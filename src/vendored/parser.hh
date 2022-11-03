/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_VENDORED_PARSER_HH_INCLUDED
# define YY_YY_SRC_VENDORED_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 18 "src/parser/generator.y"

#include "parser/requires.cc"

#line 48 "src/vendored/parser.hh"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FLOAT = 258,                   /* FLOAT  */
    INT = 259,                     /* INT  */
    ID = 260,                      /* ID  */
    PATH = 261,                    /* PATH  */
    HPATH = 262,                   /* HPATH  */
    SPATH = 263,                   /* SPATH  */
    URI = 264,                     /* URI  */
    STR = 265,                     /* STR  */
    IND_STR = 266,                 /* IND_STR  */
    AND = 267,                     /* AND  */
    OR = 268,                      /* OR  */
    ASSERT = 269,                  /* ASSERT  */
    DOLLAR_CURLY = 270,            /* DOLLAR_CURLY  */
    ELLIPSIS = 271,                /* ELLIPSIS  */
    EQ = 272,                      /* EQ  */
    NEQ = 273,                     /* NEQ  */
    IF = 274,                      /* IF  */
    THEN = 275,                    /* THEN  */
    ELSE = 276,                    /* ELSE  */
    IMPL = 277,                    /* IMPL  */
    IN = 278,                      /* IN  */
    INHERIT = 279,                 /* INHERIT  */
    IND_STRING_OPEN = 280,         /* IND_STRING_OPEN  */
    IND_STRING_CLOSE = 281,        /* IND_STRING_CLOSE  */
    LET = 282,                     /* LET  */
    OR_KW = 283,                   /* OR_KW  */
    PATH_END = 284,                /* PATH_END  */
    REC = 285,                     /* REC  */
    WITH = 286,                    /* WITH  */
    LEQ = 287,                     /* LEQ  */
    GEQ = 288,                     /* GEQ  */
    UPDATE = 289,                  /* UPDATE  */
    NOT = 290,                     /* NOT  */
    CONCAT = 291,                  /* CONCAT  */
    NEGATE = 292                   /* NEGATE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "src/parser/generator.y"

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

#line 117 "src/vendored/parser.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (void* scanner, Parsed*& parsed);

#endif /* !YY_YY_SRC_VENDORED_PARSER_HH_INCLUDED  */
