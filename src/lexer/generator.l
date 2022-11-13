/* SPDX-FileCopyrightText: 2004 Eelco Dolstra and the Nix contributors <>
 * SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

%option bison-bridge
%option bison-locations
%option ecs
%option header-file="src/vendored/lexer.hh"
%option meta-ecs
%option never-interactive
%option nodefault
%option nounput
%option noyy_top_state
%option noyywrap
%option outfile="src/vendored/lexer.cc"
%option reentrant
%option stack

%s DEFAULT
%x STRING
%x IND_STRING
%x INPATH
%x INPATH_SLASH
%x PATH_START

%{
#include "lexer/prelude.cc"
%}

ANY         .|\n
ID          [a-zA-Z\_][a-zA-Z0-9\_\'\-]*
INT         [0-9]+
FLOAT       (([1-9][0-9]*\.[0-9]*)|(0?\.[0-9]+))([Ee][+-]?[0-9]+)?
PATH_CHAR   [a-zA-Z0-9\.\_\-\+]
PATH        {PATH_CHAR}*(\/{PATH_CHAR}+)+\/?
PATH_SEG    {PATH_CHAR}*\/
HPATH       \~(\/{PATH_CHAR}+)+\/?
HPATH_START \~\/
SPATH       \<{PATH_CHAR}+(\/{PATH_CHAR}+)*\>
URI         [a-zA-Z][a-zA-Z0-9\+\-\.]*\:[a-zA-Z0-9\%\/\?\:\@\&\=\+\$\,\-\_\.\!\~\*\']+

%%

if { return IF; }
then { return THEN; }
else { return ELSE; }
assert { return ASSERT; }
with { return WITH; }
let { return LET; }
in { return IN; }
rec { return REC; }
inherit { return INHERIT; }
or { return OR_KW; }
\.\.\. { return ELLIPSIS; }

\=\= { return EQ; }
\!\= { return NEQ; }
\<\= { return LEQ; }
\>\= { return GEQ; }
\&\& { return AND; }
\|\| { return OR; }
\-\> { return IMPL; }
\/\/ { return UPDATE; }
\+\+ { return CONCAT; }

{ID} {
  yylval->string = Str_new(yytext, yyleng);
  return ID;
}

{INT} {
  yylval->integer = new Integer{
    .value = Str_new(yytext, yyleng),
    .span = SPAN,
  };

  return INT;
}

{FLOAT} {
  yylval->float_ = new Float{
    .value = Str_new(yytext, yyleng),
    .span = SPAN,
  };

  return FLOAT;
}

\$\{ {
  PUSH_STATE(DEFAULT);
  return DOLLAR_CURLY;
}

\} {
  if (YYSTATE != INITIAL) POP_STATE();
  return '}';
}

\{ {
  PUSH_STATE(DEFAULT);
  return '{';
}

\" {
  PUSH_STATE(STRING);
  return '"';
}

<STRING>([^\$\"\\]|\$[^\{\"\\]|\\{ANY}|\$\\{ANY})*\$/\" |
<STRING>([^\$\"\\]|\$[^\{\"\\]|\\{ANY}|\$\\{ANY})+ {
  yylval->util_string = new UtilString{
    .content = Str_new(yytext, yyleng),
    .should_unescape = true,
  };
  return STR;
}

<STRING>\$\{ {
  PUSH_STATE(DEFAULT);
  return DOLLAR_CURLY;
}

<STRING>\" {
  POP_STATE();
  return '"';
}

<STRING>\$|\\|\$\\ {
  return EOF;
}

\'\'(\ *\n)? {
  PUSH_STATE(IND_STRING);
  return IND_STRING_OPEN;
}

<IND_STRING>([^\$\']|\$[^\{\']|\'[^\'\$])+ {
  yylval->util_string = new UtilString{
    .content = Str_new(yytext, yyleng),
    .should_unescape = false,
  };
  return IND_STR;
}

<IND_STRING>\'\'\$ |
<IND_STRING>\$ {
  yylval->util_string = new UtilString{
    .content = Str_clone("$", 1),
    .should_unescape = false,
  };
  return IND_STR;
}

<IND_STRING>\'\'\' {
  yylval->util_string = new UtilString{
    .content = Str_clone("''", 2),
    .should_unescape = false,
  };
  return IND_STR;
}

<IND_STRING>\'\'\\{ANY} {
  yylval->util_string = new UtilString{
    .content = Str_new(yytext + 2, yyleng - 2),
    .should_unescape = true,
  };
  return IND_STR;
}

<IND_STRING>\$\{ {
  PUSH_STATE(DEFAULT);
  return DOLLAR_CURLY;
}

<IND_STRING>\'\' {
  POP_STATE();
  return IND_STRING_CLOSE;
}

<IND_STRING>\' {
  yylval->util_string = new UtilString{
    .content = Str_clone("'", 1),
    .should_unescape = false,
  };
  return IND_STR;
}

{PATH_SEG}\$\{ |
{HPATH_START}\$\{ {
  PUSH_STATE(PATH_START);
  yyless(0);
  *yylloc = prev_yylloc;
}

<PATH_START>{PATH_SEG} {
  POP_STATE();
  PUSH_STATE(INPATH_SLASH);
  yylval->string = Str_new(yytext, yyleng);
  return PATH;
}

<PATH_START>{HPATH_START} {
  POP_STATE();
  PUSH_STATE(INPATH_SLASH);
  yylval->string = Str_new(yytext, yyleng);
  return HPATH;
}

{PATH} {
  if (yytext[yyleng - 1] == '/')
    PUSH_STATE(INPATH_SLASH);
  else
    PUSH_STATE(INPATH);
  yylval->string = Str_new(yytext, yyleng);
  return PATH;
}

{HPATH} {
  if (yytext[yyleng - 1] == '/')
    PUSH_STATE(INPATH_SLASH);
  else
    PUSH_STATE(INPATH);
  yylval->string = Str_new(yytext, yyleng);
  return HPATH;
}

<INPATH,INPATH_SLASH>\$\{ {
  POP_STATE();
  PUSH_STATE(INPATH);
  PUSH_STATE(DEFAULT);
  return DOLLAR_CURLY;
}

<INPATH,INPATH_SLASH>{PATH}|{PATH_SEG}|{PATH_CHAR}+ {
  POP_STATE();
  if (yytext[yyleng-1] == '/')
    PUSH_STATE(INPATH_SLASH);
  else
    PUSH_STATE(INPATH);
  yylval->util_string = new UtilString{
    .content = Str_new(yytext, yyleng),
    .should_unescape = false,
  };
  return STR;
}

<INPATH>{ANY} |
<INPATH><<EOF>> {
  POP_STATE();
  yyless(0);
  *yylloc = prev_yylloc;
  return PATH_END;
}

<INPATH_SLASH>{ANY} |
<INPATH_SLASH><<EOF>> {
  throw new Error{
    .message = Str_clone("Path has a trailing slash"),
    .span = SPAN,
  };
}

{SPATH} {
  yylval->string = Str_new(yytext, yyleng);
  return SPATH;
}

{URI} {
  yylval->string = Str_new(yytext, yyleng);
  return URI;
}

[ \t\r\n]+ {
  LL_insert(parsed->trivia, new Trivia {
    .kind = TriviaKind::TriviaKindWhitespace,
    .ptr = Str_new(yytext, yyleng),
    .span = SPAN,
  });
}
\#[^\r\n]* {
  LL_insert(parsed->trivia, new Trivia {
    .kind = TriviaKind::TriviaKindComment,
    .ptr = Str_new(yytext, yyleng),
    .span = SPAN,
  });
}
\/\*([^*]|\*+[^*/])*\*+\/ {
  LL_insert(parsed->trivia, new Trivia {
    .kind = TriviaKind::TriviaKindMultilineComment,
    .ptr = Str_new(yytext, yyleng),
    .span = SPAN,
  });
}

{ANY} {
  return (unsigned char) yytext[0];
}

%%
