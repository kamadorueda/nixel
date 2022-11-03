// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#define SPAN \
  new Span { \
    .start = \
      new Position{ \
        .line = (size_t)yylocp->first_line, \
        .column = (size_t)yylocp->first_column, \
      }, \
    .end = new Position{ \
      .line = (size_t)yylocp->last_line, \
      .column = (size_t)yylocp->last_column, \
    }, \
  }

#define _(Kind, Ptr) \
  Expression* to_expr(Ptr* ptr) { \
    return new Expression{.kind = Kind, .ptr = (size_t*)ptr}; \
  }

_(ExpressionKind::ExpressionKindAssert, Assert)
_(ExpressionKind::ExpressionKindBinaryOperation, BinaryOperation)
_(ExpressionKind::ExpressionKindError, Error)
_(ExpressionKind::ExpressionKindFloat, Float)
_(ExpressionKind::ExpressionKindFunction, Function)
_(ExpressionKind::ExpressionKindFunctionApplication, FunctionApplication)
_(ExpressionKind::ExpressionKindHasAttribute, HasAttribute)
_(ExpressionKind::ExpressionKindIdentifier, Identifier)
_(ExpressionKind::ExpressionKindIfThenElse, IfThenElse)
_(ExpressionKind::ExpressionKindIndentedString, IndentedString)
_(ExpressionKind::ExpressionKindInteger, Integer)
_(ExpressionKind::ExpressionKindLetIn, LetIn)
_(ExpressionKind::ExpressionKindList, List)
_(ExpressionKind::ExpressionKindMap, Map)
_(ExpressionKind::ExpressionKindPath, Path)
_(ExpressionKind::ExpressionKindPropertyAccess, PropertyAccess)
_(ExpressionKind::ExpressionKindSearchNixPath, SearchNixPath)
_(ExpressionKind::ExpressionKindString_, String_)
_(ExpressionKind::ExpressionKindUnaryOperation, UnaryOperation)
_(ExpressionKind::ExpressionKindUri, Uri)
_(ExpressionKind::ExpressionKindWith, With)

#undef _

void yyerror(
  YYLTYPE* yylocp,
  yyscan_t scanner,
  Parsed*& parsed,
  const char* message
) {
  delete parsed->expression;
  parsed->expression = to_expr(new Error{
    .message = Str_new(message),
    .span = SPAN,
  });
};
