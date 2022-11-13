// SPDX-FileCopyrightText: 2004 Eelco Dolstra and the Nix contributors <>
// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

%define api.pure true
%define lr.type canonical-lr
%define parse.error verbose
%glr-parser
%header "src/vendored/parser.hh"
%lex-param { void* scanner }
%lex-param { Parsed*& parsed }
%locations
%output "src/vendored/parser.cc"
%parse-param { void* scanner }
%parse-param { Parsed*& parsed }

%code requires {
#include "parser/requires.cc"
}

%{
#include "vendored/parser.hh"
#include "vendored/lexer.hh"

YY_DECL;

#include "parser/prelude.cc"
%}

%destructor { delete $$; } <*>

%union {
  Expression* expression;
  Float* float_;
  Integer* integer;
  FunctionHeadDestructured* function_head_destructured;
  FunctionHeadDestructuredArgument* function_head_destructured_argument;
  Part* part;
  Path* path;
  Str* string;
  UtilString* util_string;
  LL* bindings;
  LL* expressions;
  LL* parts;
}

%type <bindings> binds
%type <expression> expr expr_app expr_function expr_if expr_op expr_select expr_simple
%type <expressions> expr_list
%type <function_head_destructured> formals
%type <function_head_destructured_argument> formal
%type <part> attr string_attr
%type <parts> attrs attrpath ind_string_parts string_parts string_parts_interpolated
%type <path> path_start

%token <float_> FLOAT
%token <integer> INT
%token <string> ID PATH HPATH SPATH URI
%token <util_string> STR IND_STR

%token AND OR
%token ASSERT
%token DOLLAR_CURLY
%token ELLIPSIS
%token EQ NEQ
%token IF THEN ELSE
%token IMPL
%token IN
%token INHERIT
%token IND_STRING_OPEN IND_STRING_CLOSE
%token LET
%token OR_KW
%token PATH_END
%token REC
%token WITH

%right IMPL
%left OR
%left AND
%nonassoc EQ NEQ
%nonassoc '<' '>' LEQ GEQ
%right UPDATE
%left NOT
%left '+' '-'
%left '*' '/'
%right CONCAT
%nonassoc '?'
%nonassoc NEGATE

%%

start
  : expr {
    parsed->expression = $1;
  }
  ;

expr
  : expr_function {
    $$ = $1;
  }
  ;

expr_function
  : ID ':' expr_function {
    $$ = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindSimple,
      .head_ptr = (any*) new FunctionHeadSimple{
        .identifier=$1,
      },
      .body = $3,
      .span = SPAN,
    });
  }
  | '{' formals '}' ':' expr_function {
    $$ = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindDestructured,
      .head_ptr = (any*) $2,
      .body = $5,
      .span = SPAN,
    });
  }
  | '{' formals '}' '@' ID ':' expr_function {
    $2->identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierRightAt;
    $2->identifier_ptr = $5;
    $$ = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindDestructured,
      .head_ptr = (any*) $2,
      .body = $7,
      .span = SPAN,
    });
  }
  | ID '@' '{' formals '}' ':' expr_function {
    $4->identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierLeftAt;
    $4->identifier_ptr = $1;
    $$ = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindDestructured,
      .head_ptr = (any*) $4,
      .body = $7,
      .span = SPAN,
    });
  }
  | ASSERT expr ';' expr_function {
    $$ = to_expr(new Assert{
      .expression = $2,
      .target = $4,
      .span = SPAN,
    });
  }
  | WITH expr ';' expr_function {
    $$ = to_expr(new With{
      .expression = $2,
      .target = $4,
      .span = SPAN,
    });
  }
  | LET binds IN expr_function {
    $$ = to_expr(new LetIn{
      .bindings = $2,
      .target = $4,
      .span = SPAN,
    });
  }
  | expr_if {
    $$ = $1;
  }
  ;

expr_if
  : IF expr THEN expr ELSE expr {
    $$ = to_expr(new IfThenElse{
      .predicate = $2,
      .then = $4,
      .else_ = $6,
      .span = SPAN,
    });
  }
  | expr_op {
    $$ = $1;
  }
  ;

expr_op
  : '!' expr_op %prec NOT {
    $$ = to_expr(new UnaryOperation{
      .operator_ = UnaryOperator::UnaryOperatorNot,
      .operand = $2,
      .span = SPAN,
    });
  }
  | '-' expr_op %prec NEGATE {
    $$ = to_expr(new UnaryOperation{
      .operator_ = UnaryOperator::UnaryOperatorNegate,
      .operand = $2,
      .span = SPAN,
    });
  }
  | expr_op EQ expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorEqualTo,
      .right = $3,
    });
  }
  | expr_op NEQ expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorNotEqualTo,
      .right = $3,
    });
  }
  | expr_op '<' expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorLessThan,
      .right = $3,
    });
  }
  | expr_op LEQ expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorLessThanOrEqualTo,
      .right = $3,
    });
  }
  | expr_op '>' expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorGreaterThan,
      .right = $3,
    });
  }
  | expr_op GEQ expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorGreaterThanOrEqualTo,
      .right = $3,
    });
  }
  | expr_op AND expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorLogicalAnd,
      .right = $3,
    });
  }
  | expr_op OR expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorLogicalOr,
      .right = $3,
    });
  }
  | expr_op IMPL expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorImplication,
      .right = $3,
    });
  }
  | expr_op UPDATE expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorUpdate,
      .right = $3,
    });
  }
  | expr_op '?' attrpath {
    $$ = to_expr(new HasAttribute{
      .expression = $1,
      .attribute_path = $3,
    });
  }
  | expr_op '+' expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorAddition,
      .right = $3,
    });
  }
  | expr_op '-' expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorSubtraction,
      .right = $3,
    });
  }
  | expr_op '*' expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorMultiplication,
      .right = $3,
    });
  }
  | expr_op '/' expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorDivision,
      .right = $3,
    });
  }
  | expr_op CONCAT expr_op {
    $$ = to_expr(new BinaryOperation{
      .left = $1,
      .operator_ = BinaryOperator::BinaryOperatorConcatenation,
      .right = $3,
    });
  }
  | expr_app {
    $$ = $1;
  }
  ;

expr_app
  : expr_app expr_select {
    if ($1->kind == ExpressionKind::ExpressionKindFunctionApplication) {
      $$ = $1;
    } else {
      $$ = to_expr(new FunctionApplication{
        .function = $1,
        .arguments = LL_new(),
      });
    }

    LL_insert(((FunctionApplication*) $$->ptr)->arguments, $2);
  }
  | expr_select {
    $$ = $1;
  }
  ;

expr_select
  : expr_simple '.' attrpath {
    $$ = to_expr(new PropertyAccess {
      .expression = $1,
      .attribute_path = $3,
      .default_ = nullptr,
    });
  }
  | expr_simple '.' attrpath OR_KW expr_select {
    $$ = to_expr(new PropertyAccess {
      .expression = $1,
      .attribute_path = $3,
      .default_ = $5,
    });
  }
  | expr_simple OR_KW {
    $$ = to_expr(new FunctionApplication{
      .function = $1,
      .arguments = LL_new(),
    });

    LL_insert(((FunctionApplication*) $$->ptr)->arguments, to_expr(new Identifier{
      .id = Str_clone("or", 2),
      .span = SPAN,
    }));
    TRIVIA_BOUNDARY;
  }
  | expr_simple {
    $$ = $1;
  }
  ;

expr_simple
  : FLOAT {
    $$ = to_expr($1);
    TRIVIA_BOUNDARY;
  }
  | ID {
    $$ = to_expr(new Identifier{
      .id = $1,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  | INT {
    $$ = to_expr($1);
    TRIVIA_BOUNDARY;
  }
  | '"' string_parts '"' {
    $$ = to_expr(new String_{
      .parts = $2,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  | IND_STRING_OPEN ind_string_parts IND_STRING_CLOSE {
    $$ = to_expr(new IndentedString{
      .parts = $2,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  | path_start PATH_END {
    $$ = to_expr($1);
    TRIVIA_BOUNDARY;
  }
  | path_start string_parts_interpolated PATH_END {
    // TODO
    // std::copy($2->begin(), $2->end(), std::back_inserter(*($1->parts)));
    delete $2;
    $$ = to_expr($1);
    TRIVIA_BOUNDARY;
  }
  | URI {
    $$ = to_expr(new Uri{
      .uri = $1,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  | SPATH {
    $$ = to_expr(new SearchNixPath{
      .path = $1,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  | '(' expr ')' {
    $$ = $2;
    TRIVIA_BOUNDARY;
  }
  | REC '{' binds '}' {
    $$ = to_expr(new Map{
      .recursive = true,
      .bindings = $3,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  | '{' binds '}' {
    $$ = to_expr(new Map{
      .recursive = false,
      .bindings = $2,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  | '[' expr_list ']' {
    $$ = to_expr(new List{
      .elements = $2,
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
  ;

string_parts
  : STR {
    $$ = LL_new();
    LL_insert($$, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = $1,
        .span = SPAN,
      },
    });
    TRIVIA_BOUNDARY;
  }
  | string_parts_interpolated {
    $$ = $1;
  }
  | {
    $$ = LL_new();
    TRIVIA_BOUNDARY;
  }
  ;

string_parts_interpolated
  : string_parts_interpolated STR {
    LL_insert($1, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = $2,
        .span = SPAN,
      },
    });
    $$ = $1;
    TRIVIA_BOUNDARY;
  }
  | string_parts_interpolated DOLLAR_CURLY expr '}' {
    LL_insert($1, new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) $3,
    });
    $$ = $1;
    TRIVIA_BOUNDARY;
  }
  | DOLLAR_CURLY expr '}' {
    $$ = LL_new();
    LL_insert($$, new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) $2,
    });
    TRIVIA_BOUNDARY;
  }
  | STR DOLLAR_CURLY expr '}' {
    $$ = LL_new();
    LL_insert($$, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = $1,
        .span = SPAN,
      },
    });
    LL_insert($$, new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) $3,
    });
    TRIVIA_BOUNDARY;
  }
  ;

path_start
  : PATH {
    $$ = new Path{
      .parts = LL_new(),
      .span = SPAN,
    };
    LL_insert($$->parts, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = $1,
          .should_unescape = false,
        },
        .span = SPAN,
      },
    });
    TRIVIA_BOUNDARY;
  }
  | HPATH {
    $$ = new Path{
      .parts = LL_new(),
      .span = SPAN,
    };
    LL_insert($$->parts, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = $1,
          .should_unescape = false,
        },
        .span = SPAN,
      },
    });
    TRIVIA_BOUNDARY;
  }
  ;

ind_string_parts
  : ind_string_parts IND_STR {
    LL_insert($1, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = $2,
        .span = SPAN,
      },
    });
    $$ = $1;
    TRIVIA_BOUNDARY;
  }
  | ind_string_parts DOLLAR_CURLY expr '}' {
    LL_insert($1, new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) $3,
    });
    $$ = $1;
    TRIVIA_BOUNDARY;
  }
  | {
    $$ = LL_new();
    TRIVIA_BOUNDARY;
  }
  ;

binds
  : binds attrpath '=' expr ';' {
    LL_insert($1, new Binding{
      .kind = BindingKind::BindingKindBinding,
      .ptr = (any*) new BindingKeyValue{
        .from = $2,
        .to = $4,
      },
    });
    $$ = $1;
    TRIVIA_BOUNDARY;
  }
  | binds INHERIT attrs ';' {
    LL_insert($1, new Binding{
      .kind = BindingKind::BindingKindInherit,
      .ptr = (any*) new BindingInherit{
        .from = nullptr,
        .attributes = $3,
        .span = SPAN,
      },
    });
    $$ = $1;
    TRIVIA_BOUNDARY;
  }
  | binds INHERIT '(' expr ')' attrs ';' {
    LL_insert($1, new Binding{
      .kind = BindingKind::BindingKindInherit,
      .ptr = (any*) new BindingInherit{
        .from = $4,
        .attributes = $6,
        .span = SPAN,
      },
    });
    $$ = $1;
    TRIVIA_BOUNDARY;
  }
  | {
    $$ = LL_new();
    TRIVIA_BOUNDARY;
  }
  ;

attrs
  : attrs attr {
    LL_insert($1, $2);
    $$ = $1;
  }
  | attrs string_attr {
    LL_insert($1, $2);
    $$ = $1;
  }
  | {
    $$ = LL_new();
    TRIVIA_BOUNDARY;
  }
  ;

attrpath
  : attrpath '.' attr {
    LL_insert($1, $3);
    $$ = $1;
  }
  | attrpath '.' string_attr {
    LL_insert($1, $3);
    $$ = $1;
  }
  | attr {
    $$ = LL_new();
    LL_insert($$, $1);
  }
  | string_attr {
    $$ = LL_new();
    LL_insert($$, $1);
  }
  ;

attr
  : ID {
    $$ = new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = $1,
          .should_unescape = false,
        },
        .span = SPAN,
      },
    };
    TRIVIA_BOUNDARY;
  }
  | OR_KW {
    $$ = new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = Str_clone("or", 2),
          .should_unescape = false,
        },
        .span = SPAN,
      },
    };
    TRIVIA_BOUNDARY;
  }
  ;

string_attr
  : '"' string_parts '"' {
    $$ = new Part{
      .kind = PartKind::PartKindExpression,
      .ptr = (any*) to_expr(new String_{
        .parts = $2,
        .span = SPAN,
      }),
    };
    TRIVIA_BOUNDARY;
  }
  | DOLLAR_CURLY expr '}' {
    $$ = new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) $2,
    };
    TRIVIA_BOUNDARY;
  }
  ;

expr_list
  : expr_list expr_select {
    LL_insert($1, $2);
    $$ = $1;
  }
  | {
    $$ = LL_new();
    TRIVIA_BOUNDARY;
  }
  ;

formals
  : formal ',' formals {
    $$ = $3;
    LL_insert($$->arguments, $1);
  }
  | formal {
    $$ = new FunctionHeadDestructured{
      .ellipsis = false,
      .identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierNone,
      .identifier_ptr = nullptr,
      .arguments = LL_new(),
    };
    LL_insert($$->arguments, $1);
  }
  | {
    $$ = new FunctionHeadDestructured{
      .ellipsis = false,
      .identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierNone,
      .identifier_ptr = nullptr,
      .arguments = LL_new(),
    };
    TRIVIA_BOUNDARY;
  }
  | ELLIPSIS {
    $$ = new FunctionHeadDestructured{
      .ellipsis = true,
      .identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierNone,
      .identifier_ptr = nullptr,
      .arguments = LL_new(),
    };
    TRIVIA_BOUNDARY;
  }
  ;

formal
  : ID {
    $$ = new FunctionHeadDestructuredArgument{
      .identifier = $1,
      .default_ = nullptr,
    };
    TRIVIA_BOUNDARY;
  }
  | ID '?' expr {
    $$ = new FunctionHeadDestructuredArgument{
      .identifier = $1,
      .default_ = $3,
    };
  }
  ;

%%

#include "parser/parse.cc"
