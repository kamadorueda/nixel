/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1






/* First part of user prologue.  */
#line 22 "src/parser/generator.y"

#include "vendored/parser.hh"
#include "vendored/lexer.hh"

YY_DECL;

#include "parser/prelude.cc"

#line 67 "src/vendored/parser.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hh"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FLOAT = 3,                      /* FLOAT  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_PATH = 6,                       /* PATH  */
  YYSYMBOL_HPATH = 7,                      /* HPATH  */
  YYSYMBOL_SPATH = 8,                      /* SPATH  */
  YYSYMBOL_URI = 9,                        /* URI  */
  YYSYMBOL_STR = 10,                       /* STR  */
  YYSYMBOL_IND_STR = 11,                   /* IND_STR  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_ASSERT = 14,                    /* ASSERT  */
  YYSYMBOL_DOLLAR_CURLY = 15,              /* DOLLAR_CURLY  */
  YYSYMBOL_ELLIPSIS = 16,                  /* ELLIPSIS  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_NEQ = 18,                       /* NEQ  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_THEN = 20,                      /* THEN  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_IMPL = 22,                      /* IMPL  */
  YYSYMBOL_IN = 23,                        /* IN  */
  YYSYMBOL_INHERIT = 24,                   /* INHERIT  */
  YYSYMBOL_IND_STRING_OPEN = 25,           /* IND_STRING_OPEN  */
  YYSYMBOL_IND_STRING_CLOSE = 26,          /* IND_STRING_CLOSE  */
  YYSYMBOL_LET = 27,                       /* LET  */
  YYSYMBOL_OR_KW = 28,                     /* OR_KW  */
  YYSYMBOL_PATH_END = 29,                  /* PATH_END  */
  YYSYMBOL_REC = 30,                       /* REC  */
  YYSYMBOL_WITH = 31,                      /* WITH  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_LEQ = 34,                       /* LEQ  */
  YYSYMBOL_GEQ = 35,                       /* GEQ  */
  YYSYMBOL_UPDATE = 36,                    /* UPDATE  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_CONCAT = 42,                    /* CONCAT  */
  YYSYMBOL_43_ = 43,                       /* '?'  */
  YYSYMBOL_NEGATE = 44,                    /* NEGATE  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* '@'  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* '!'  */
  YYSYMBOL_51_ = 51,                       /* '.'  */
  YYSYMBOL_52_ = 52,                       /* '"'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_start = 60,                     /* start  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_expr_function = 62,             /* expr_function  */
  YYSYMBOL_expr_if = 63,                   /* expr_if  */
  YYSYMBOL_expr_op = 64,                   /* expr_op  */
  YYSYMBOL_expr_app = 65,                  /* expr_app  */
  YYSYMBOL_expr_select = 66,               /* expr_select  */
  YYSYMBOL_expr_simple = 67,               /* expr_simple  */
  YYSYMBOL_string_parts = 68,              /* string_parts  */
  YYSYMBOL_string_parts_interpolated = 69, /* string_parts_interpolated  */
  YYSYMBOL_path_start = 70,                /* path_start  */
  YYSYMBOL_ind_string_parts = 71,          /* ind_string_parts  */
  YYSYMBOL_binds = 72,                     /* binds  */
  YYSYMBOL_attrs = 73,                     /* attrs  */
  YYSYMBOL_attrpath = 74,                  /* attrpath  */
  YYSYMBOL_attr = 75,                      /* attr  */
  YYSYMBOL_string_attr = 76,               /* string_attr  */
  YYSYMBOL_expr_list = 77,                 /* expr_list  */
  YYSYMBOL_formals = 78,                   /* formals  */
  YYSYMBOL_formal = 79                     /* formal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   21708

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1101
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    52,     2,     2,     2,     2,     2,
      53,    54,    40,    38,    58,    39,    51,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    49,
      32,    57,    33,    43,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    34,    35,    36,
      37,    42,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,   100,   106,   116,   124,   134,   144,   151,
     158,   165,   171,   179,   185,   192,   199,   206,   213,   220,
     227,   234,   241,   248,   255,   262,   269,   275,   282,   289,
     296,   303,   310,   316,   328,   334,   341,   348,   360,   366,
     370,   377,   381,   388,   395,   399,   406,   413,   420,   424,
     432,   440,   450,   461,   464,   471,   482,   490,   498,   516,
     533,   553,   564,   572,   579,   590,   602,   614,   621,   625,
     629,   636,   640,   644,   648,   655,   668,   684,   694,   704,
     708,   715,   719,   728,   737,   749,   756
};
#endif

#define YYPACT_NINF (-174)
#define YYTABLE_NINF (-87)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4888,  5279,  5931,  2568,     5,   111,  6768,  6822,  4973,  5033,
      11,    16,   -44,  4973,  1840,   271,  1840,    -4,  5130,   860,
       3,    10,    23,    24, 17125,  8013,  8067,  6876,   188,  4888,
     -13,    -2,    54,   171,   139,   215,    45,  6930,   215, 17162,
     206,    51,   242,    68,   -28, 17199,    70,  5446,    65,    -3,
      64,  3929,  -174,  1840,  1840,  1840,  1840,  1840,  1840,  1840,
    1840,  1840,  1840,  1840,  1840,  1840,  1840,  1840,   159,  8121,
    8175,   506,   119,  6984,   262,   136,    22,  4888,  5507,   195,
    5446,  7038,    81,  5446,  4888,    67,    95,    -4,   184,   295,
     342,   472,  4888,  5636,  7092,    41,    22,  5446,   101,  7146,
      73,  5446,  7200,  7254,  4002, 17236, 17273,  2677,  3649, 17310,
    4000,  4504,  5233,  5846, 17347, 17384, 17421, 17458, 17495, 17532,
   16145,  7308,  7362,   142,   166,   198,   180,   197,   261,  5130,
     144,   190,   632,  4973,  7416,   275,   -15,  4888,   266,   245,
     253,    87,   254,   105,   243,  4888,   270,   371,   251,   503,
     164,   241,   373,   380,   381,   260,   322,   285,    90,   163,
    8229,  4888,   347,   301,   667,  4888,   364,  1038,   384,   721,
    8547,  8600,  8282,  8653,  8706,  4973,  5033,    11,    16,   296,
    4973,  1848,   309,  1848,    -4,  5130,   860,   341,   343, 19619,
   14642, 14695,  8759,   330,  8812,  8865,  8335,  8918,  8971,  4973,
    5033,    11,    16,   375,  4973,  4625,   455,  4625,    -4,  5130,
     860,   415,   439, 20672, 14748, 14801,  9024,   333,  9077,  9130,
    8388,  9183,  9236,  4973,  5033,    11,    16,   416,  4973,  5689,
     458,  5689,    -4,  5130,   860,   413,   418, 17879, 14854, 14907,
    9289,   480,  5446,    75,   440,  9342,  9395,  8441,  9448,  9501,
    4973,  5033,    11,    16,   446,  4973,  5784,   766,  5784,    -4,
    5130,   860,   468,   473, 20136, 14960, 15013,  9554,   484,   610,
     618,   672,   705,   759,    11,   479,   215,    -4,  5130,   860,
     771,   507, 16182,  5446, 16219,    -4, 16256, 16293,  7470,  5446,
    7524,    -4,  7578,  7632,  5446,   691,  5446,  9607,  9660,  8494,
    9713,  9766,  4973,  5033,    11,    16,   482,  4973, 15967,   881,
   15967,    -4,  5130,   860,   512,   516, 20704, 15066, 15119,  9819,
     740,  1447,  2419,  1698,  2640,  2721,  4973,  5033,    11,    16,
     510,  4973, 15975,   906, 15975,    -4,  5130,   860,   -12,    29,
    2861,  1599,  2795,  3540,   778,   159,   506,  1307,  5446,  1615,
      -4,  4973,   518,   520,   546,   376,   847,   215,   522,  9872,
     215, 19652,   899,   525, 19685,   523,   539,  4072,  1848,  1848,
    1848,  1848,  1848,  1848,  1848,  1848,  1848,  1848,  1848,  1848,
    1848,  1848,  1848,   942, 15172, 15225,   990,  9925,   810,  5033,
     551,   545,   582,   414,   937,   215,   554,  9978,   215, 20736,
     951,   557, 20768,   576,   575,  4126,  4625,  4625,  4625,  4625,
    4625,  4625,  4625,  4625,  4625,  4625,  4625,  4625,  4625,  4625,
    4625,  1054, 15278, 15331,  1130, 10031,   872,  5130,   584,   583,
     611,   454,   968,   215,   587, 10084,   215, 17912,  1056,   586,
   17945,   589,   580,  4196,  5689,  5689,  5689,  5689,  5689,  5689,
    5689,  5689,  5689,  5689,  5689,  5689,  5689,  5689,  5689,  1242,
   15384, 15437,  1257, 10137,   879,   592,  5130,  1714,  4973,  5446,
     599,   603,   634,   478,  1097,   215,   608, 10190,   215, 20168,
    1099,   612, 20200,   606,   613,  4320,  5784,  5784,  5784,  5784,
    5784,  5784,  5784,  5784,  5784,  5784,  5784,  5784,  5784,  5784,
    5784,  1561, 15490, 15543,  1566, 10243,   916,   548,   215,  1202,
     616,   629,  4454,  4614,  1656,   828,   953,   639,   636,   642,
     647,   656,   657,  5507,   659,   658,   695,   585,  1169,   215,
     668, 10296,   215, 20800,  1209,   669, 20832,   670,   675,  4706,
   15967, 15967, 15967, 15967, 15967, 15967, 15967, 15967, 15967, 15967,
   15967, 15967, 15967, 15967, 15967,  1807, 15596, 15649,  1902, 10349,
     992,  5636,   685,   688,   701,   594,  1243,   215,   689,  3612,
     215,  4127,  1231,   693, 16761,   690,   692,  4760, 15975, 15975,
   15975, 15975, 15975, 15975, 15975, 15975, 15975, 15975, 15975, 15975,
   15975, 15975, 15975,  1960,  4553,  7901,  2026,  3693,  1031, 16330,
   16367,  7686,  7740,   696,   700,   698,    22,  4973,  5507, 10402,
    4973,  1310,  4973, 10455,   108, 10508, 10561, 10614, 19718, 19751,
   20014, 20046, 19784,  3030, 20079, 20091, 20124, 19817, 19850, 19883,
   19916, 19949, 19982, 18440,  5446, 18475,    -4, 18510, 18545, 18580,
   10667,  5446, 10720,    -4, 10773, 10826, 10879, 10932,   728,    22,
    5033,  5507, 10985,  5033,  1562,  5033, 11038,   189, 11091, 11144,
   11197, 20864, 20896,  3885, 21440, 20928, 21536, 21547, 21579, 21590,
   20960, 20992, 21024, 21056, 21088, 21120, 18615,  5446, 18647,    -4,
   18679, 18711, 18743, 11250,  5446, 11303,    -4, 11356, 11409, 11462,
   11515,   716,    22,  5130,  5507, 11568,  5130,  1563,  5130, 11621,
     235, 11674, 11727, 11780, 17978, 18011, 18275, 18308, 18044,  5334,
   18341, 18374, 18407, 18077, 18110, 18143, 18176, 18209, 18242, 17564,
    5446, 17599,    -4, 17634, 17669, 17704, 11833,  5446, 11886,    -4,
   11939, 11992, 12045, 12098,  1052,   729,  1645,   710,   707,    22,
    5446,  5507, 12151,  5446,  1648,  5446, 12204,   355, 12257, 12310,
   12363, 20232, 20264, 20520, 20552, 20296, 20584, 20596, 20628, 20640,
   20328, 20360, 20392, 20424, 20456, 20488, 18775,  5446, 18807,    -4,
   18839, 18871, 18903, 12416,  5446, 12469,    -4, 12522, 12575, 12628,
   12681,  1088,  1670,  1160,  1235,  1778,  1786,  1915,  5446,  2060,
      -4,  2132,  2536,  2859,  3032, 16404, 16441,  7794,  7848,  1109,
    1121,   764,    22,  5507,  5507, 12734,  5507,  1749,  5507, 12787,
     453, 12840, 12893, 12946, 21152, 21184, 21472, 21504, 21216,  2925,
   21622, 21633, 21665, 21248, 21280, 21312, 21344, 21376, 21408, 18935,
    5446, 18967,    -4, 18999, 19031, 19063, 12999,  5446, 13052,    -4,
   13105, 13158, 13211, 13264,    49,    22,  5636,  5507,  3766,  5636,
    1927,  5636,  3830,   517,  4352,  5386,  6008, 16793, 16825,  3157,
    6553, 16857,  2201,  4761, 17081, 17093, 16889, 16921, 16953, 16985,
   17017, 17049, 16473,  5446, 16505,    -4, 16537, 16569, 16601,  6064,
    5446,  6120,    -4,  6185,  6267,  6344,  6407,  1720,  1857,   739,
     742,   777,   743, 13317,   751,  4973,   804,   769,   767,   942,
     774,   776,  5185,   990,   782,   821,   809,   822, 13370,   823,
    5033,   839,   801,   798,  1054,   807,   803,  5354,  1130,   812,
     806,   836,   818, 13423,   824,  5130,   856,   829,   841,  1242,
     844,   846,  5702,  1257,   301,  2028,   853,   871,   898,   888,
   13476,   889,  5446,   932,   891,   887,  1561,   894,   896, 16028,
    1566,  3102,   903,   912, 16036,  1656,   920,   922,   950,   955,
   13529,   957,  5507,   969,   946,   952,  1807,   959,   956, 16089,
    1902,   962,   221,   989,   226,  6463,   291,  5636,  1006,   965,
     963,  1960,   967,   964, 16097,  2026,   974,  4973,   973,   979,
   19095, 19130, 19165, 19200, 13582, 13635, 15702, 13688, 13741,   995,
    5033,   997,   999, 19235, 19267, 19299, 19331, 13794, 13847, 15755,
   13900, 13953,  1002,  5130,   994,  1007, 17739, 17774, 17809, 17844,
   14006, 14059, 15808, 14112, 14165,  2010,  1009,  5446,  1004,  1010,
   19363, 19395, 19427, 19459, 14218, 14271, 15861, 14324, 14377,  3156,
    3226,  4832,  3392,  3484,  1012,  5507,  1042,  1023, 19491, 19523,
   19555, 19587, 14430, 14483, 15914, 14536, 14589,  1029,  5636,   297,
    1032, 16633, 16665, 16697, 16729,  6521,  6600,  7957,  6656,  6712,
    4973,  1030,  4973,  5033,  1069,  5033,  5130,  1044,  5130,  2046,
    5446,  1053,  5446,  5507,  1078,  5507,  5636,   307,  5636,  1058,
    1061,  1091,  1102,  1072,  1074,  1082,  1083,  1111,  1133,   336,
     339
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,  5571,  4520,  4917,  2916,  3886,     0,   972,   -37,
     -23,  1944,  -173,     6,  -162,     2,   -26,  1303,  -111,    -5,
    -174
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,   262,   263,   264,   265,   266,   267,    48,
      49,   268,    33,    42,   130,   244,    89,    90,    51,    43,
      44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   167,    35,    52,   355,    74,    46,   100,   191,   215,
      -2,    47,   101,   191,    26,   -59,    26,    34,   239,   -82,
     -59,   -67,   -63,    -3,   -11,    69,   -63,    40,   393,    26,
      96,   -67,   -86,    76,   -59,    -3,    88,   -63,    41,   -67,
     -67,    91,   286,   -86,   -67,   292,    -3,    77,   -54,   -53,
     131,   104,   431,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,   -67,   -83,
     120,   123,   -70,   121,    78,   367,   -11,    26,   318,   473,
     -70,   467,   -70,   -55,    26,    97,   137,   -11,   -55,   138,
     -70,   139,    26,   342,    92,   -70,    -4,   -57,   -84,   405,
     -58,   507,   -57,   -70,   150,   -58,   153,    -4,     1,     2,
      37,     4,     5,     6,     7,    95,   -70,    99,   102,   -70,
     129,   -60,   -52,   443,   -70,   -55,   -60,   -70,   466,   239,
      10,   527,   -75,   191,   294,    12,    -4,    26,   -75,   -57,
     -60,   150,   -58,   160,    82,    26,   -76,   365,   141,   347,
     485,    38,   -76,   895,    83,   565,   896,    17,    18,   348,
      19,    26,    84,    85,   282,    26,    -8,    86,   512,   -68,
     388,   403,   349,   -56,   283,   191,   215,   363,   -56,   -68,
     191,   191,    79,   191,   356,   239,    80,   284,   362,   144,
     384,    87,   -68,   149,   426,   441,   350,    81,    72,   191,
     215,   401,   539,   242,   191,   215,   -61,   215,   394,   239,
     -61,   285,   400,   -68,   422,   -56,   -68,    73,   464,   145,
     -67,   -61,   483,   191,   215,   439,   577,   146,   191,   239,
     -67,   239,   432,   239,   910,   132,   438,   911,   460,   -67,
     510,   133,   152,   -67,   147,   506,   -69,    82,   518,    93,
     191,   215,   481,   -85,   520,   191,   -69,    83,   516,   474,
     239,   -10,   -67,   480,   -85,   502,   243,   -67,    -8,   -69,
      86,   157,   295,   -10,   537,    -9,    40,   296,   239,    -8,
     925,   -62,   509,   926,   -10,   -62,   -67,    41,   161,    94,
     -69,   122,   -81,   -69,    87,   -67,   -62,   560,   575,   -67,
     158,   159,   191,   215,   535,   163,   -70,   191,   318,   164,
     318,   528,   239,   604,    40,   534,   -70,   556,   -67,   599,
     601,   598,    -5,   -67,   -67,    41,   191,   215,   573,   -70,
     165,   191,   342,   -67,   342,   566,   239,   -67,    -9,   572,
      72,   594,   357,    72,    -5,   242,   -73,   -12,   242,    -9,
     -70,   191,   -73,   -70,   -12,    -5,   -67,   638,    88,   387,
     645,   -67,   425,   611,    -7,   -12,   362,   104,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,    -7,    -6,   637,    -6,    79,   644,   215,
      -3,    80,   -11,   -74,    -7,   681,    88,    -6,   688,   -74,
     942,   654,   609,   943,   400,   104,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   395,   -78,   680,   -77,    79,   687,   239,   -78,    80,
     -77,   -71,   -72,   724,    88,    -3,   731,   -71,   -72,   697,
     652,   150,   438,   104,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   -11,
      40,   723,   433,    40,   730,    79,   239,    -3,   191,    80,
     -67,    41,   -11,   -67,    41,   771,    88,    82,   778,   -67,
     695,   744,   -67,   -67,   480,   104,   -67,    83,   792,    79,
      72,   132,   475,    80,    72,   242,   243,   468,   962,   242,
      86,   963,   -67,   770,   742,   -67,   777,   -67,   -65,   463,
     -67,   288,   104,   505,   782,    -3,   791,    72,   -65,   134,
     -11,   289,   242,   318,    87,   508,   -65,   -65,   529,   834,
      88,   -65,   841,    -3,   290,   807,   515,   -11,   534,   104,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   -65,   567,   833,   291,    79,
     840,   342,   977,    80,   606,   978,   608,   877,    88,   607,
     884,   612,   614,   850,   781,   615,   572,   104,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   616,   650,   876,    79,   649,   883,   898,
      80,   889,   651,   655,   657,    79,   901,   191,   318,    80,
     191,   805,   191,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     848,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   658,   659,
     692,   694,   693,   700,   702,   -39,   698,    82,   -39,   734,
     -39,   701,   913,   -41,   904,   739,   -41,    83,   -41,   916,
     215,   318,   740,   215,   741,   215,   -39,   745,   748,   747,
      86,   -39,   -39,   -39,   -41,   -39,   -39,   749,   784,   -41,
     -41,   -41,   -64,   -41,   -41,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -64,   785,    87,   928,   795,   919,   796,   797,
     -64,   -64,   931,   239,   318,   -64,   239,   -40,   239,   798,
     -40,   -55,   -40,   799,   800,   802,   -55,   803,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   804,   810,   808,   -40,   -64,
     -55,   847,   811,   -40,   -40,   -40,   -66,   -40,   -40,   812,
     -47,   845,   945,   -47,   936,   -47,   -66,   846,   851,   948,
     853,   318,   854,   887,   -66,   -66,   855,    -4,    -4,   -66,
      72,   -47,   888,   953,    -4,   242,   -47,   -47,   -47,   935,
     -47,   -47,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   559,
      -4,    40,  1025,   -66,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -67,    41,   934,   -46,    -4,   986,   -46,    72,   -46,
     -67,    -8,   -10,   242,   -67,   965,   -38,   956,   987,   513,
      -9,   -38,   968,   318,   318,   -46,   318,   597,   318,   989,
     -46,   -46,   -46,   -67,   -46,   -46,   990,   -38,   -67,   991,
     295,   994,   514,   -38,   -38,   296,   -38,   -38,   995,   999,
    1000,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   980,   647,
     971,    -8,   -10,    -9,  1002,   983,   342,   318,  1003,   342,
    1004,   342,    82,   -44,  1007,  1008,   -44,  1013,   -44,  1012,
      -8,  1015,    83,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     610,    85,   -10,   992,   -44,    86,  1016,   997,    -9,   -44,
     -44,   -44,   295,   -44,   -44,   -80,    40,   296,  1005,   295,
     -80,  1020,  1010,  1017,   296,   191,   -67,    41,  1021,    87,
    1026,   690,   996,  1018,    82,   -67,   -80,  1023,   733,   -67,
     215,    40,   -80,   -80,    83,   -80,   -80,  1009,    -8,  1027,
    1032,   -67,    41,   243,  1037,   239,   295,    86,   -67,  1042,
     -67,   296,  1022,   -67,   -67,   -10,    -9,  1029,  1030,  1031,
    1050,  1034,    82,    -8,  1055,   780,   613,   633,  1035,  1036,
    1039,    87,    83,   -67,  1041,  1063,    82,   634,   -67,  1068,
     653,    85,   318,   295,  1040,    86,    83,  1044,   296,  1054,
     635,  1045,    27,    82,  1047,   243,   -10,   342,    -9,    86,
     192,   216,   794,    83,  1067,   192,    27,   191,    27,    87,
     240,   696,    85,  1048,   636,   640,    86,    27,   656,   150,
     215,    27,   295,    87,  1049,   641,  1052,   296,  1053,  1057,
    1058,  1060,  1061,   239,  1065,  1062,  1066,    -5,   642,  1070,
      87,   843,    -5,   280,  1072,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
    1073,   295,   643,   347,  1075,   318,   296,  1076,    -5,    27,
     319,    -5,  1078,   348,  1080,  1082,    27,  1083,   342,   676,
     886,    82,   -57,    -5,    27,   343,   349,   -57,  1085,   677,
     191,    83,   191,   215,  1086,   215,   239,  1088,   239,   -12,
     243,   -57,   678,   318,    86,   318,   342,   169,   342,   -12,
     350,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -12,   -12,
     -12,   240,    82,   699,    82,   192,   679,    -7,    87,    27,
      -6,    -7,    83,   -43,    83,    27,   -43,    27,   -43,   -58,
     743,    85,    -6,   243,   -58,    86,    -7,    86,    -6,    -7,
      -6,   -56,    -7,    27,   -43,   683,   -56,    27,   -58,   -43,
     -43,   -43,     0,   -43,   -43,   684,   746,   192,   216,    87,
     -56,    87,   192,   192,    -6,   192,     0,   240,   685,     0,
       0,     0,   192,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
       0,   192,   216,     0,    82,     0,   192,   216,     0,   216,
       0,   240,   686,     0,    83,   -50,   216,     0,   -50,     0,
     -50,     0,   806,    85,     0,   192,   216,    86,     0,     0,
     192,   240,     0,   240,     0,   240,   -50,    82,     0,     0,
     240,   -50,   -50,   -50,    82,   -50,   -50,    83,     0,     0,
       0,    87,   192,   216,    83,     0,   243,   192,     0,     0,
      86,     0,   240,   243,     0,     0,    82,    86,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,     0,    83,   719,    82,   783,
     240,     0,     0,     0,    87,   243,   809,   720,    83,    86,
     -42,    87,   726,   -42,     0,   -42,   849,    85,     0,     0,
     721,    86,   727,     0,   192,   216,     0,     0,   852,   192,
     319,   -42,   319,    87,   240,   728,   -42,   -42,   -42,   319,
     -42,   -42,     0,     0,   722,    87,     0,     0,   192,   216,
       0,     0,     0,   192,   343,     0,   343,     0,   240,   729,
       0,     0,   -75,   343,     0,    82,     0,     0,     0,     0,
       0,     0,   -75,   192,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,   243,   -75,     0,     0,    86,   280,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,     0,   -75,   893,     0,   -75,
       0,   216,    87,     0,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,   293,     0,     0,   280,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,     0,     0,     0,     0,     0,     0,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   280,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,     0,     0,   151,     0,   154,     0,     0,   240,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   280,     0,   -39,
     -39,     0,     0,     0,   -39,   -39,     0,     0,     0,   -39,
     151,     0,   -39,     0,     0,   -39,     0,   -39,     0,   -39,
     -39,   -39,   -39,   -39,   280,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,   -39,   -39,   319,     0,     0,   -39,   -39,
     -39,     0,   -39,     0,     0,   -39,     0,     0,     0,     0,
       0,   280,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,     0,     0,     0,
       0,     0,     0,   343,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   280,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,     0,   766,    82,    82,     0,
       0,   773,     0,     0,     0,     0,   767,    83,    83,   192,
     319,   774,   192,     0,   192,     0,   243,   243,     0,   768,
      86,    86,     0,     0,   775,     0,     0,     0,     0,     0,
       0,     0,   321,   322,   569,     4,     5,   324,   325,   908,
     923,   -32,   -32,   769,    87,    87,   -32,   -32,   776,     0,
     -76,   -32,   216,   319,   328,   216,     0,   216,     0,   330,
     -76,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,
     -32,   -32,   -32,   -76,     0,   570,   -32,     0,   600,   602,
     -65,   335,   336,    82,   337,     0,     0,   -32,     0,     0,
     -65,   787,     0,    83,   -76,   240,   319,   -76,   240,   -65,
     240,   788,   243,   -65,     0,    82,    86,     0,     0,     0,
       0,     0,     0,     0,   789,    83,   639,     0,     0,   646,
       0,     0,   -65,     0,   243,   940,     0,   -65,    86,     0,
      87,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   790,     0,
     -40,   -40,     0,   319,     0,   -40,   -40,   951,     0,   347,
     -40,     0,    87,   -40,   682,   -78,   -40,   689,   -40,   348,
     -40,   -40,   -40,   -40,   -40,   -78,   -40,   -40,   -40,   -40,
     -40,   -40,   349,   561,   -40,   -40,   562,     0,   -78,   -40,
     -40,   -40,     0,   -40,    82,     0,   -40,     0,     0,     0,
       0,     0,   725,   736,    83,   732,   350,     0,     0,   -78,
     151,     0,   -78,   243,     0,   319,   319,    86,   319,     0,
     319,   -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   960,     0,     0,     0,
       0,    87,     0,   -48,   772,     0,   -48,   779,   -48,     0,
       0,   -51,   829,     0,   -51,     0,   -51,   793,   343,   319,
       0,   343,   830,   343,   -48,     0,     0,     0,     0,   -48,
     -48,   -48,   -51,   -48,   -48,   831,     0,   -51,   -51,   -51,
       0,   -51,   -51,     1,     2,    37,     4,     5,     6,     7,
       0,   170,   171,   359,     4,     5,   173,   174,   835,   832,
       0,   842,   -77,     0,     0,    10,     0,   192,     0,     0,
      12,     0,   -77,   177,   192,     0,     0,     0,   179,    14,
       0,     0,   216,     0,     0,   -77,    38,   181,     0,   216,
      16,     0,    17,    18,   360,    19,   878,   240,   183,   885,
     184,   185,     0,   186,   240,     0,   -77,   836,     0,   -77,
       0,     0,     0,     0,     0,     0,     0,   837,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,     0,   280,     0,     0,     0,
     838,     0,    82,     0,   319,     0,     0,     0,     0,     0,
     -75,   319,    83,   -75,    28,   -75,     0,     0,     0,   343,
       0,   243,   193,   217,   839,    86,   343,   193,    28,   192,
      28,   -75,   241,     0,     0,   872,   -75,   -75,   -75,    28,
     -75,   -75,   216,    28,   975,   873,     0,     0,     0,    87,
       0,     0,     0,     0,     0,   240,     0,     0,   874,     0,
       0,     0,     0,     0,     0,   281,     0,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,   875,     0,     0,   347,     0,   319,     0,     0,
       0,    28,   320,     0,     0,   348,     0,     0,    28,     0,
     343,   879,     0,   -64,     0,     0,    28,   344,   349,     0,
       0,   880,   192,   -64,   192,   216,     0,   216,   240,     0,
     240,   -66,   -64,     0,   881,   319,   -64,   319,   343,  1079,
     343,   -66,   350,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -66,     0,     0,   241,   -66,   -64,     0,   193,   882,     0,
     -64,    28,     0,     0,     0,   -76,     0,    28,   -76,    28,
     -76,     0,     0,   -66,     0,     0,     0,     0,   -66,     0,
       0,     0,     0,     0,     0,    28,   -76,     0,     0,    28,
       0,   -76,   -76,   -76,     0,   -76,   -76,     0,     0,   193,
     217,     0,     0,     0,   193,   193,     0,   193,     0,   241,
       0,     0,     0,     0,   193,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,     0,   193,   217,     0,     0,     0,   193,   217,
       0,   217,     0,   241,     0,     0,     0,   -35,   217,     0,
     954,     0,   -35,     0,     0,     0,     0,   193,   217,     0,
       0,     0,   193,   241,     0,   241,     0,   241,   -35,     0,
       0,     0,   241,   955,   -35,   -35,     0,   -35,   -35,     0,
       0,     0,     0,     0,   193,   217,     0,     0,     0,   193,
       0,     0,   993,     0,   241,     0,   998,     0,     0,     0,
       0,     0,     0,   -18,   -18,     0,     0,  1006,   -18,   -18,
       0,  1011,   241,   -18,     0,     0,     0,     0,     0,     0,
       0,     0,  1019,     0,     0,     0,  1024,   587,     0,   588,
     589,   590,   591,   592,   593,     0,   193,   217,   -18,  1033,
       0,   193,   320,  1038,   320,     0,   241,     0,  1043,   -18,
       0,   320,     0,     0,     0,     0,     0,     0,     0,  1051,
     193,   217,     0,  1056,     0,   193,   344,     0,   344,     0,
     241,     0,     0,     0,  1064,   344,     0,     0,  1069,     0,
       0,     0,     0,     0,     0,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,     0,   151,     0,
       0,     0,     0,   217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,     0,     0,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,     0,     0,     0,     0,     0,     0,     0,
     241,     0,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   281,
       0,   -41,   -41,     0,     0,     0,   -41,   -41,     0,     0,
       0,   -41,     0,     0,   -41,     0,     0,   -41,     0,   -41,
       0,   -41,   -41,   -41,   -41,   -41,   281,   -41,   -41,   -41,
     -41,   -41,   -41,     0,     0,   -41,   -41,   320,     0,     0,
     -41,   -41,   -41,     0,   -41,     0,     0,   -41,     0,     0,
       0,     0,     0,   281,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,     0,
       0,     0,     0,     0,     0,   344,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,     0,     0,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,
       0,   193,   320,     0,   193,     0,   193,     0,     0,     0,
       0,   -73,     0,     0,   -73,     0,   -73,     0,   -40,     0,
       0,   -40,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,
     -40,   -40,   -73,     0,     0,   -40,   -40,   -73,   -73,   -73,
     -40,   -73,   -73,   -40,   217,   320,   -40,   217,   -40,   217,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,
     -40,   -40,     0,    29,   -40,     0,    30,     0,     0,   -40,
     -40,   -40,     0,   -40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   320,     0,
     241,     0,   241,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
       0,     0,   -47,   -47,     0,     0,     0,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,     0,     0,   -47,     0,
     -47,     0,   -47,   -47,   -47,   -47,   -47,   -16,   -47,   -47,
     -47,   -47,   -47,   -47,     0,   320,   -47,   -47,     0,   -16,
     -16,   -47,   -47,   -47,     0,   -47,     0,     0,   -47,   -16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,     0,     0,     0,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,     0,     0,   -46,   -46,     0,     0,     0,   -46,   -46,
       0,     0,     0,   -46,     0,     0,   -46,   320,   320,   -46,
     320,   -46,   320,   -46,   -46,   -46,   -46,   -46,     0,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,     0,
       0,     0,   -46,   -46,   -46,     0,   -46,     0,     0,   -46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     344,   320,     0,   344,     0,   344,     0,     0,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,     0,     0,   -34,   -34,     0,
       0,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
     -34,     0,     0,     0,     0,   -34,     0,   -34,   -34,   -34,
     -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,   193,
       0,   -34,   -34,     0,     0,     0,   193,   -34,   -34,     0,
     -34,     0,     0,   -34,   217,     0,     0,     0,     0,     0,
       0,   217,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   241,
       0,     0,     0,   578,   579,     0,   241,     0,   580,   581,
       0,     0,     0,   582,   -74,     0,     0,   -74,     0,   -74,
       0,     0,     0,   583,   584,   585,   586,   587,   281,   588,
     589,   590,   591,   592,   593,   -74,   320,     0,   -13,     0,
     -74,   -74,   -74,   320,   -74,   -74,    24,     0,     0,   -13,
       0,   344,     0,     0,   189,   213,     0,     0,   344,   189,
      39,   193,    45,     0,   237,     0,     0,   -18,   -18,     0,
       0,     0,   -18,   -18,   217,    24,   -18,   -18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,     0,     0,
       0,   549,     0,   550,   551,   552,   553,   554,   555,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,   320,
       0,     0,     0,    24,   316,     0,     0,     0,     0,     0,
      24,     0,   344,     0,     0,     0,     0,     0,    24,   340,
       0,     0,     0,     0,   193,     0,   193,   217,     0,   217,
     241,     0,   241,     0,     0,     0,     0,   320,     0,   320,
     344,     0,   344,     0,     0,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -18,   -18,     0,   237,     0,   -18,   -18,   189,
       0,     0,   -18,    24,     0,     0,     0,   -45,     0,     0,
     -45,    24,   -45,     0,     0,     0,   377,     0,   378,   379,
     380,   381,   382,   383,     0,     0,     0,    24,   -45,   -18,
       0,    24,     0,   -45,   -45,   -45,     0,   -45,   -45,     0,
       0,   189,   213,     0,     0,     0,   189,   361,     0,   364,
       0,   237,     0,     0,     0,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,     0,   189,   213,     0,     0,     0,
     189,   399,     0,   402,     0,   237,     0,   -49,     0,     0,
     -49,     0,   -49,     0,     0,     0,     0,     0,     0,   189,
     213,     0,     0,     0,   189,   437,     0,   440,   -49,   237,
       0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   189,   213,     0,   -16,
     -16,   189,   479,     0,   482,     0,   237,     0,     0,   -16,
       0,   -78,     0,     0,   -78,     0,   -78,     0,     0,   583,
     584,   585,   586,   587,   237,   588,   589,   590,   591,   592,
     593,     0,   -78,     0,   -16,     0,     0,   -78,   -78,   -78,
       0,   -78,   -78,     0,     0,   -16,     0,     0,   189,   213,
       0,     0,     0,   189,   533,     0,   536,     0,   237,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,     0,     0,     0,     0,
       0,     0,   189,   213,     0,     0,     0,   189,   571,     0,
     574,   -77,   237,     0,   -77,     0,   -77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,     0,   -77,     0,     0,     0,     0,   -77,   -77,   -77,
       0,   -77,   -77,     0,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,     0,
       0,     0,     0,     0,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,     0,     0,     0,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     704,   705,   706,   707,   708,   709,   710,   711,   712,   713,
     714,   715,   716,   717,   718,     0,     0,     0,     0,     0,
       0,     0,   237,     0,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   751,   752,   753,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763,   764,   765,   -71,     0,     0,
     -71,     0,   -71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -71,   316,
       0,     0,     0,   -71,   -71,   -71,     0,   -71,   -71,     0,
       0,     0,     0,     0,     0,     0,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     828,     0,     0,     0,     0,     0,     0,   340,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,   871,   -72,
       0,     0,   -72,     0,   -72,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   316,     0,   189,     0,   189,     0,
     -72,     0,     0,     0,     0,   -72,   -72,   -72,     0,   -72,
     -72,     0,     0,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
       0,     0,   -38,   -38,     0,     0,     0,   -38,   -38,     0,
       0,     0,   -38,     0,     0,   -38,   213,   316,   595,   213,
     -38,   213,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,   -38,   -38,     0,     0,
       0,   596,   -38,   -38,     0,   -38,     0,     0,   -38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     316,     0,   237,     0,   237,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,   -40,   -40,     0,     0,     0,   -40,
     -40,     0,     0,     0,   -40,     0,     0,   -40,     0,     0,
     -40,     0,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -17,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   316,   -40,   -40,
       0,   -17,   -17,   -40,   -40,   -40,     0,   -40,     0,     0,
     -40,   -17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,     0,     0,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,   -44,   -44,     0,     0,     0,
     -44,   -44,     0,     0,     0,   -44,     0,     0,   -44,   316,
     316,   -44,   316,   -44,   316,   -44,   -44,   -44,   -44,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,   -44,
     -44,     0,     0,     0,   -44,   -44,   -44,     0,   -44,     0,
       0,   -44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   340,   316,     0,   340,     0,   340,     0,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,     0,     0,   -43,   -43,
       0,     0,     0,   -43,   -43,     0,     0,     0,   -43,     0,
       0,   -43,     0,     0,   -43,     0,   -43,     0,   -43,   -43,
     -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,
       0,   189,   -43,   -43,     0,     0,     0,   -43,   -43,   -43,
       0,   -43,     0,     0,   -43,     0,   213,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
       0,   237,   -50,   -50,     0,     0,     0,   -50,   -50,     0,
       0,     0,   -50,     0,     0,   -50,     0,     0,   -50,     0,
     -50,     0,   -50,   -50,   -50,   -50,   -50,     0,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,   -50,   -50,   316,     0,
       0,   -50,   -50,   -50,     0,   -50,    25,     0,   -50,     0,
       0,     0,     0,   340,   190,   214,     0,   -16,   -16,   190,
      25,     0,    25,   189,   238,   -16,     0,   -16,     0,     0,
       0,     0,     0,     0,     0,    25,   213,   411,   412,   413,
     414,   415,     0,   416,   417,   418,   419,   420,   421,   237,
       0,     0,   269,   270,   271,     4,     5,   272,   273,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,   274,     0,     0,     0,     0,   275,
       0,   316,     0,    25,   317,     0,     0,     0,     0,     0,
      25,     0,     0,     0,   340,   276,     0,     0,    25,   341,
       0,   277,   278,     0,   279,   103,   189,     0,   189,   213,
       0,   213,   237,     0,   237,     0,     0,     0,     0,   316,
     -18,   316,   340,     0,   340,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -18,   -18,     0,   238,     0,   -18,   -18,   190,
       0,     0,   -18,    25,     0,     0,     0,   -79,     0,     0,
       0,    25,   -79,     0,     0,     0,    62,     0,    63,    64,
      65,    66,    67,    68,     0,     0,     0,    25,   -79,     0,
       0,    25,     0,     0,   -79,   -79,     0,   -79,   -79,     0,
       0,   190,   214,     0,     0,     0,   190,   190,     0,   190,
       0,   238,     0,     0,     0,   269,   270,   271,     4,     5,
     272,   273,     0,     0,     0,   190,   214,     0,     0,     0,
     190,   214,     0,   214,     0,   238,     0,   274,     0,     0,
       0,     0,   275,     0,     0,     0,     0,     0,     0,   190,
     214,     0,     0,     0,   190,   238,     0,   238,   276,   238,
       0,     0,     0,     0,   277,   278,     0,   279,   617,   269,
     270,   271,     4,     5,   272,   273,   190,   214,     0,   -15,
     -15,   190,     0,     0,   -15,   -15,   238,     0,     0,   -15,
       0,   274,     0,     0,     0,     0,   275,     0,     0,   -15,
     -15,   -15,   -15,   -15,   238,   -15,   -15,   -15,   -15,   -15,
     -15,     0,   276,     0,   -15,     0,     0,     0,   277,   278,
       0,   279,   660,     0,     0,   -15,     0,     0,   190,   214,
       0,     0,     0,   190,   317,     0,   317,     0,   238,   269,
     270,   271,     4,     5,   272,   273,     0,     0,     0,     0,
       0,     0,   190,   214,     0,     0,     0,   190,   341,     0,
     341,   274,   238,     0,     0,     0,   275,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,     0,     0,
       0,     0,   276,     0,     0,     0,     0,     0,   277,   278,
       0,   279,   703,     0,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,     0,     0,     0,
       0,     0,     0,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,   270,   271,     4,     5,   272,   273,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   274,     0,     0,     0,     0,
     275,     0,   238,     0,   190,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,     0,     0,   -42,   -42,   276,     0,     0,   -42,
     -42,     0,   277,   278,   -42,   279,   750,   -42,     0,     0,
     -42,     0,   -42,     0,   -42,   -42,   -42,   -42,   -42,     0,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,   -42,   -42,
       0,     0,     0,   -42,   -42,   -42,     0,   -42,     0,   317,
     -42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,     0,     0,     0,     0,     0,     0,   341,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,   270,   271,
       4,     5,   272,   273,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   274,
       0,     0,     0,     0,   275,     0,     0,     0,     0,     0,
       0,     0,     0,   190,   317,     0,   190,     0,   190,     0,
     276,     0,     0,     0,   -20,     0,   277,   278,     0,   279,
     786,     0,     0,     0,     0,     0,   -20,   -20,     0,     0,
      22,   -20,   -20,     0,     0,     0,   -20,     0,   187,   211,
       0,     0,     0,   187,     0,     0,   214,   317,   235,   214,
      62,   214,    63,    64,    65,    66,    67,    68,     0,    75,
       0,     0,     0,     0,     0,     0,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,     0,     0,   -33,   -33,     0,     0,     0,
     -33,   -33,     0,     0,     0,   -33,     0,     0,   -33,   238,
     317,     0,   238,   -33,   238,   -33,   -33,   -33,   -33,   -33,
       0,   -33,   -33,   -33,   -33,   -33,   -33,   124,   314,   -33,
     -33,     0,     0,     0,   128,   -33,   -33,     0,   -33,     0,
       0,   -33,   135,   338,     0,     0,     0,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,     0,     0,     0,   317,   194,   195,
     397,     4,     5,   197,   198,     0,     0,     0,     0,   -37,
       0,     0,     0,     0,   -37,     0,     0,     0,     0,   235,
     201,     0,     0,   187,     0,   203,     0,   156,     0,     0,
     -37,     0,     0,     0,   205,    22,   -37,   -37,     0,   -37,
     -37,   398,     0,     0,     0,   207,     0,   208,   209,     0,
     210,   166,     0,     0,     0,   168,     0,     0,     0,   317,
     317,     0,   317,     0,   317,   187,   211,     0,     0,     0,
     187,     0,     0,     0,     0,   235,     0,     0,     0,   269,
     270,   271,     4,     5,   272,   273,     0,     0,     0,   187,
     211,     0,     0,     0,   187,     0,     0,     0,     0,   235,
       0,   274,   341,   317,     0,   341,   275,   341,     0,     0,
       0,     0,     0,   187,   211,     0,     0,     0,   187,     0,
       0,     0,   276,   235,     0,     0,     0,     0,   277,   278,
       0,   279,   813,   269,   270,   271,     4,     5,   272,   273,
     187,   211,     0,   -20,   -20,   187,     0,     0,   -20,   -20,
     235,   190,     0,   -20,     0,   274,     0,     0,     0,     0,
     275,     0,     0,     0,     0,     0,   214,   587,   235,   588,
     589,   590,   591,   592,   593,     0,   276,     0,   -20,     0,
       0,   238,   277,   278,     0,   279,   856,     0,     0,   -20,
       0,     0,   187,   211,     0,     0,     0,   187,     0,     0,
       0,     0,   235,     0,     0,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,     0,     0,     0,     0,   187,   211,   317,     0,
       0,   187,     0,     0,     0,     0,   235,   -36,     0,     0,
       0,     0,   -36,   341,     0,     0,     0,     0,     0,     0,
       0,   605,     0,   190,     0,     0,     0,     0,   -36,     0,
       0,     0,     0,     0,   -36,   -36,   214,   -36,   -36,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     0,   238,
       0,     0,     8,     0,     0,     0,     0,     9,     0,   648,
       0,     0,     0,    10,     0,    11,     0,    23,    12,    13,
       0,     0,     0,     0,     0,   188,   212,    14,     0,     0,
     188,   317,     0,     0,    15,   236,     0,     0,    16,     0,
      17,    18,     0,    19,   341,     0,    23,   691,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,   190,   214,
       0,   214,   238,     0,   238,     0,     0,     0,     0,   317,
       0,   317,   341,     0,   341,     0,   170,   171,   172,     4,
       5,   173,   174,     0,     0,     0,   235,   175,   187,   738,
       0,     0,   176,     0,    23,   315,     0,     0,   177,     0,
     178,    23,     0,   179,   180,     0,     0,     0,     0,    23,
     339,     0,   181,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,   183,     0,   184,   185,     0,   186,     0,
       0,     0,     0,     0,     0,     0,   194,   195,   196,     4,
       5,   197,   198,   801,     0,     0,   236,   199,     0,     0,
     188,     0,   200,     0,    23,     0,     0,     0,   201,     0,
     202,     0,    23,   203,   204,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,    23,   206,
       0,   844,    23,   207,     0,   208,   209,     0,   210,     0,
       0,     0,   188,   212,     0,     0,     0,   188,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   188,   212,     0,     0,
       0,   188,     0,     0,     0,     0,   236,   890,   314,     0,
     892,     0,   894,   218,   219,   220,     4,     5,   221,   222,
     188,   212,     0,     0,   223,   188,     0,     0,     0,   224,
     236,     0,     0,     0,     0,   225,     0,   226,     0,     0,
     227,   228,     0,     0,     0,     0,     0,   188,   212,   229,
     905,   314,   188,   907,     0,   909,   230,   236,     0,     0,
     231,     0,   232,   233,     0,   234,     0,     0,   170,   171,
     359,     4,     5,   173,   174,   236,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,     0,     0,   920,   314,   179,   922,     0,   924,   188,
     212,     0,     0,     0,   188,     0,     0,     0,     0,   236,
       0,   360,     0,   -19,     0,     0,     0,   184,   185,     0,
     186,     0,     0,   188,   212,   -19,   -19,     0,   188,     0,
     -19,   -19,     0,   236,     0,   -19,     0,     0,     0,     0,
     937,   314,     0,   939,     0,   941,     0,     0,   188,    62,
       0,    63,    64,    65,    66,    67,    68,     0,     0,   -39,
       0,     0,   -39,   -39,   -39,   -39,   -39,   -39,   -39,     0,
       0,   -39,   -39,     0,     0,     0,   -39,   -39,     0,     0,
       0,   -39,     0,     0,   -39,     0,   212,   -39,     0,   -39,
       0,   -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,
     -39,   -39,   -39,   957,   314,   -39,   959,     0,   961,     0,
     -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,   -18,   -18,     0,     0,
       0,   -18,   -18,     0,     0,     0,   -18,   194,   195,   397,
       4,     5,   197,   198,     0,     0,   972,   314,     0,   974,
     453,   976,   454,   455,   456,   457,   458,   459,     0,   201,
       0,     0,     0,   236,   203,   188,     0,     0,   -18,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,     0,     0,   -48,   -48,
     398,     0,     0,   -48,   -48,     0,   208,   209,   -48,   210,
       0,   -48,     0,     0,   -48,   988,   -48,     0,   -48,   -48,
     -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,
    1001,     0,   -48,   -48,     0,     0,     0,   -48,   -48,   -48,
     315,   -48,     0,     0,   -48,  1014,     0,     0,     0,   245,
     246,   247,     4,     5,   248,   249,     0,     0,     0,     0,
     250,     0,  1028,     0,     0,   251,     0,     0,     0,     0,
       0,   252,     0,   253,     0,     0,   254,   255,   339,     0,
       0,     0,  1046,     0,     0,   256,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,   258,  1059,   259,   260,
       0,   261,     0,     0,     0,     0,     0,   187,     0,     0,
     297,   298,   299,     4,     5,   300,   301,     0,     0,     0,
     211,   302,     0,     0,   188,   315,   303,   188,     0,   188,
       0,     0,   304,   235,   305,     0,     0,   306,   307,     0,
       0,     0,     0,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,   309,     0,     0,     0,   310,     0,   311,
     312,     0,   313,     0,     0,   314,     0,   212,   315,     0,
     212,     0,   212,     0,     0,     0,     0,     0,   338,    31,
      32,     0,     0,     0,    36,     0,     0,     0,     0,    50,
    1089,     0,  1090,  1091,     0,  1092,  1093,     0,  1094,     0,
    1095,     0,  1096,  1097,     0,  1098,  1099,     0,  1100,     0,
     236,   315,     0,   236,     0,   236,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
     322,   323,     4,     5,   324,   325,     0,     0,     0,   125,
     326,   126,     0,     0,   127,   327,     0,     0,   315,     0,
       0,   328,     0,   329,   136,     0,   330,   331,   140,     0,
       0,     0,   142,     0,     0,   332,     0,     0,     0,     0,
       0,     0,   333,     0,     0,     0,   334,     0,   335,   336,
       0,   337,   218,   219,   435,     4,     5,   221,   222,     0,
     148,     0,     0,     0,   155,   218,   219,   435,     4,     5,
     221,   222,     0,     0,   225,     0,   162,     0,     0,   227,
     315,   315,     0,   315,     0,   315,     0,   225,   229,     0,
       0,     0,   227,     0,     0,   436,     0,     0,     0,   231,
       0,   232,   233,     0,   234,     0,   353,   354,   436,     0,
       0,   358,     0,     0,   232,   233,   366,   234,     0,     0,
       0,     0,     0,   339,   315,     0,   339,     0,   339,     0,
     391,   392,     0,     0,     0,   396,     0,     0,     0,     0,
     404,     0,     0,     0,     0,     0,     0,   245,   246,   477,
       4,     5,   248,   249,   429,   430,     0,     0,     0,   434,
       0,     0,     0,     0,   442,     0,     0,     0,     0,   252,
       0,     0,   188,   465,   254,     0,     0,     0,     0,     0,
       0,   471,   472,   256,     0,     0,   476,   212,     0,     0,
     478,   484,     0,     0,   258,     0,   259,   260,     0,   261,
       0,     0,   236,     0,     0,     0,   -21,     0,     0,   511,
       0,     0,     0,     0,   517,     0,     0,     0,   -21,   -21,
     519,     0,     0,   -21,   -21,   521,     0,   522,   -21,     0,
       0,     0,     0,   525,   526,     0,     0,     0,   530,   315,
       0,     0,    62,   538,    63,    64,    65,    66,    67,    68,
       0,     0,     0,     0,   339,     0,     0,   563,   564,     0,
       0,     0,   568,     0,   188,     0,     0,   576,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   -41,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,     0,     0,   -41,   -41,     0,     0,     0,   -41,   -41,
       0,     0,     0,   -41,     0,     0,   -41,     0,     0,   -41,
       0,   -41,   315,   -41,   -41,   -41,   -41,   -41,     0,   -41,
     -41,   -41,   -41,   -41,   -41,   339,     0,   -41,     0,     0,
       0,     0,   -41,   -41,   -41,     0,   -41,   188,     0,   188,
     212,     0,   212,   236,     0,   236,     0,     0,     0,     0,
     315,     0,   315,   339,     0,   339,     0,     0,     0,     0,
       0,   -51,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,
     -51,   -51,     0,     0,     0,   -51,   -51,     0,     0,     0,
     -51,     0,     0,   -51,     0,     0,   -51,   735,   -51,   737,
     -51,   -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,
     -51,   -51,     0,     0,   -51,   -51,     0,     0,     0,   -51,
     -51,   -51,     0,   -51,     0,     0,   -51,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,     0,     0,   -75,   -75,     0,     0,
       0,   -75,   -75,     0,     0,     0,   -75,     0,     0,   -75,
       0,     0,   -75,     0,   -75,     0,   -75,   -75,   -75,   -75,
     -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
     -75,   -75,     0,     0,     0,   -75,   -75,   -75,     0,   -75,
       0,     0,   -75,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
       0,     0,   -76,   -76,     0,     0,     0,   -76,   -76,     0,
       0,     0,   -76,     0,     0,   -76,     0,     0,   -76,     0,
     -76,     0,   -76,   -76,   -76,   -76,   -76,     0,   -76,   -76,
     -76,   -76,   -76,   -76,     0,     0,   -76,   -76,     0,     0,
       0,   -76,   -76,   -76,     0,   -76,     0,     0,   -76,   891,
       0,     0,     0,     0,     0,     0,     0,     0,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,   -35,   -35,     0,
       0,     0,   -35,   -35,     0,   897,     0,   -35,     0,     0,
     -35,     0,   900,   984,     0,   -35,     0,   -35,   -35,   -35,
     -35,   -35,   906,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,   -35,   -35,     0,     0,     0,   985,   -35,   -35,     0,
     -35,     0,     0,   -35,     0,     0,     0,     0,   912,     0,
       0,     0,     0,     0,     0,   915,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   921,     0,     0,     0,     0,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,   -73,
     -73,     0,     0,     0,   -73,   -73,     0,     0,     0,   -73,
       0,   927,   -73,     0,     0,   -73,     0,   -73,   930,   -73,
     -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,   -73,   -73,
     -73,     0,   938,   -73,   -73,     0,     0,     0,   -73,   -73,
     -73,     0,   -73,     0,     0,   -73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   944,     0,
       0,     0,     0,     0,     0,   947,     0,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,     0,     0,   -74,   -74,     0,   952,
       0,   -74,   -74,     0,     0,     0,   -74,     0,     0,   -74,
       0,     0,   -74,     0,   -74,   958,   -74,   -74,   -74,   -74,
     -74,     0,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,
     -74,   -74,     0,     0,     0,   -74,   -74,   -74,     0,   -74,
       0,   964,   -74,     0,     0,     0,     0,     0,   967,     0,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,   973,   -45,
     -45,     0,     0,     0,   -45,   -45,     0,     0,     0,   -45,
       0,     0,   -45,     0,     0,   -45,     0,   -45,     0,   -45,
     -45,   -45,   -45,   -45,   979,   -45,   -45,   -45,   -45,   -45,
     -45,   982,     0,   -45,   -45,     0,     0,     0,   -45,   -45,
     -45,     0,   -45,     0,     0,   -45,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,   -49,   -49,     0,     0,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,     0,
       0,   -49,     0,   -49,     0,   -49,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,   -49,
     -49,     0,     0,     0,   -49,   -49,   -49,     0,   -49,     0,
       0,   -49,     0,     0,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,     0,     0,   -78,   -78,     0,     0,     0,   -78,   -78,
       0,     0,     0,   -78,     0,     0,   -78,     0,     0,   -78,
       0,   -78,     0,   -78,   -78,   -78,   -78,   -78,  1071,   -78,
     -78,   -78,   -78,   -78,   -78,   -17,   -17,   -78,   -78,     0,
       0,  1074,   -78,   -78,   -78,   -17,   -78,     0,     0,   -78,
       0,     0,     0,     0,  1077,   583,   584,   585,   586,   587,
       0,   588,   589,   590,   591,   592,   593,     0,  1081,     0,
     -17,     0,     0,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
       0,   -17,   -77,   -77,     0,     0,  1084,   -77,   -77,     0,
       0,     0,   -77,     0,     0,   -77,     0,     0,   -77,  1087,
     -77,     0,   -77,   -77,   -77,   -77,   -77,     0,   -77,   -77,
     -77,   -77,   -77,   -77,     0,     0,   -77,   -77,     0,     0,
       0,   -77,   -77,   -77,     0,   -77,     0,     0,   -77,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   -71,   -71,
       0,     0,     0,   -71,   -71,     0,     0,     0,   -71,     0,
       0,   -71,     0,     0,   -71,     0,   -71,     0,   -71,   -71,
     -71,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,   -71,   -71,     0,     0,     0,   -71,   -71,   -71,
       0,   -71,     0,     0,   -71,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,     0,     0,   -72,   -72,     0,     0,     0,   -72,
     -72,     0,     0,     0,   -72,     0,     0,   -72,     0,     0,
     -72,     0,   -72,     0,   -72,   -72,   -72,   -72,   -72,     0,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,   -72,   -72,
       0,     0,     0,   -72,   -72,   -72,     0,   -72,   -47,     0,
     -72,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
     -47,   -47,     0,     0,     0,   -47,   -47,     0,     0,     0,
     -47,     0,     0,   -47,     0,     0,   -47,     0,   -47,     0,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,   -47,     0,     0,     0,     0,   -47,
     -47,   -47,   -46,   -47,     0,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,   -46,   -46,     0,     0,     0,   -46,
     -46,     0,     0,     0,   -46,     0,     0,   -46,     0,     0,
     -46,     0,   -46,     0,   -46,   -46,   -46,   -46,   -46,     0,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,   -46,     0,
       0,     0,     0,   -46,   -46,   -46,   -38,   -46,     0,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,     0,     0,   -38,   -38,
       0,     0,     0,   -38,   -38,     0,     0,     0,   -38,     0,
       0,   -38,     0,     0,    70,     0,   -38,     0,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,
       0,     0,   -38,     0,     0,     0,     0,    71,   -38,   -38,
     -40,   -38,     0,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,   -40,   -40,     0,     0,     0,   -40,   -40,     0,
       0,     0,   -40,     0,     0,   -40,     0,     0,   -40,     0,
     -40,     0,   -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,     0,   -40,     0,     0,     0,
       0,   -40,   -40,   -40,   -44,   -40,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,     0,     0,   -44,   -44,     0,     0,
       0,   -44,   -44,     0,     0,     0,   -44,     0,     0,   -44,
       0,     0,   -44,     0,   -44,     0,   -44,   -44,   -44,   -44,
     -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,
     -44,     0,     0,     0,     0,   -44,   -44,   -44,   -43,   -44,
       0,   -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
     -43,   -43,     0,     0,     0,   -43,   -43,     0,     0,     0,
     -43,     0,     0,   -43,     0,     0,   -43,     0,   -43,     0,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,
     -43,   -43,     0,     0,   -43,     0,     0,     0,     0,   -43,
     -43,   -43,   -50,   -43,     0,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,     0,     0,   -50,   -50,     0,     0,     0,   -50,
     -50,     0,     0,     0,   -50,     0,     0,   -50,     0,     0,
     -50,     0,   -50,     0,   -50,   -50,   -50,   -50,   -50,     0,
     -50,   -50,   -50,   -50,   -50,   -50,     0,     0,   -50,     0,
       0,     0,     0,   -50,   -50,   -50,   -42,   -50,     0,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,   -42,   -42,
       0,     0,     0,   -42,   -42,     0,     0,     0,   -42,     0,
       0,   -42,     0,     0,   -42,     0,   -42,     0,   -42,   -42,
     -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,
       0,     0,   -42,     0,     0,     0,     0,   -42,   -42,   -42,
     -48,   -42,     0,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,   -48,   -48,     0,     0,     0,   -48,   -48,     0,
       0,     0,   -48,     0,     0,   -48,     0,     0,   -48,     0,
     -48,     0,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
     -48,   -48,   -48,   -48,     0,     0,   -48,     0,     0,     0,
       0,   -48,   -48,   -48,   -51,   -48,     0,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,   -51,   -51,     0,     0,
       0,   -51,   -51,     0,     0,     0,   -51,     0,     0,   -51,
       0,     0,   -51,     0,   -51,     0,   -51,   -51,   -51,   -51,
     -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,
     -51,     0,     0,     0,     0,   -51,   -51,   -51,   -35,   -51,
       0,   -35,   -35,   -35,   -35,   -35,   -35,   -35,     0,     0,
     -35,   -35,     0,     0,     0,   -35,   -35,     0,     0,     0,
     -35,     0,     0,   -35,     0,     0,   143,     0,   -35,     0,
     -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,   -35,   -35,
     -35,   -35,     0,     0,   -35,     0,     0,     0,     0,   346,
     -35,   -35,   -45,   -35,     0,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,   -45,   -45,     0,     0,     0,   -45,
     -45,     0,     0,     0,   -45,     0,     0,   -45,     0,     0,
     -45,     0,   -45,     0,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,   -45,   -45,   -45,   -45,     0,     0,   -45,     0,
       0,     0,     0,   -45,   -45,   -45,   -49,   -45,     0,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,     0,     0,   -49,   -49,
       0,     0,     0,   -49,   -49,     0,     0,     0,   -49,     0,
       0,   -49,     0,     0,   -49,     0,   -49,     0,   -49,   -49,
     -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,   -49,     0,     0,     0,     0,   -49,   -49,   -49,
     -75,   -49,     0,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
       0,     0,   -75,   -75,     0,     0,     0,   -75,   -75,     0,
       0,     0,   -75,     0,     0,   -75,     0,     0,   -75,     0,
     -75,     0,   -75,   -75,   -75,   -75,   -75,     0,   -75,   -75,
     -75,   -75,   -75,   -75,     0,     0,   -75,     0,     0,     0,
       0,   -75,   -75,   -75,   -76,   -75,     0,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,     0,     0,   -76,   -76,     0,     0,
       0,   -76,   -76,     0,     0,     0,   -76,     0,     0,   -76,
       0,     0,   -76,     0,   -76,     0,   -76,   -76,   -76,   -76,
     -76,     0,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,
     -76,     0,     0,     0,     0,   -76,   -76,   -76,   -73,   -76,
       0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
     -73,   -73,     0,     0,     0,   -73,   -73,     0,     0,     0,
     -73,     0,     0,   -73,     0,     0,   -73,     0,   -73,     0,
     -73,   -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,   -73,
     -73,   -73,     0,     0,   -73,     0,     0,     0,     0,   -73,
     -73,   -73,   -74,   -73,     0,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,   -74,   -74,     0,     0,     0,   -74,
     -74,     0,     0,     0,   -74,     0,     0,   -74,     0,     0,
     -74,     0,   -74,     0,   -74,   -74,   -74,   -74,   -74,     0,
     -74,   -74,   -74,   -74,   -74,   -74,     0,     0,   -74,     0,
       0,     0,     0,   -74,   -74,   -74,   -71,   -74,     0,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   -71,   -71,
       0,     0,     0,   -71,   -71,     0,     0,     0,   -71,     0,
       0,   -71,     0,     0,   -71,     0,   -71,     0,   -71,   -71,
     -71,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,   -71,     0,     0,     0,     0,   -71,   -71,   -71,
     -72,   -71,     0,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
       0,     0,   -72,   -72,     0,     0,     0,   -72,   -72,     0,
       0,     0,   -72,     0,     0,   -72,     0,     0,   -72,     0,
     -72,     0,   -72,   -72,   -72,   -72,   -72,     0,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,   -72,     0,     0,     0,
       0,   -72,   -72,   -72,   -78,   -72,     0,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,   -78,   -78,     0,     0,
       0,   -78,   -78,     0,     0,     0,   -78,     0,     0,   -78,
       0,     0,   -78,     0,   -78,     0,   -78,   -78,   -78,   -78,
     -78,     0,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
     -78,     0,     0,     0,     0,   -78,   -78,   -78,   -77,   -78,
       0,   -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,
     -77,   -77,     0,     0,     0,   -77,   -77,     0,     0,     0,
     -77,     0,     0,   -77,     0,     0,   -77,     0,   -77,     0,
     -77,   -77,   -77,   -77,   -77,     0,   -77,   -77,   -77,   -77,
     -77,   -77,     0,     0,   -77,     0,     0,     0,     0,   -77,
     -77,   -77,     0,   -77,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,     0,     0,   -37,   -37,     0,     0,     0,   -37,   -37,
       0,     0,     0,   -37,     0,     0,   -37,     0,     0,     0,
       0,   -37,     0,   -37,   -37,   -37,   -37,   -37,     0,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,   -37,   -37,     0,
       0,     0,     0,   -37,   -37,     0,   -37,     0,     0,   -37,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,   -36,
     -36,     0,     0,     0,   -36,   -36,     0,     0,     0,   -36,
       0,     0,   -36,     0,     0,     0,     0,   -36,     0,   -36,
     -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,
     -36,     0,     0,   -36,   -36,     0,     0,     0,     0,   -36,
     -36,     0,   -36,   -32,     0,   -36,     1,     2,    37,     4,
       5,     6,     7,     0,     0,   -32,   -32,     0,     0,     0,
     -32,   -32,     0,     0,     0,   -32,     0,     0,    10,     0,
       0,     0,     0,    12,     0,   -32,   -32,   -32,   -32,   -32,
       0,   -32,   -32,   -32,   -32,   -32,   -32,     0,     0,    38,
       0,     0,     0,     0,     0,    17,    18,   -34,    19,     0,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,     0,   -34,
     -34,     0,     0,     0,   -34,   -34,     0,     0,     0,   -34,
       0,     0,   -34,     0,     0,     0,     0,   -34,     0,   -34,
     -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,   -34,     0,     0,     0,     0,     0,   -34,
     -34,   -33,   -34,     0,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,     0,     0,   -33,   -33,     0,     0,     0,   -33,   -33,
       0,     0,     0,   -33,     0,     0,   -33,     0,     0,     0,
       0,   -33,     0,   -33,   -33,   -33,   -33,   -33,     0,   -33,
     -33,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,     0,
       0,     0,     0,   -33,   -33,   -37,   -33,     0,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,   -37,   -37,     0,
       0,     0,   -37,   -37,     0,     0,     0,   -37,     0,     0,
     -37,     0,     0,     0,     0,   -37,     0,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,   -37,     0,     0,     0,     0,     0,   -37,   -37,   -36,
     -37,     0,   -36,   -36,   -36,   -36,   -36,   -36,   -36,     0,
       0,   -36,   -36,     0,     0,     0,   -36,   -36,     0,     0,
       0,   -36,     0,     0,   -36,     0,     0,     0,     0,   -36,
       0,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,
     -36,   -36,   -36,     0,     0,   -36,     0,     0,     0,     0,
       0,   -36,   -36,     0,   -36,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,   -40,   -40,     0,     0,     0,   -40,
     -40,     0,     0,     0,   -40,     0,     0,   -40,     0,     0,
     -40,     0,   -40,     0,   -40,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   351,   -40,     0,
     352,   -40,     0,   -40,   -40,   -40,     0,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,     0,     0,   -40,   -40,     0,
       0,     0,   -40,   -40,     0,   -40,     0,   -40,     0,     0,
     -40,     0,     0,   -40,     0,   -40,     0,   -40,   -40,   -40,
     -40,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,
     389,   -40,     0,   390,     0,     0,   -40,   -40,   -40,     0,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,
     -40,   -40,     0,     0,     0,   -40,   -40,     0,     0,     0,
     -40,     0,     0,   -40,     0,     0,   -40,     0,   -40,     0,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,
     -40,   -40,     0,   427,   -40,     0,   428,     0,     0,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,     0,     0,   -40,   -40,     0,     0,     0,   -40,   -40,
       0,     0,     0,   -40,     0,     0,   -40,     0,     0,   -40,
       0,   -40,     0,   -40,   -40,   -40,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,   -40,     0,   469,   -40,   -40,   470,
       0,     0,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,     0,     0,   -40,   -40,     0,     0,
       0,   -40,   -40,     0,     0,   -40,   -40,     0,     0,   -40,
       0,     0,   -40,     0,   -40,     0,   -40,   -40,   -40,   -40,
     -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,   523,
     -40,     0,   524,     0,     0,   -40,   -40,   -40,     0,   -40,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,   -39,
     -39,     0,     0,     0,   -39,   -39,     0,     0,     0,   -39,
       0,     0,   -39,     0,     0,   -39,     0,   -39,     0,   -39,
     -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,   -39,     0,     0,   -39,     0,   -39,   -39,
     -39,     0,   -39,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
       0,     0,   -41,   -41,     0,     0,     0,   -41,   -41,     0,
       0,     0,   -41,     0,     0,   -41,     0,     0,   -41,     0,
     -41,     0,   -41,   -41,   -41,   -41,   -41,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,   -41,     0,     0,   -41,
       0,   -41,   -41,   -41,     0,   -41,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,     0,     0,   -47,   -47,     0,     0,     0,
     -47,   -47,     0,     0,     0,   -47,     0,     0,   -47,     0,
       0,   -47,     0,   -47,     0,   -47,   -47,   -47,   -47,   -47,
       0,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,
       0,     0,   -47,     0,   -47,   -47,   -47,     0,   -47,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,
       0,     0,     0,   -46,   -46,     0,     0,     0,   -46,     0,
       0,   -46,     0,     0,   -46,     0,   -46,     0,   -46,   -46,
     -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,   -46,     0,     0,   -46,     0,   -46,   -46,   -46,
       0,   -46,   -38,   -38,   -38,   -38,   -38,   -38,   -38,     0,
       0,   -38,   -38,     0,     0,     0,   -38,   -38,     0,     0,
       0,   -38,     0,     0,   -38,     0,     0,   385,     0,   -38,
       0,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,   -38,     0,     0,   -38,     0,
     386,   -38,   -38,     0,   -38,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,     0,     0,   -39,   -39,     0,     0,     0,   -39,
     -39,     0,   -39,     0,   -39,     0,     0,   -39,     0,     0,
     -39,     0,   -39,     0,   -39,   -39,   -39,   -39,   -39,     0,
     -39,   -39,   -39,   -39,   -39,   -39,     0,     0,   -39,     0,
       0,     0,     0,   -39,   -39,   -39,     0,   -39,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,     0,     0,   -41,   -41,     0,
       0,     0,   -41,   -41,     0,   -41,     0,   -41,     0,     0,
     -41,     0,     0,   -41,     0,   -41,     0,   -41,   -41,   -41,
     -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
       0,   -41,     0,     0,     0,     0,   -41,   -41,   -41,     0,
     -41,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
     -47,   -47,     0,     0,     0,   -47,   -47,     0,   -47,     0,
     -47,     0,     0,   -47,     0,     0,   -47,     0,   -47,     0,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,   -47,     0,     0,     0,     0,   -47,
     -47,   -47,     0,   -47,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,     0,     0,   -46,   -46,     0,     0,     0,   -46,   -46,
       0,   -46,     0,   -46,     0,     0,   -46,     0,     0,   -46,
       0,   -46,     0,   -46,   -46,   -46,   -46,   -46,     0,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,   -46,     0,     0,
       0,     0,   -46,   -46,   -46,     0,   -46,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,   -38,   -38,     0,     0,
       0,   -38,   -38,     0,   -38,     0,   -38,     0,     0,   -38,
       0,     0,   423,     0,   -38,     0,   -38,   -38,   -38,   -38,
     -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,
     -38,     0,     0,     0,     0,   424,   -38,   -38,     0,   -38,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,   -39,
     -39,     0,     0,     0,   -39,   -39,     0,     0,     0,   -39,
       0,     0,   -39,     0,     0,   -39,     0,   -39,     0,   -39,
     -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,   -39,     0,     0,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
       0,     0,   -41,   -41,     0,     0,     0,   -41,   -41,     0,
       0,     0,   -41,     0,     0,   -41,     0,     0,   -41,     0,
     -41,     0,   -41,   -41,   -41,   -41,   -41,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,   -41,     0,     0,     0,
       0,   -41,   -41,   -41,   -41,   -41,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,     0,     0,   -47,   -47,     0,     0,     0,
     -47,   -47,     0,     0,     0,   -47,     0,     0,   -47,     0,
       0,   -47,     0,   -47,     0,   -47,   -47,   -47,   -47,   -47,
       0,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,
       0,     0,     0,     0,   -47,   -47,   -47,   -47,   -47,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,
       0,     0,     0,   -46,   -46,     0,     0,     0,   -46,     0,
       0,   -46,     0,     0,   -46,     0,   -46,     0,   -46,   -46,
     -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,   -46,     0,     0,     0,     0,   -46,   -46,   -46,
     -46,   -46,   -38,   -38,   -38,   -38,   -38,   -38,   -38,     0,
       0,   -38,   -38,     0,     0,     0,   -38,   -38,     0,     0,
       0,   -38,     0,     0,   -38,     0,     0,   461,     0,   -38,
       0,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,   -38,     0,     0,     0,     0,
     462,   -38,   -38,   -38,   -38,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,     0,     0,   -39,   -39,     0,     0,     0,   -39,
     -39,     0,     0,     0,   -39,     0,     0,   -39,     0,     0,
     -39,     0,   -39,     0,   -39,   -39,   -39,   -39,   -39,     0,
     -39,   -39,   -39,   -39,   -39,   -39,     0,     0,   -39,   -39,
       0,     0,     0,   -39,   -39,   -39,     0,   -39,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,     0,     0,   -41,   -41,     0,
       0,     0,   -41,   -41,     0,     0,     0,   -41,     0,     0,
     -41,     0,     0,   -41,     0,   -41,     0,   -41,   -41,   -41,
     -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
       0,   -41,   -41,     0,     0,     0,   -41,   -41,   -41,     0,
     -41,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
     -47,   -47,     0,     0,     0,   -47,   -47,     0,     0,     0,
     -47,     0,     0,   -47,     0,     0,   -47,     0,   -47,     0,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,   -47,   -47,     0,     0,     0,   -47,
     -47,   -47,     0,   -47,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,     0,     0,   -46,   -46,     0,     0,     0,   -46,   -46,
       0,     0,     0,   -46,     0,     0,   -46,     0,     0,   -46,
       0,   -46,     0,   -46,   -46,   -46,   -46,   -46,     0,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,     0,
       0,     0,   -46,   -46,   -46,     0,   -46,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,   -38,   -38,     0,     0,
       0,   -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,
       0,     0,   503,     0,   -38,     0,   -38,   -38,   -38,   -38,
     -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,
     -38,   -38,     0,     0,     0,   504,   -38,   -38,     0,   -38,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,   -39,
     -39,     0,     0,     0,   -39,   -39,     0,     0,   -39,   -39,
       0,     0,   -39,     0,     0,   -39,     0,   -39,     0,   -39,
     -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,   -39,     0,     0,     0,     0,   -39,   -39,
     -39,     0,   -39,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
       0,     0,   -41,   -41,     0,     0,     0,   -41,   -41,     0,
       0,   -41,   -41,     0,     0,   -41,     0,     0,   -41,     0,
     -41,     0,   -41,   -41,   -41,   -41,   -41,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,   -41,     0,     0,     0,
       0,   -41,   -41,   -41,     0,   -41,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,     0,     0,   -47,   -47,     0,     0,     0,
     -47,   -47,     0,     0,   -47,   -47,     0,     0,   -47,     0,
       0,   -47,     0,   -47,     0,   -47,   -47,   -47,   -47,   -47,
       0,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,
       0,     0,     0,     0,   -47,   -47,   -47,     0,   -47,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,
       0,     0,     0,   -46,   -46,     0,     0,   -46,   -46,     0,
       0,   -46,     0,     0,   -46,     0,   -46,     0,   -46,   -46,
     -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,   -46,     0,     0,     0,     0,   -46,   -46,   -46,
       0,   -46,   -38,   -38,   -38,   -38,   -38,   -38,   -38,     0,
       0,   -38,   -38,     0,     0,     0,   -38,   -38,     0,     0,
     -38,   -38,     0,     0,   -38,     0,     0,   557,     0,   -38,
       0,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,   -38,     0,     0,     0,     0,
     558,   -38,   -38,     0,   -38,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,   -40,   -40,     0,     0,     0,   -40,
     -40,     0,     0,     0,   -40,     0,     0,   -40,     0,     0,
     -40,     0,   -40,     0,   -40,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   -40,   -40,   -40,   -40,     0,     0,   -40,     0,
       0,   -40,     0,   -40,   -40,   -40,     0,   -40,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,   -44,   -44,     0,
       0,     0,   -44,   -44,     0,     0,     0,   -44,     0,     0,
     -44,     0,     0,   -44,     0,   -44,     0,   -44,   -44,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,     0,
       0,   -44,     0,     0,   -44,     0,   -44,   -44,   -44,     0,
     -44,   -40,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,
     -40,   -40,     0,     0,     0,   -40,   -40,     0,   -40,     0,
     -40,     0,     0,   -40,     0,     0,   -40,     0,   -40,     0,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,   -40,     0,     0,     0,     0,   -40,
     -40,   -40,     0,   -40,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   -44,   -44,     0,     0,     0,   -44,   -44,
       0,   -44,     0,   -44,     0,     0,   -44,     0,     0,   -44,
       0,   -44,     0,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,   -44,     0,     0,
       0,     0,   -44,   -44,   -44,     0,   -44,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,     0,     0,   -40,   -40,     0,     0,
       0,   -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,
       0,     0,   -40,     0,   -40,     0,   -40,   -40,   -40,   -40,
     -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,
     -40,     0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,   -44,
     -44,     0,     0,     0,   -44,   -44,     0,     0,     0,   -44,
       0,     0,   -44,     0,     0,   -44,     0,   -44,     0,   -44,
     -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   -44,     0,     0,     0,     0,   -44,   -44,
     -44,   -44,   -44,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,   -40,   -40,     0,     0,     0,   -40,   -40,     0,
       0,     0,   -40,     0,     0,   -40,     0,     0,   -40,     0,
     -40,     0,   -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,     0,   -40,   -40,     0,     0,
       0,   -40,   -40,   -40,     0,   -40,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,   -44,   -44,     0,     0,     0,
     -44,   -44,     0,     0,     0,   -44,     0,     0,   -44,     0,
       0,   -44,     0,   -44,     0,   -44,   -44,   -44,   -44,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,   -44,
     -44,     0,     0,     0,   -44,   -44,   -44,     0,   -44,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,     0,     0,   -40,   -40,
       0,     0,     0,   -40,   -40,     0,     0,   -40,   -40,     0,
       0,   -40,     0,     0,   -40,     0,   -40,     0,   -40,   -40,
     -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,   -40,     0,     0,     0,     0,   -40,   -40,   -40,
       0,   -40,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,
       0,   -44,   -44,     0,     0,     0,   -44,   -44,     0,     0,
     -44,   -44,     0,     0,   -44,     0,     0,   -44,     0,   -44,
       0,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,   -44,     0,     0,     0,     0,
     -44,   -44,   -44,     0,   -44,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,     0,     0,   -43,   -43,     0,     0,     0,   -43,
     -43,     0,     0,     0,   -43,     0,     0,   -43,     0,     0,
     -43,     0,   -43,     0,   -43,   -43,   -43,   -43,   -43,     0,
     -43,   -43,   -43,   -43,   -43,   -43,     0,     0,   -43,     0,
       0,   -43,     0,   -43,   -43,   -43,     0,   -43,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,     0,     0,   -50,   -50,     0,
       0,     0,   -50,   -50,     0,     0,     0,   -50,     0,     0,
     -50,     0,     0,   -50,     0,   -50,     0,   -50,   -50,   -50,
     -50,   -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,     0,
       0,   -50,     0,     0,   -50,     0,   -50,   -50,   -50,     0,
     -50,   -42,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,
     -42,   -42,     0,     0,     0,   -42,   -42,     0,     0,     0,
     -42,     0,     0,   -42,     0,     0,   -42,     0,   -42,     0,
     -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,
     -42,   -42,     0,     0,   -42,     0,     0,   -42,     0,   -42,
     -42,   -42,     0,   -42,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,     0,     0,   -48,   -48,     0,     0,     0,   -48,   -48,
       0,     0,     0,   -48,     0,     0,   -48,     0,     0,   -48,
       0,   -48,     0,   -48,   -48,   -48,   -48,   -48,     0,   -48,
     -48,   -48,   -48,   -48,   -48,     0,     0,   -48,     0,     0,
     -48,     0,   -48,   -48,   -48,     0,   -48,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,   -51,   -51,     0,     0,
       0,   -51,   -51,     0,     0,     0,   -51,     0,     0,   -51,
       0,     0,   -51,     0,   -51,     0,   -51,   -51,   -51,   -51,
     -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,
     -51,     0,     0,   -51,     0,   -51,   -51,   -51,     0,   -51,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,   -75,
     -75,     0,     0,     0,   -75,   -75,     0,     0,     0,   -75,
       0,     0,   -75,     0,     0,   -75,     0,   -75,     0,   -75,
     -75,   -75,   -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,
     -75,     0,     0,   -75,     0,     0,   -75,     0,   -75,   -75,
     -75,     0,   -75,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
       0,     0,   -76,   -76,     0,     0,     0,   -76,   -76,     0,
       0,     0,   -76,     0,     0,   -76,     0,     0,   -76,     0,
     -76,     0,   -76,   -76,   -76,   -76,   -76,     0,   -76,   -76,
     -76,   -76,   -76,   -76,     0,     0,   -76,     0,     0,   -76,
       0,   -76,   -76,   -76,     0,   -76,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,     0,     0,   -35,   -35,     0,     0,     0,
     -35,   -35,     0,     0,     0,   -35,     0,     0,   -35,     0,
       0,   902,     0,   -35,     0,   -35,   -35,   -35,   -35,   -35,
       0,   -35,   -35,   -35,   -35,   -35,   -35,     0,     0,   -35,
       0,     0,   -35,     0,   903,   -35,   -35,     0,   -35,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,   -73,   -73,
       0,     0,     0,   -73,   -73,     0,     0,     0,   -73,     0,
       0,   -73,     0,     0,   -73,     0,   -73,     0,   -73,   -73,
     -73,   -73,   -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,
       0,     0,   -73,     0,     0,   -73,     0,   -73,   -73,   -73,
       0,   -73,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,
       0,   -74,   -74,     0,     0,     0,   -74,   -74,     0,     0,
       0,   -74,     0,     0,   -74,     0,     0,   -74,     0,   -74,
       0,   -74,   -74,   -74,   -74,   -74,     0,   -74,   -74,   -74,
     -74,   -74,   -74,     0,     0,   -74,     0,     0,   -74,     0,
     -74,   -74,   -74,     0,   -74,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,   -45,   -45,     0,     0,     0,   -45,
     -45,     0,     0,     0,   -45,     0,     0,   -45,     0,     0,
     -45,     0,   -45,     0,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,   -45,   -45,   -45,   -45,     0,     0,   -45,     0,
       0,   -45,     0,   -45,   -45,   -45,     0,   -45,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,     0,     0,   -43,   -43,     0,
       0,     0,   -43,   -43,     0,   -43,     0,   -43,     0,     0,
     -43,     0,     0,   -43,     0,   -43,     0,   -43,   -43,   -43,
     -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,
       0,   -43,     0,     0,     0,     0,   -43,   -43,   -43,     0,
     -43,   -50,   -50,   -50,   -50,   -50,   -50,   -50,     0,     0,
     -50,   -50,     0,     0,     0,   -50,   -50,     0,   -50,     0,
     -50,     0,     0,   -50,     0,     0,   -50,     0,   -50,     0,
     -50,   -50,   -50,   -50,   -50,     0,   -50,   -50,   -50,   -50,
     -50,   -50,     0,     0,   -50,     0,     0,     0,     0,   -50,
     -50,   -50,     0,   -50,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,     0,     0,   -42,   -42,     0,     0,     0,   -42,   -42,
       0,   -42,     0,   -42,     0,     0,   -42,     0,     0,   -42,
       0,   -42,     0,   -42,   -42,   -42,   -42,   -42,     0,   -42,
     -42,   -42,   -42,   -42,   -42,     0,     0,   -42,     0,     0,
       0,     0,   -42,   -42,   -42,     0,   -42,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,     0,     0,   -48,   -48,     0,     0,
       0,   -48,   -48,     0,   -48,     0,   -48,     0,     0,   -48,
       0,     0,   -48,     0,   -48,     0,   -48,   -48,   -48,   -48,
     -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
     -48,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,   -51,
     -51,     0,     0,     0,   -51,   -51,     0,   -51,     0,   -51,
       0,     0,   -51,     0,     0,   -51,     0,   -51,     0,   -51,
     -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,   -51,
     -51,     0,     0,   -51,     0,     0,     0,     0,   -51,   -51,
     -51,     0,   -51,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
       0,     0,   -75,   -75,     0,     0,     0,   -75,   -75,     0,
     -75,     0,   -75,     0,     0,   -75,     0,     0,   -75,     0,
     -75,     0,   -75,   -75,   -75,   -75,   -75,     0,   -75,   -75,
     -75,   -75,   -75,   -75,     0,     0,   -75,     0,     0,     0,
       0,   -75,   -75,   -75,     0,   -75,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,   -76,   -76,     0,     0,     0,
     -76,   -76,     0,   -76,     0,   -76,     0,     0,   -76,     0,
       0,   -76,     0,   -76,     0,   -76,   -76,   -76,   -76,   -76,
       0,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,   -76,
       0,     0,     0,     0,   -76,   -76,   -76,     0,   -76,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,     0,     0,   -35,   -35,
       0,     0,     0,   -35,   -35,     0,   -35,     0,   -35,     0,
       0,   -35,     0,     0,   917,     0,   -35,     0,   -35,   -35,
     -35,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,
       0,     0,   -35,     0,     0,     0,     0,   918,   -35,   -35,
       0,   -35,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,
       0,   -73,   -73,     0,     0,     0,   -73,   -73,     0,   -73,
       0,   -73,     0,     0,   -73,     0,     0,   -73,     0,   -73,
       0,   -73,   -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,
     -73,   -73,   -73,     0,     0,   -73,     0,     0,     0,     0,
     -73,   -73,   -73,     0,   -73,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,   -74,   -74,     0,     0,     0,   -74,
     -74,     0,   -74,     0,   -74,     0,     0,   -74,     0,     0,
     -74,     0,   -74,     0,   -74,   -74,   -74,   -74,   -74,     0,
     -74,   -74,   -74,   -74,   -74,   -74,     0,     0,   -74,     0,
       0,     0,     0,   -74,   -74,   -74,     0,   -74,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,   -45,   -45,     0,
       0,     0,   -45,   -45,     0,   -45,     0,   -45,     0,     0,
     -45,     0,     0,   -45,     0,   -45,     0,   -45,   -45,   -45,
     -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,
       0,   -45,     0,     0,     0,     0,   -45,   -45,   -45,     0,
     -45,   -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
     -43,   -43,     0,     0,     0,   -43,   -43,     0,     0,     0,
     -43,     0,     0,   -43,     0,     0,   -43,     0,   -43,     0,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,
     -43,   -43,     0,     0,   -43,     0,     0,     0,     0,   -43,
     -43,   -43,   -43,   -43,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,     0,     0,   -50,   -50,     0,     0,     0,   -50,   -50,
       0,     0,     0,   -50,     0,     0,   -50,     0,     0,   -50,
       0,   -50,     0,   -50,   -50,   -50,   -50,   -50,     0,   -50,
     -50,   -50,   -50,   -50,   -50,     0,     0,   -50,     0,     0,
       0,     0,   -50,   -50,   -50,   -50,   -50,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,   -42,   -42,     0,     0,
       0,   -42,   -42,     0,     0,     0,   -42,     0,     0,   -42,
       0,     0,   -42,     0,   -42,     0,   -42,   -42,   -42,   -42,
     -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,
     -42,     0,     0,     0,     0,   -42,   -42,   -42,   -42,   -42,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,   -48,
     -48,     0,     0,     0,   -48,   -48,     0,     0,     0,   -48,
       0,     0,   -48,     0,     0,   -48,     0,   -48,     0,   -48,
     -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,   -48,
     -48,     0,     0,   -48,     0,     0,     0,     0,   -48,   -48,
     -48,   -48,   -48,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
       0,     0,   -51,   -51,     0,     0,     0,   -51,   -51,     0,
       0,     0,   -51,     0,     0,   -51,     0,     0,   -51,     0,
     -51,     0,   -51,   -51,   -51,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,   -51,     0,     0,     0,
       0,   -51,   -51,   -51,   -51,   -51,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     0,     0,   -75,   -75,     0,     0,     0,
     -75,   -75,     0,     0,     0,   -75,     0,     0,   -75,     0,
       0,   -75,     0,   -75,     0,   -75,   -75,   -75,   -75,   -75,
       0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,   -75,
       0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,     0,     0,   -76,   -76,
       0,     0,     0,   -76,   -76,     0,     0,     0,   -76,     0,
       0,   -76,     0,     0,   -76,     0,   -76,     0,   -76,   -76,
     -76,   -76,   -76,     0,   -76,   -76,   -76,   -76,   -76,   -76,
       0,     0,   -76,     0,     0,     0,     0,   -76,   -76,   -76,
     -76,   -76,   -35,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,   -35,   -35,     0,     0,     0,   -35,   -35,     0,     0,
       0,   -35,     0,     0,   -35,     0,     0,   932,     0,   -35,
       0,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,   -35,
     -35,   -35,   -35,     0,     0,   -35,     0,     0,     0,     0,
     933,   -35,   -35,   -35,   -35,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,     0,     0,   -73,   -73,     0,     0,     0,   -73,
     -73,     0,     0,     0,   -73,     0,     0,   -73,     0,     0,
     -73,     0,   -73,     0,   -73,   -73,   -73,   -73,   -73,     0,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,   -73,     0,
       0,     0,     0,   -73,   -73,   -73,   -73,   -73,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,     0,     0,   -74,   -74,     0,
       0,     0,   -74,   -74,     0,     0,     0,   -74,     0,     0,
     -74,     0,     0,   -74,     0,   -74,     0,   -74,   -74,   -74,
     -74,   -74,     0,   -74,   -74,   -74,   -74,   -74,   -74,     0,
       0,   -74,     0,     0,     0,     0,   -74,   -74,   -74,   -74,
     -74,   -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
     -45,   -45,     0,     0,     0,   -45,   -45,     0,     0,     0,
     -45,     0,     0,   -45,     0,     0,   -45,     0,   -45,     0,
     -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,   -45,     0,     0,     0,     0,   -45,
     -45,   -45,   -45,   -45,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,     0,     0,   -43,   -43,     0,     0,     0,   -43,   -43,
       0,     0,     0,   -43,     0,     0,   -43,     0,     0,   -43,
       0,   -43,     0,   -43,   -43,   -43,   -43,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,     0,   -43,   -43,     0,
       0,     0,   -43,   -43,   -43,     0,   -43,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,   -50,   -50,     0,     0,
       0,   -50,   -50,     0,     0,     0,   -50,     0,     0,   -50,
       0,     0,   -50,     0,   -50,     0,   -50,   -50,   -50,   -50,
     -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,     0,     0,
     -50,   -50,     0,     0,     0,   -50,   -50,   -50,     0,   -50,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,   -42,
     -42,     0,     0,     0,   -42,   -42,     0,     0,     0,   -42,
       0,     0,   -42,     0,     0,   -42,     0,   -42,     0,   -42,
     -42,   -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,
     -42,     0,     0,   -42,   -42,     0,     0,     0,   -42,   -42,
     -42,     0,   -42,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,   -48,   -48,     0,     0,     0,   -48,   -48,     0,
       0,     0,   -48,     0,     0,   -48,     0,     0,   -48,     0,
     -48,     0,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
     -48,   -48,   -48,   -48,     0,     0,   -48,   -48,     0,     0,
       0,   -48,   -48,   -48,     0,   -48,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,     0,     0,   -51,   -51,     0,     0,     0,
     -51,   -51,     0,     0,     0,   -51,     0,     0,   -51,     0,
       0,   -51,     0,   -51,     0,   -51,   -51,   -51,   -51,   -51,
       0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,   -51,
     -51,     0,     0,     0,   -51,   -51,   -51,     0,   -51,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,     0,     0,   -75,   -75,
       0,     0,     0,   -75,   -75,     0,     0,     0,   -75,     0,
       0,   -75,     0,     0,   -75,     0,   -75,     0,   -75,   -75,
     -75,   -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,
       0,     0,   -75,   -75,     0,     0,     0,   -75,   -75,   -75,
       0,   -75,   -76,   -76,   -76,   -76,   -76,   -76,   -76,     0,
       0,   -76,   -76,     0,     0,     0,   -76,   -76,     0,     0,
       0,   -76,     0,     0,   -76,     0,     0,   -76,     0,   -76,
       0,   -76,   -76,   -76,   -76,   -76,     0,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,   -76,   -76,     0,     0,     0,
     -76,   -76,   -76,     0,   -76,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,     0,     0,   -35,   -35,     0,     0,     0,   -35,
     -35,     0,     0,     0,   -35,     0,     0,   -35,     0,     0,
     949,     0,   -35,     0,   -35,   -35,   -35,   -35,   -35,     0,
     -35,   -35,   -35,   -35,   -35,   -35,     0,     0,   -35,   -35,
       0,     0,     0,   950,   -35,   -35,     0,   -35,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,     0,     0,   -73,   -73,     0,
       0,     0,   -73,   -73,     0,     0,     0,   -73,     0,     0,
     -73,     0,     0,   -73,     0,   -73,     0,   -73,   -73,   -73,
     -73,   -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,     0,
       0,   -73,   -73,     0,     0,     0,   -73,   -73,   -73,     0,
     -73,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,
     -74,   -74,     0,     0,     0,   -74,   -74,     0,     0,     0,
     -74,     0,     0,   -74,     0,     0,   -74,     0,   -74,     0,
     -74,   -74,   -74,   -74,   -74,     0,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,   -74,   -74,     0,     0,     0,   -74,
     -74,   -74,     0,   -74,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,     0,     0,   -45,   -45,     0,     0,     0,   -45,   -45,
       0,     0,     0,   -45,     0,     0,   -45,     0,     0,   -45,
       0,   -45,     0,   -45,   -45,   -45,   -45,   -45,     0,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,   -45,   -45,     0,
       0,     0,   -45,   -45,   -45,     0,   -45,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,   -43,   -43,     0,     0,
       0,   -43,   -43,     0,     0,   -43,   -43,     0,     0,   -43,
       0,     0,   -43,     0,   -43,     0,   -43,   -43,   -43,   -43,
     -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
     -43,     0,     0,     0,     0,   -43,   -43,   -43,     0,   -43,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,     0,     0,   -50,
     -50,     0,     0,     0,   -50,   -50,     0,     0,   -50,   -50,
       0,     0,   -50,     0,     0,   -50,     0,   -50,     0,   -50,
     -50,   -50,   -50,   -50,     0,   -50,   -50,   -50,   -50,   -50,
     -50,     0,     0,   -50,     0,     0,     0,     0,   -50,   -50,
     -50,     0,   -50,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
       0,     0,   -42,   -42,     0,     0,     0,   -42,   -42,     0,
       0,   -42,   -42,     0,     0,   -42,     0,     0,   -42,     0,
     -42,     0,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,   -42,     0,     0,     0,
       0,   -42,   -42,   -42,     0,   -42,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,   -48,   -48,     0,     0,     0,
     -48,   -48,     0,     0,   -48,   -48,     0,     0,   -48,     0,
       0,   -48,     0,   -48,     0,   -48,   -48,   -48,   -48,   -48,
       0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,   -48,
       0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,     0,     0,   -51,   -51,
       0,     0,     0,   -51,   -51,     0,     0,   -51,   -51,     0,
       0,   -51,     0,     0,   -51,     0,   -51,     0,   -51,   -51,
     -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,
       0,     0,   -51,     0,     0,     0,     0,   -51,   -51,   -51,
       0,   -51,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,
       0,   -75,   -75,     0,     0,     0,   -75,   -75,     0,     0,
     -75,   -75,     0,     0,   -75,     0,     0,   -75,     0,   -75,
       0,   -75,   -75,   -75,   -75,   -75,     0,   -75,   -75,   -75,
     -75,   -75,   -75,     0,     0,   -75,     0,     0,     0,     0,
     -75,   -75,   -75,     0,   -75,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,     0,     0,   -76,   -76,     0,     0,     0,   -76,
     -76,     0,     0,   -76,   -76,     0,     0,   -76,     0,     0,
     -76,     0,   -76,     0,   -76,   -76,   -76,   -76,   -76,     0,
     -76,   -76,   -76,   -76,   -76,   -76,     0,     0,   -76,     0,
       0,     0,     0,   -76,   -76,   -76,     0,   -76,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,   -35,   -35,     0,
       0,     0,   -35,   -35,     0,     0,   -35,   -35,     0,     0,
     -35,     0,     0,   969,     0,   -35,     0,   -35,   -35,   -35,
     -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,   -35,     0,     0,     0,     0,   970,   -35,   -35,     0,
     -35,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
     -73,   -73,     0,     0,     0,   -73,   -73,     0,     0,   -73,
     -73,     0,     0,   -73,     0,     0,   -73,     0,   -73,     0,
     -73,   -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,   -73,
     -73,   -73,     0,     0,   -73,     0,     0,     0,     0,   -73,
     -73,   -73,     0,   -73,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,     0,   -74,   -74,     0,     0,     0,   -74,   -74,
       0,     0,   -74,   -74,     0,     0,   -74,     0,     0,   -74,
       0,   -74,     0,   -74,   -74,   -74,   -74,   -74,     0,   -74,
     -74,   -74,   -74,   -74,   -74,     0,     0,   -74,     0,     0,
       0,     0,   -74,   -74,   -74,     0,   -74,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,     0,     0,   -45,   -45,     0,     0,
       0,   -45,   -45,     0,     0,   -45,   -45,     0,     0,   -45,
       0,     0,   -45,     0,   -45,     0,   -45,   -45,   -45,   -45,
     -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
     -45,     0,     0,     0,     0,   -45,   -45,   -45,     0,   -45,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,   -49,
     -49,     0,     0,     0,   -49,   -49,     0,     0,     0,   -49,
       0,     0,   -49,     0,     0,   -49,     0,   -49,     0,   -49,
     -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,
     -49,     0,     0,   -49,     0,     0,   -49,     0,   -49,   -49,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,   -49,   -49,     0,     0,     0,   -49,   -49,     0,
     -49,     0,   -49,     0,     0,   -49,     0,     0,   -49,     0,
     -49,     0,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,
     -49,   -49,   -49,   -49,     0,     0,   -49,     0,     0,     0,
       0,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,   -49,   -49,     0,     0,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,     0,
       0,   -49,     0,   -49,     0,   -49,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,   -49,
       0,     0,     0,     0,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,     0,     0,   -49,   -49,
       0,     0,     0,   -49,   -49,     0,     0,     0,   -49,     0,
       0,   -49,     0,     0,   -49,     0,   -49,     0,   -49,   -49,
     -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,   -49,   -49,     0,     0,     0,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,   -49,   -49,     0,     0,     0,   -49,   -49,     0,     0,
     -49,   -49,     0,     0,   -49,     0,     0,   -49,     0,   -49,
       0,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,   -49,     0,     0,     0,     0,
     -49,   -49,   -49,     0,   -49,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,     0,     0,   -78,   -78,     0,     0,     0,   -78,
     -78,     0,     0,     0,   -78,     0,     0,   -78,     0,     0,
     -78,     0,   -78,     0,   -78,   -78,   -78,   -78,   -78,     0,
     -78,   -78,   -78,   -78,   -78,   -78,     0,     0,   -78,     0,
       0,   -78,     0,   -78,   -78,   -78,     0,   -78,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,     0,     0,   -77,   -77,     0,
       0,     0,   -77,   -77,     0,     0,     0,   -77,     0,     0,
     -77,     0,     0,   -77,     0,   -77,     0,   -77,   -77,   -77,
     -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,   -77,     0,
       0,   -77,     0,     0,   -77,     0,   -77,   -77,   -77,     0,
     -77,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
     -71,   -71,     0,     0,     0,   -71,   -71,     0,     0,     0,
     -71,     0,     0,   -71,     0,     0,   -71,     0,   -71,     0,
     -71,   -71,   -71,   -71,   -71,     0,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,   -71,     0,     0,   -71,     0,   -71,
     -71,   -71,     0,   -71,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,   -72,   -72,     0,     0,     0,   -72,   -72,
       0,     0,     0,   -72,     0,     0,   -72,     0,     0,   -72,
       0,   -72,     0,   -72,   -72,   -72,   -72,   -72,     0,   -72,
     -72,   -72,   -72,   -72,   -72,     0,     0,   -72,     0,     0,
     -72,     0,   -72,   -72,   -72,     0,   -72,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,   -78,   -78,     0,     0,
       0,   -78,   -78,     0,   -78,     0,   -78,     0,     0,   -78,
       0,     0,   -78,     0,   -78,     0,   -78,   -78,   -78,   -78,
     -78,     0,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
     -78,     0,     0,     0,     0,   -78,   -78,   -78,     0,   -78,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,   -77,
     -77,     0,     0,     0,   -77,   -77,     0,   -77,     0,   -77,
       0,     0,   -77,     0,     0,   -77,     0,   -77,     0,   -77,
     -77,   -77,   -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,
     -77,     0,     0,   -77,     0,     0,     0,     0,   -77,   -77,
     -77,     0,   -77,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,   -71,   -71,     0,     0,     0,   -71,   -71,     0,
     -71,     0,   -71,     0,     0,   -71,     0,     0,   -71,     0,
     -71,     0,   -71,   -71,   -71,   -71,   -71,     0,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,   -71,     0,     0,     0,
       0,   -71,   -71,   -71,     0,   -71,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,   -72,   -72,     0,     0,     0,
     -72,   -72,     0,   -72,     0,   -72,     0,     0,   -72,     0,
       0,   -72,     0,   -72,     0,   -72,   -72,   -72,   -72,   -72,
       0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,   -72,
       0,     0,     0,     0,   -72,   -72,   -72,     0,   -72,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,     0,     0,   -78,   -78,
       0,     0,     0,   -78,   -78,     0,     0,     0,   -78,     0,
       0,   -78,     0,     0,   -78,     0,   -78,     0,   -78,   -78,
     -78,   -78,   -78,     0,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,   -78,     0,     0,     0,     0,   -78,   -78,   -78,
     -78,   -78,   -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,
       0,   -77,   -77,     0,     0,     0,   -77,   -77,     0,     0,
       0,   -77,     0,     0,   -77,     0,     0,   -77,     0,   -77,
       0,   -77,   -77,   -77,   -77,   -77,     0,   -77,   -77,   -77,
     -77,   -77,   -77,     0,     0,   -77,     0,     0,     0,     0,
     -77,   -77,   -77,   -77,   -77,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,   -71,   -71,     0,     0,     0,   -71,
     -71,     0,     0,     0,   -71,     0,     0,   -71,     0,     0,
     -71,     0,   -71,     0,   -71,   -71,   -71,   -71,   -71,     0,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   -71,     0,
       0,     0,     0,   -71,   -71,   -71,   -71,   -71,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,     0,     0,   -72,   -72,     0,
       0,     0,   -72,   -72,     0,     0,     0,   -72,     0,     0,
     -72,     0,     0,   -72,     0,   -72,     0,   -72,   -72,   -72,
     -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,   -72,     0,
       0,   -72,     0,     0,     0,     0,   -72,   -72,   -72,   -72,
     -72,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
     -78,   -78,     0,     0,     0,   -78,   -78,     0,     0,     0,
     -78,     0,     0,   -78,     0,     0,   -78,     0,   -78,     0,
     -78,   -78,   -78,   -78,   -78,     0,   -78,   -78,   -78,   -78,
     -78,   -78,     0,     0,   -78,   -78,     0,     0,     0,   -78,
     -78,   -78,     0,   -78,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,     0,     0,   -77,   -77,     0,     0,     0,   -77,   -77,
       0,     0,     0,   -77,     0,     0,   -77,     0,     0,   -77,
       0,   -77,     0,   -77,   -77,   -77,   -77,   -77,     0,   -77,
     -77,   -77,   -77,   -77,   -77,     0,     0,   -77,   -77,     0,
       0,     0,   -77,   -77,   -77,     0,   -77,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,   -71,   -71,     0,     0,
       0,   -71,   -71,     0,     0,     0,   -71,     0,     0,   -71,
       0,     0,   -71,     0,   -71,     0,   -71,   -71,   -71,   -71,
     -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
     -71,   -71,     0,     0,     0,   -71,   -71,   -71,     0,   -71,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,   -72,
     -72,     0,     0,     0,   -72,   -72,     0,     0,     0,   -72,
       0,     0,   -72,     0,     0,   -72,     0,   -72,     0,   -72,
     -72,   -72,   -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,   -72,   -72,     0,     0,     0,   -72,   -72,
     -72,     0,   -72,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,   -78,   -78,     0,     0,     0,   -78,   -78,     0,
       0,   -78,   -78,     0,     0,   -78,     0,     0,   -78,     0,
     -78,     0,   -78,   -78,   -78,   -78,   -78,     0,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,   -78,     0,     0,     0,
       0,   -78,   -78,   -78,     0,   -78,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,     0,     0,   -77,   -77,     0,     0,     0,
     -77,   -77,     0,     0,   -77,   -77,     0,     0,   -77,     0,
       0,   -77,     0,   -77,     0,   -77,   -77,   -77,   -77,   -77,
       0,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,   -77,
       0,     0,     0,     0,   -77,   -77,   -77,     0,   -77,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   -71,   -71,
       0,     0,     0,   -71,   -71,     0,     0,   -71,   -71,     0,
       0,   -71,     0,     0,   -71,     0,   -71,     0,   -71,   -71,
     -71,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,   -71,     0,     0,     0,     0,   -71,   -71,   -71,
       0,   -71,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,
       0,   -72,   -72,     0,     0,     0,   -72,   -72,     0,     0,
     -72,   -72,     0,     0,   -72,     0,     0,   -72,     0,   -72,
       0,   -72,   -72,   -72,   -72,   -72,     0,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,   -72,     0,     0,     0,     0,
     -72,   -72,   -72,     0,   -72,   170,   171,   359,     4,     5,
     173,   174,     0,     0,   -32,   -32,     0,     0,     0,   -32,
     -32,     0,     0,     0,   -32,     0,     0,   177,     0,     0,
       0,     0,   179,     0,   -32,   -32,   -32,   -32,   -32,     0,
     -32,   -32,   -32,   -32,   -32,   -32,     0,     0,   360,     0,
       0,   -32,     0,     0,   184,   185,     0,   186,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,     0,     0,   -34,   -34,     0,
       0,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
     -34,     0,     0,     0,     0,   -34,     0,   -34,   -34,   -34,
     -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,
       0,   -34,     0,     0,   -34,     0,     0,   -34,   -34,     0,
     -34,   194,   195,   397,     4,     5,   197,   198,     0,     0,
     -32,   -32,     0,     0,     0,   -32,   -32,     0,   -32,     0,
     -32,     0,     0,   201,     0,     0,     0,     0,   203,     0,
     -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,   -32,
     -32,   -32,     0,     0,   398,     0,     0,     0,     0,     0,
     208,   209,     0,   210,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,   -34,   -34,     0,     0,     0,   -34,   -34,
       0,   -34,     0,   -34,     0,     0,   -34,     0,     0,     0,
       0,   -34,     0,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,   -34,   -34,   -34,   -34,     0,     0,   -34,     0,     0,
       0,     0,     0,   -34,   -34,     0,   -34,   218,   219,   435,
       4,     5,   221,   222,     0,     0,   -32,   -32,     0,     0,
       0,   -32,   -32,     0,     0,     0,   -32,     0,     0,   225,
       0,     0,     0,     0,   227,     0,   -32,   -32,   -32,   -32,
     -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,     0,     0,
     436,     0,     0,     0,     0,     0,   232,   233,   -32,   234,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,     0,   -34,
     -34,     0,     0,     0,   -34,   -34,     0,     0,     0,   -34,
       0,     0,   -34,     0,     0,     0,     0,   -34,     0,   -34,
     -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,   -34,     0,     0,     0,     0,     0,   -34,
     -34,   -34,   -34,   245,   246,   477,     4,     5,   248,   249,
       0,     0,   -32,   -32,     0,     0,     0,   -32,   -32,     0,
       0,     0,   -32,     0,     0,   252,     0,     0,     0,     0,
     254,     0,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,     0,   478,   -32,     0,     0,
       0,     0,   259,   260,     0,   261,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,     0,     0,   -34,   -34,     0,     0,     0,
     -34,   -34,     0,     0,     0,   -34,     0,     0,   -34,     0,
       0,     0,     0,   -34,     0,   -34,   -34,   -34,   -34,   -34,
       0,   -34,   -34,   -34,   -34,   -34,   -34,     0,     0,   -34,
     -34,     0,     0,     0,     0,   -34,   -34,     0,   -34,   297,
     298,   531,     4,     5,   300,   301,     0,     0,   -32,   -32,
       0,     0,     0,   -32,   -32,     0,     0,   -32,   -32,     0,
       0,   304,     0,     0,     0,     0,   306,     0,   -32,   -32,
     -32,   -32,   -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,
       0,     0,   532,     0,     0,     0,     0,     0,   311,   312,
       0,   313,   -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,
       0,   -34,   -34,     0,     0,     0,   -34,   -34,     0,     0,
     -34,   -34,     0,     0,   -34,     0,     0,     0,     0,   -34,
       0,   -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,     0,   -34,     0,     0,     0,     0,
       0,   -34,   -34,     0,   -34,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,     0,     0,   -33,   -33,     0,     0,     0,   -33,
     -33,     0,     0,     0,   -33,     0,     0,   -33,     0,     0,
       0,     0,   -33,     0,   -33,   -33,   -33,   -33,   -33,     0,
     -33,   -33,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,
       0,   -33,     0,     0,   -33,   -33,     0,   -33,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,   -37,   -37,     0,
       0,     0,   -37,   -37,     0,     0,     0,   -37,     0,     0,
     -37,     0,     0,     0,     0,   -37,     0,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,   -37,     0,     0,   -37,     0,     0,   -37,   -37,     0,
     -37,   -33,   -33,   -33,   -33,   -33,   -33,   -33,     0,     0,
     -33,   -33,     0,     0,     0,   -33,   -33,     0,   -33,     0,
     -33,     0,     0,   -33,     0,     0,     0,     0,   -33,     0,
     -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,   -33,   -33,
     -33,   -33,     0,     0,   -33,     0,     0,     0,     0,     0,
     -33,   -33,     0,   -33,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,     0,     0,   -37,   -37,     0,     0,     0,   -37,   -37,
       0,   -37,     0,   -37,     0,     0,   -37,     0,     0,     0,
       0,   -37,     0,   -37,   -37,   -37,   -37,   -37,     0,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,   -37,     0,     0,
       0,     0,     0,   -37,   -37,     0,   -37,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,     0,     0,   -33,   -33,     0,     0,
       0,   -33,   -33,     0,     0,     0,   -33,     0,     0,   -33,
       0,     0,     0,     0,   -33,     0,   -33,   -33,   -33,   -33,
     -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,     0,
     -33,     0,     0,     0,     0,     0,   -33,   -33,   -33,   -33,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,   -37,
     -37,     0,     0,     0,   -37,   -37,     0,     0,     0,   -37,
       0,     0,   -37,     0,     0,     0,     0,   -37,     0,   -37,
     -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,
     -37,     0,     0,   -37,     0,     0,     0,     0,     0,   -37,
     -37,   -37,   -37,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
       0,     0,   -33,   -33,     0,     0,     0,   -33,   -33,     0,
       0,     0,   -33,     0,     0,   -33,     0,     0,     0,     0,
     -33,     0,   -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,
     -33,   -33,   -33,   -33,     0,     0,   -33,   -33,     0,     0,
       0,     0,   -33,   -33,     0,   -33,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,     0,     0,   -37,   -37,     0,     0,     0,
     -37,   -37,     0,     0,     0,   -37,     0,     0,   -37,     0,
       0,     0,     0,   -37,     0,   -37,   -37,   -37,   -37,   -37,
       0,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,   -37,
     -37,     0,     0,     0,     0,   -37,   -37,     0,   -37,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,     0,     0,   -33,   -33,
       0,     0,     0,   -33,   -33,     0,     0,   -33,   -33,     0,
       0,   -33,     0,     0,     0,     0,   -33,     0,   -33,   -33,
     -33,   -33,   -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,
       0,     0,   -33,     0,     0,     0,     0,     0,   -33,   -33,
       0,   -33,   -37,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,   -37,   -37,     0,     0,     0,   -37,   -37,     0,     0,
     -37,   -37,     0,     0,   -37,     0,     0,     0,     0,   -37,
       0,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,
     -37,   -37,   -37,     0,     0,   -37,     0,     0,     0,     0,
       0,   -37,   -37,     0,   -37,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,     0,     0,   -36,   -36,     0,     0,     0,   -36,
     -36,     0,     0,     0,   -36,     0,     0,   -36,     0,     0,
       0,     0,   -36,     0,   -36,   -36,   -36,   -36,   -36,     0,
     -36,   -36,   -36,   -36,   -36,   -36,     0,     0,   -36,     0,
       0,   -36,     0,     0,   -36,   -36,     0,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,     0,     0,   -36,   -36,     0,
       0,     0,   -36,   -36,     0,   -36,     0,   -36,     0,     0,
     -36,     0,     0,     0,     0,   -36,     0,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,
       0,   -36,     0,     0,     0,     0,     0,   -36,   -36,     0,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,
     -36,   -36,     0,     0,     0,   -36,   -36,     0,     0,     0,
     -36,     0,     0,   -36,     0,     0,     0,     0,   -36,     0,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,     0,   -36,     0,     0,     0,     0,     0,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,     0,     0,   -36,   -36,     0,     0,     0,   -36,   -36,
       0,     0,     0,   -36,     0,     0,   -36,     0,     0,     0,
       0,   -36,     0,   -36,   -36,   -36,   -36,   -36,     0,   -36,
     -36,   -36,   -36,   -36,   -36,     0,     0,   -36,   -36,     0,
       0,     0,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,   -36,   -36,     0,     0,
       0,   -36,   -36,     0,     0,   -36,   -36,     0,     0,   -36,
       0,     0,     0,     0,   -36,     0,   -36,   -36,   -36,   -36,
     -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,
     -36,     0,     0,     0,     0,     0,   -36,   -36,     0,   -36,
     297,   298,   531,     4,     5,   300,   301,     0,   321,   322,
     569,     4,     5,   324,   325,     0,     0,     0,     0,     0,
       0,     0,   304,     0,     0,     0,     0,   306,     0,     0,
     328,     0,     0,     0,     0,   330,   308,     0,     0,     0,
       0,     0,     0,   532,   332,     0,     0,   310,     0,   311,
     312,   570,   313,     0,     0,   334,     0,   335,   336,     0,
     337,   245,   246,   477,     4,     5,   248,   249,     0,   269,
     270,   271,     4,     5,   272,   273,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,   254,     0,
       0,   274,     0,     0,     0,     0,   275,     0,     0,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
     259,   260,   276,   261,     0,     0,     0,     0,   277,   278,
       0,   279,   297,   298,   531,     4,     5,   300,   301,     0,
     321,   322,   569,     4,     5,   324,   325,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,   306,
       0,     0,   328,     0,     0,     0,     0,   330,     0,     0,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
       0,   311,   312,   570,   313,   -26,     0,     0,     0,   335,
     336,     0,   337,     0,     0,     0,     0,   -26,   -26,     0,
       0,     0,   -26,   -26,     0,     0,     0,   -26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -26,   -26,   -26,
     -26,   -26,   -75,   -26,   -26,   -26,   -26,   -26,   -26,     0,
       0,     0,     0,     0,   -75,   -75,   345,     0,     0,   -75,
     -75,     0,     0,     0,   -75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -76,
     -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,     0,
       0,   -76,   -76,   -75,     0,     0,   -76,   -76,     0,     0,
       0,   -76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -76,   -76,   -76,   -76,   -76,   -73,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,     0,     0,     0,   -73,   -73,
     -76,     0,     0,   -73,   -73,     0,     0,     0,   -73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -73,   -73,
     -73,   -73,   -73,   -74,   -73,   -73,   -73,   -73,   -73,   -73,
       0,     0,     0,     0,     0,   -74,   -74,   -73,     0,     0,
     -74,   -74,     0,     0,     0,   -74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,   -74,
     -71,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,
       0,     0,   -71,   -71,   -74,     0,     0,   -71,   -71,     0,
       0,     0,   -71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -71,   -71,   -71,   -71,   -71,   -72,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,   -72,
     -72,   -71,     0,     0,   -72,   -72,     0,     0,     0,   -72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -72,
     -72,   -72,   -72,   -72,   -78,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,     0,     0,   -78,   -78,   -72,     0,
       0,   -78,   -78,     0,     0,     0,   -78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -78,   -78,   -78,   -78,
     -78,   -77,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,     0,   -77,   -77,   -78,     0,     0,   -77,   -77,
       0,     0,     0,   -77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -77,   -77,   -77,   -77,   -77,     0,   -77,
     -77,   -77,   -77,   -77,   -77,   -75,   -75,     0,     0,     0,
     -75,   -75,   -77,     0,     0,   -75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,
       0,   -75,   -75,   -75,   -75,   -75,   -75,   -76,   -76,     0,
     -75,     0,   -76,   -76,   -75,     0,     0,   -76,     0,     0,
       0,   -75,     0,     0,     0,     0,     0,   -76,   -76,   -76,
     -76,   -76,     0,   -76,   -76,   -76,   -76,   -76,   -76,   -26,
     -26,     0,   -76,     0,   -26,   -26,   -76,     0,     0,   -26,
       0,     0,     0,   -76,     0,     0,     0,     0,     0,   -26,
     -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,
     -26,   -73,   -73,     0,   -26,     0,   -73,   -73,   981,     0,
       0,   -73,     0,     0,     0,   -26,     0,     0,     0,     0,
       0,   -73,   -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,
     -73,   -73,   -73,   -74,   -74,     0,   -73,     0,   -74,   -74,
     -73,     0,     0,   -74,     0,     0,     0,   -73,     0,     0,
       0,     0,     0,   -74,   -74,   -74,   -74,   -74,     0,   -74,
     -74,   -74,   -74,   -74,   -74,   -78,   -78,     0,   -74,     0,
     -78,   -78,   -74,     0,     0,   -78,     0,     0,     0,   -74,
       0,     0,     0,     0,     0,   -78,   -78,   -78,   -78,   -78,
       0,   -78,   -78,   -78,   -78,   -78,   -78,   -77,   -77,     0,
     -78,     0,   -77,   -77,   -78,     0,     0,   -77,     0,     0,
       0,   -78,     0,     0,     0,     0,     0,   -77,   -77,   -77,
     -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,   -77,   -71,
     -71,     0,   -77,     0,   -71,   -71,   -77,     0,     0,   -71,
       0,     0,     0,   -77,     0,     0,     0,     0,     0,   -71,
     -71,   -71,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,
     -71,   -72,   -72,     0,   -71,     0,   -72,   -72,   -71,     0,
       0,   -72,     0,     0,     0,   -71,     0,     0,     0,     0,
       0,   -72,   -72,   -72,   -72,   -72,     0,   -72,   -72,   -72,
     -72,   -72,   -72,   -14,   -14,     0,   -72,     0,   -14,   -14,
     -72,     0,     0,   -14,     0,     0,     0,   -72,     0,     0,
       0,     0,     0,   -14,   -14,   -14,   -14,   -14,     0,   588,
     589,   590,   591,   592,   593,   -22,   -22,     0,   -14,     0,
     580,   581,     0,     0,     0,   -22,     0,     0,     0,   -14,
       0,     0,     0,     0,     0,   583,   584,   585,   586,   587,
       0,   588,   589,   590,   591,   592,   593,   578,   -23,     0,
     -22,     0,   580,   581,     0,     0,     0,   -23,     0,     0,
       0,   -22,     0,     0,     0,     0,     0,   583,   584,   585,
     586,   587,     0,   588,   589,   590,   591,   592,   593,   578,
     579,     0,   -23,     0,   580,   581,     0,     0,     0,   582,
       0,     0,     0,   -23,     0,     0,     0,     0,     0,   583,
     584,   585,   586,   587,     0,   588,   589,   590,   591,   592,
     593,   -25,   -25,     0,   -24,     0,   -25,   -25,     0,     0,
       0,   -25,     0,     0,     0,   -24,     0,     0,     0,     0,
       0,   -25,   -25,   -25,   -25,   587,     0,   588,   589,   590,
     591,   592,   593,   -27,   -27,     0,   -25,     0,   -27,   -27,
       0,     0,     0,   -27,     0,     0,     0,   -25,     0,     0,
       0,     0,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,
     -27,   590,   591,   592,   593,   -28,   -28,     0,   -27,     0,
     -28,   -28,     0,     0,     0,   -28,     0,     0,     0,   -27,
       0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   590,   591,   592,   593,   -29,   -29,     0,
     -28,     0,   -29,   -29,     0,     0,     0,   -29,     0,     0,
       0,   -28,     0,     0,     0,     0,     0,   -29,   -29,   -29,
     -29,   -29,     0,   -29,   -29,   -29,   -29,   592,   593,   -30,
     -30,     0,   -29,     0,   -30,   -30,     0,     0,     0,   -30,
       0,     0,     0,   -29,     0,     0,     0,     0,     0,   -30,
     -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,   592,
     593,   -31,   -31,     0,   -30,     0,   -31,   -31,     0,     0,
       0,   -31,     0,     0,     0,   -30,     0,     0,     0,     0,
       0,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,
     -31,   592,   593,   -19,   -19,     0,   -31,     0,   -19,   -19,
       0,     0,     0,   -19,     0,   -21,   -21,   -31,     0,     0,
     -21,   -21,     0,     0,     0,   -21,     0,   587,     0,   588,
     589,   590,   591,   592,   593,   -13,     0,     0,   -19,   587,
       0,   588,   589,   590,   591,   592,   593,    53,    54,   -19,
     -21,     0,    55,    56,     0,     0,     0,    57,     0,     0,
       0,   -21,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,   -15,    63,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,   -15,   -15,     0,     0,     0,   -15,
     -15,     0,     0,     0,   -15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -15,   -15,   -15,   -15,   -15,   -14,
     -15,   -15,   -15,   -15,   -15,   -15,     0,     0,     0,     0,
       0,   -14,   -14,     0,     0,     0,   -14,   -14,     0,     0,
       0,   -14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -14,   -14,   -14,   -14,   -14,   -22,    63,    64,    65,
      66,    67,    68,     0,     0,     0,     0,     0,   -22,   -22,
       0,     0,     0,    55,    56,     0,     0,     0,   -22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,   -23,    63,    64,    65,    66,    67,    68,
       0,     0,     0,     0,     0,    53,   -23,     0,     0,     0,
      55,    56,     0,     0,     0,   -23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
     -24,    63,    64,    65,    66,    67,    68,     0,     0,     0,
       0,     0,    53,    54,     0,     0,     0,    55,    56,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,   -25,    63,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,   -25,
     -25,     0,     0,     0,   -25,   -25,     0,     0,     0,   -25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -25,
     -25,   -25,   -25,    62,   -27,    63,    64,    65,    66,    67,
      68,     0,     0,     0,     0,     0,   -27,   -27,     0,     0,
       0,   -27,   -27,     0,     0,     0,   -27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -27,   -27,   -27,   -27,
     -27,   -28,   -27,   -27,    65,    66,    67,    68,     0,     0,
       0,     0,     0,   -28,   -28,     0,     0,     0,   -28,   -28,
       0,     0,     0,   -28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -28,   -28,   -28,   -28,   -28,   -29,   -28,
     -28,    65,    66,    67,    68,     0,     0,     0,     0,     0,
     -29,   -29,     0,     0,     0,   -29,   -29,     0,     0,     0,
     -29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -29,   -29,   -29,   -29,   -29,   -30,   -29,   -29,   -29,   -29,
      67,    68,     0,     0,     0,     0,     0,   -30,   -30,     0,
       0,     0,   -30,   -30,     0,     0,     0,   -30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -30,   -30,   -30,
     -30,   -30,   -31,   -30,   -30,   -30,   -30,    67,    68,     0,
       0,     0,     0,     0,   -31,   -31,     0,     0,     0,   -31,
     -31,     0,     0,     0,   -31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,     0,
     -31,   -31,   -31,   -31,    67,    68,   -75,   -75,     0,     0,
       0,   -75,   -75,     0,     0,     0,   -75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -75,   -75,   -75,   -75,
     -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,   -76,   -76,     0,     0,   -75,   -76,   -76,   -75,     0,
       0,   -76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -76,   -76,   -76,   -76,   -76,     0,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,     0,   -26,   -26,     0,     0,
     -76,   -26,   -26,   -76,     0,     0,   -26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,
     -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,     0,     0,
       0,   -73,   -73,     0,     0,   929,   -73,   -73,   -26,     0,
       0,   -73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -73,   -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,
     -73,   -73,   -73,     0,     0,     0,   -74,   -74,     0,     0,
     -73,   -74,   -74,   -73,     0,     0,   -74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,
     -74,     0,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,
       0,   -78,   -78,     0,     0,   -74,   -78,   -78,   -74,     0,
       0,   -78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -78,   -78,   -78,   -78,   -78,     0,   -78,   -78,   -78,
     -78,   -78,   -78,     0,     0,     0,   -77,   -77,     0,     0,
     -78,   -77,   -77,   -78,     0,     0,   -77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -77,   -77,   -77,   -77,
     -77,     0,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,
       0,   -71,   -71,     0,     0,   -77,   -71,   -71,   -77,     0,
       0,   -71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -71,   -71,   -71,   -71,   -71,     0,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,   -72,   -72,     0,     0,
     -71,   -72,   -72,   -71,     0,     0,   -72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -72,   -72,   -72,   -72,
     -72,     0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,   444,   445,     0,     0,   -72,   446,   447,   -72,     0,
       0,   448,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   449,   450,   451,   452,   453,     0,   454,   455,   456,
     457,   458,   459,     0,   -15,   -15,     0,     0,     0,   -15,
     -15,     0,     0,   -13,   -15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -15,   -15,   -15,   -15,   -15,     0,
     -15,   -15,   -15,   -15,   -15,   -15,     0,   -14,   -14,     0,
       0,     0,   -14,   -14,     0,     0,   -15,   -14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -14,   -14,   -14,
     -14,   -14,     0,   454,   455,   456,   457,   458,   459,     0,
     -22,   -22,     0,     0,     0,   446,   447,     0,     0,   -14,
     -22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   450,   451,   452,   453,     0,   454,   455,   456,   457,
     458,   459,     0,   444,   -23,     0,     0,     0,   446,   447,
       0,     0,   -22,   -23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   449,   450,   451,   452,   453,     0,   454,
     455,   456,   457,   458,   459,     0,   444,   445,     0,     0,
       0,   446,   447,     0,     0,   -23,   448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   449,   450,   451,   452,
     453,     0,   454,   455,   456,   457,   458,   459,     0,   -25,
     -25,     0,     0,     0,   -25,   -25,     0,     0,   -24,   -25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -25,
     -25,   -25,   -25,   453,     0,   454,   455,   456,   457,   458,
     459,     0,   -27,   -27,     0,     0,     0,   -27,   -27,     0,
       0,   -25,   -27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     456,   457,   458,   459,     0,   -28,   -28,     0,     0,     0,
     -28,   -28,     0,     0,   -27,   -28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   456,   457,   458,   459,     0,   -29,   -29,
       0,     0,     0,   -29,   -29,     0,     0,   -28,   -29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -29,   -29,
     -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,   458,   459,
       0,   -30,   -30,     0,     0,     0,   -30,   -30,     0,     0,
     -29,   -30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,
     -30,   458,   459,     0,   -31,   -31,     0,     0,     0,   -31,
     -31,     0,     0,   -30,   -31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,     0,
     -31,   -31,   -31,   -31,   458,   459,     0,   -16,   -16,     0,
       0,     0,     0,     0,     0,     0,   -31,   -16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   449,   450,   451,
     452,   453,     0,   454,   455,   456,   457,   458,   459,     0,
     -17,   -17,     0,     0,     0,     0,     0,     0,     0,   -16,
     -17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   450,   451,   452,   453,     0,   454,   455,   456,   457,
     458,   459,     0,   -20,   -20,     0,     0,     0,   -20,   -20,
       0,     0,   -17,   -20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   453,     0,   454,
     455,   456,   457,   458,   459,     0,   -19,   -19,     0,     0,
       0,   -19,   -19,     0,     0,   -20,   -19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     453,     0,   454,   455,   456,   457,   458,   459,     0,   -21,
     -21,     0,     0,     0,   -21,   -21,     0,     0,   -19,   -21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   453,     0,   454,   455,   456,   457,   458,
     459,     0,   -75,   -75,     0,     0,     0,   -75,   -75,     0,
       0,   -21,   -75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -75,   -75,   -75,   -75,   -75,     0,   -75,   -75,
     -75,   -75,   -75,   -75,     0,     0,     0,   -76,   -76,   -75,
       0,   -75,   -76,   -76,     0,     0,     0,   -76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -76,   -76,   -76,
     -76,   -76,     0,   -76,   -76,   -76,   -76,   -76,   -76,     0,
       0,     0,   -26,   -26,   -76,     0,   -76,   -26,   -26,     0,
       0,     0,   -26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,
     -26,   -26,   -26,   -26,     0,     0,     0,   -73,   -73,   -26,
       0,   899,   -73,   -73,     0,     0,     0,   -73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -73,   -73,   -73,
     -73,   -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,     0,
       0,     0,   -74,   -74,   -73,     0,   -73,   -74,   -74,     0,
       0,     0,   -74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -74,   -74,   -74,   -74,   -74,     0,   -74,   -74,
     -74,   -74,   -74,   -74,     0,     0,     0,   -75,   -75,   -74,
       0,   -74,   -75,   -75,     0,   -75,     0,   -75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -75,   -75,   -75,
     -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,   -76,
     -76,     0,     0,     0,   -76,   -76,   -75,   -76,     0,   -76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -76,
     -76,   -76,   -76,   -76,     0,   -76,   -76,   -76,   -76,   -76,
     -76,   -26,   -26,     0,     0,     0,   -26,   -26,   -76,   -26,
       0,   -26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,
     -26,   -26,   -26,   -73,   -73,     0,     0,     0,   -73,   -73,
     914,   -73,     0,   -73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -73,   -73,   -73,   -73,   -73,     0,   -73,
     -73,   -73,   -73,   -73,   -73,   -74,   -74,     0,     0,     0,
     -74,   -74,   -73,   -74,     0,   -74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,   -74,
       0,   -74,   -74,   -74,   -74,   -74,   -74,   -75,   -75,     0,
       0,     0,   -75,   -75,   -74,     0,     0,   -75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -75,   -75,   -75,
     -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,   -76,
     -76,     0,   -75,     0,   -76,   -76,   -75,     0,     0,   -76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -76,
     -76,   -76,   -76,   -76,     0,   -76,   -76,   -76,   -76,   -76,
     -76,   -26,   -26,     0,   -76,     0,   -26,   -26,   -76,     0,
       0,   -26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,
     -26,   -26,   -26,   -73,   -73,     0,   -26,     0,   -73,   -73,
     946,     0,     0,   -73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -73,   -73,   -73,   -73,   -73,     0,   -73,
     -73,   -73,   -73,   -73,   -73,   -74,   -74,     0,   -73,     0,
     -74,   -74,   -73,     0,     0,   -74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,   -74,
       0,   -74,   -74,   -74,   -74,   -74,   -74,   -75,   -75,     0,
     -74,     0,   -75,   -75,   -74,     0,   -75,   -75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -75,   -75,   -75,
     -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,   -76,
     -76,     0,     0,     0,   -76,   -76,   -75,     0,   -76,   -76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -76,
     -76,   -76,   -76,   -76,     0,   -76,   -76,   -76,   -76,   -76,
     -76,   -26,   -26,     0,     0,     0,   -26,   -26,   -76,     0,
     -26,   -26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,
     -26,   -26,   -26,   -73,   -73,     0,     0,     0,   -73,   -73,
     966,     0,   -73,   -73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -73,   -73,   -73,   -73,   -73,     0,   -73,
     -73,   -73,   -73,   -73,   -73,   -74,   -74,     0,     0,     0,
     -74,   -74,   -73,     0,   -74,   -74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,   -74,
       0,   -74,   -74,   -74,   -74,   -74,   -74,   -78,   -78,     0,
       0,     0,   -78,   -78,   -74,     0,     0,   -78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -78,   -78,   -78,
     -78,   -78,     0,   -78,   -78,   -78,   -78,   -78,   -78,     0,
       0,     0,   -77,   -77,   -78,     0,   -78,   -77,   -77,     0,
       0,     0,   -77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -77,   -77,   -77,   -77,   -77,     0,   -77,   -77,
     -77,   -77,   -77,   -77,     0,     0,     0,   -71,   -71,   -77,
       0,   -77,   -71,   -71,     0,     0,     0,   -71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,     0,
       0,     0,   -72,   -72,   -71,     0,   -71,   -72,   -72,     0,
       0,     0,   -72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -72,   -72,   -72,   -72,   -72,     0,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,     0,   -78,   -78,   -72,
       0,   -72,   -78,   -78,     0,   -78,     0,   -78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -78,   -78,   -78,
     -78,   -78,     0,   -78,   -78,   -78,   -78,   -78,   -78,   -77,
     -77,     0,     0,     0,   -77,   -77,   -78,   -77,     0,   -77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -77,
     -77,   -77,   -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,
     -77,   -71,   -71,     0,     0,     0,   -71,   -71,   -77,   -71,
       0,   -71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -71,   -71,   -71,   -71,   -71,     0,   -71,   -71,   -71,
     -71,   -71,   -71,   -72,   -72,     0,     0,     0,   -72,   -72,
     -71,   -72,     0,   -72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -72,   -72,   -72,   -72,   -72,     0,   -72,
     -72,   -72,   -72,   -72,   -72,   -78,   -78,     0,     0,     0,
     -78,   -78,   -72,     0,     0,   -78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -78,   -78,   -78,   -78,   -78,
       0,   -78,   -78,   -78,   -78,   -78,   -78,   -77,   -77,     0,
     -78,     0,   -77,   -77,   -78,     0,     0,   -77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -77,   -77,   -77,
     -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,   -77,   -71,
     -71,     0,   -77,     0,   -71,   -71,   -77,     0,     0,   -71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -71,
     -71,   -71,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,
     -71,   -72,   -72,     0,   -71,     0,   -72,   -72,   -71,     0,
       0,   -72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -72,   -72,   -72,   -72,   -72,     0,   -72,   -72,   -72,
     -72,   -72,   -72,   -78,   -78,     0,   -72,     0,   -78,   -78,
     -72,     0,   -78,   -78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -78,   -78,   -78,   -78,   -78,     0,   -78,
     -78,   -78,   -78,   -78,   -78,   -77,   -77,     0,     0,     0,
     -77,   -77,   -78,     0,   -77,   -77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -77,   -77,   -77,   -77,   -77,
       0,   -77,   -77,   -77,   -77,   -77,   -77,   -71,   -71,     0,
       0,     0,   -71,   -71,   -77,     0,   -71,   -71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,   -72,
     -72,     0,     0,     0,   -72,   -72,   -71,     0,   -72,   -72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -72,
     -72,   -72,   -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,
     -72,   368,   369,     0,     0,     0,   370,   371,   -72,     0,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,     0,   378,   379,   380,
     381,   382,   383,     0,   -15,   -15,     0,     0,   -13,   -15,
     -15,     0,     0,     0,   -15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -15,   -15,   -15,   -15,   -15,     0,
     -15,   -15,   -15,   -15,   -15,   -15,     0,   -14,   -14,     0,
       0,   -15,   -14,   -14,     0,     0,     0,   -14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -14,   -14,   -14,
     -14,   -14,     0,   378,   379,   380,   381,   382,   383,     0,
     -22,   -22,     0,     0,   -14,   370,   371,     0,     0,     0,
     -22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     373,   374,   375,   376,   377,     0,   378,   379,   380,   381,
     382,   383,     0,   368,   -23,     0,     0,   -22,   370,   371,
       0,     0,     0,   -23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   373,   374,   375,   376,   377,     0,   378,
     379,   380,   381,   382,   383,     0,   368,   369,     0,     0,
     -23,   370,   371,     0,     0,     0,   372,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   373,   374,   375,   376,
     377,     0,   378,   379,   380,   381,   382,   383,     0,   -25,
     -25,     0,     0,   -24,   -25,   -25,     0,     0,     0,   -25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -25,
     -25,   -25,   -25,   377,     0,   378,   379,   380,   381,   382,
     383,     0,   -27,   -27,     0,     0,   -25,   -27,   -27,     0,
       0,     0,   -27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     380,   381,   382,   383,     0,   -28,   -28,     0,     0,   -27,
     -28,   -28,     0,     0,     0,   -28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   380,   381,   382,   383,     0,   -29,   -29,
       0,     0,   -28,   -29,   -29,     0,     0,     0,   -29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -29,   -29,
     -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,   382,   383,
       0,   -30,   -30,     0,     0,   -29,   -30,   -30,     0,     0,
       0,   -30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,
     -30,   382,   383,     0,   -31,   -31,     0,     0,   -30,   -31,
     -31,     0,     0,     0,   -31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,     0,
     -31,   -31,   -31,   -31,   382,   383,   -16,   -16,     0,     0,
       0,   -31,     0,     0,     0,     0,   -16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   373,   374,   375,   376,
     377,     0,   378,   379,   380,   381,   382,   383,   -17,   -17,
       0,     0,     0,   -16,     0,     0,     0,     0,   -17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   373,   374,
     375,   376,   377,     0,   378,   379,   380,   381,   382,   383,
       0,   -20,   -20,     0,     0,   -17,   -20,   -20,     0,     0,
       0,   -20,     0,   -19,   -19,     0,     0,     0,   -19,   -19,
       0,     0,     0,   -19,     0,   377,     0,   378,   379,   380,
     381,   382,   383,     0,     0,     0,     0,   377,   -20,   378,
     379,   380,   381,   382,   383,     0,   -21,   -21,     0,     0,
     -19,   -21,   -21,     0,     0,     0,   -21,     0,   486,   487,
       0,     0,     0,   488,   489,     0,     0,     0,   490,     0,
     377,     0,   378,   379,   380,   381,   382,   383,   491,   492,
     493,   494,   495,   -21,   496,   497,   498,   499,   500,   501,
     -15,   -15,     0,   -13,     0,   -15,   -15,     0,     0,     0,
     -15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -15,   -15,   -15,   -15,   -15,     0,   -15,   -15,   -15,   -15,
     -15,   -15,   -14,   -14,     0,   -15,     0,   -14,   -14,     0,
       0,     0,   -14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -14,   -14,   -14,   -14,   -14,     0,   496,   497,
     498,   499,   500,   501,   -22,   -22,     0,   -14,     0,   488,
     489,     0,     0,     0,   -22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   493,   494,   495,     0,
     496,   497,   498,   499,   500,   501,   486,   -23,     0,   -22,
       0,   488,   489,     0,     0,     0,   -23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,   492,   493,   494,
     495,     0,   496,   497,   498,   499,   500,   501,   486,   487,
       0,   -23,     0,   488,   489,     0,     0,     0,   490,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   492,
     493,   494,   495,     0,   496,   497,   498,   499,   500,   501,
     -25,   -25,     0,   -24,     0,   -25,   -25,     0,     0,     0,
     -25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -25,   -25,   -25,   -25,   495,     0,   496,   497,   498,   499,
     500,   501,   -27,   -27,     0,   -25,     0,   -27,   -27,     0,
       0,     0,   -27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     498,   499,   500,   501,   -28,   -28,     0,   -27,     0,   -28,
     -28,     0,     0,     0,   -28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,     0,
     -28,   -28,   498,   499,   500,   501,   -29,   -29,     0,   -28,
       0,   -29,   -29,     0,     0,     0,   -29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -29,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -29,   500,   501,   -30,   -30,
       0,   -29,     0,   -30,   -30,     0,     0,     0,   -30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -30,   -30,
     -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,   500,   501,
     -31,   -31,     0,   -30,     0,   -31,   -31,     0,     0,     0,
     -31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,
     500,   501,   -16,   -16,     0,   -31,     0,     0,     0,     0,
       0,     0,   -16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   491,   492,   493,   494,   495,     0,   496,   497,
     498,   499,   500,   501,   -17,   -17,     0,   -16,     0,     0,
       0,     0,     0,     0,   -17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   493,   494,   495,     0,
     496,   497,   498,   499,   500,   501,   -18,   -18,     0,   -17,
       0,   -18,   -18,     0,     0,     0,   -18,     0,   -20,   -20,
       0,     0,     0,   -20,   -20,     0,     0,     0,   -20,     0,
     495,     0,   496,   497,   498,   499,   500,   501,     0,     0,
       0,   -18,   495,     0,   496,   497,   498,   499,   500,   501,
     -19,   -19,     0,   -20,     0,   -19,   -19,     0,     0,     0,
     -19,     0,   -21,   -21,     0,     0,     0,   -21,   -21,     0,
       0,     0,   -21,     0,   495,     0,   496,   497,   498,   499,
     500,   501,     0,     0,     0,   -19,   495,     0,   496,   497,
     498,   499,   500,   501,   406,   407,     0,   -21,     0,   408,
     409,     0,   -13,     0,   410,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,   412,   413,   414,   415,     0,
     416,   417,   418,   419,   420,   421,   540,   541,     0,     0,
       0,   542,   543,     0,     0,   -13,   544,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   545,   546,   547,   548,
     549,     0,   550,   551,   552,   553,   554,   555,   -15,   -15,
       0,     0,     0,   -15,   -15,     0,   -15,     0,   -15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -15,   -15,
     -15,   -15,   -15,     0,   -15,   -15,   -15,   -15,   -15,   -15,
     -14,   -14,     0,     0,     0,   -14,   -14,     0,   -14,     0,
     -14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -14,   -14,   -14,   -14,   -14,     0,   416,   417,   418,   419,
     420,   421,   -15,   -15,     0,     0,     0,   -15,   -15,     0,
       0,   -15,   -15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -15,   -15,   -15,   -15,   -15,     0,   -15,   -15,
     -15,   -15,   -15,   -15,   -14,   -14,     0,     0,     0,   -14,
     -14,     0,     0,   -14,   -14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -14,   -14,   -14,   -14,   -14,     0,
     550,   551,   552,   553,   554,   555,   -22,   -22,     0,     0,
       0,   408,   409,     0,   -22,     0,   -22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   411,   412,   413,   414,
     415,     0,   416,   417,   418,   419,   420,   421,   406,   -23,
       0,     0,     0,   408,   409,     0,   -23,     0,   -23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   411,   412,
     413,   414,   415,     0,   416,   417,   418,   419,   420,   421,
     406,   407,     0,     0,     0,   408,   409,     0,   -24,     0,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     411,   412,   413,   414,   415,     0,   416,   417,   418,   419,
     420,   421,   -25,   -25,     0,     0,     0,   -25,   -25,     0,
     -25,     0,   -25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -25,   -25,   -25,   -25,   415,     0,   416,   417,
     418,   419,   420,   421,   -27,   -27,     0,     0,     0,   -27,
     -27,     0,   -27,     0,   -27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -27,   -27,   -27,   -27,   -27,     0,
     -27,   -27,   418,   419,   420,   421,   -28,   -28,     0,     0,
       0,   -28,   -28,     0,   -28,     0,   -28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,
     -28,     0,   -28,   -28,   418,   419,   420,   421,   -29,   -29,
       0,     0,     0,   -29,   -29,     0,   -29,     0,   -29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -29,   -29,
     -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,   420,   421,
     -30,   -30,     0,     0,     0,   -30,   -30,     0,   -30,     0,
     -30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,
     420,   421,   -31,   -31,     0,     0,     0,   -31,   -31,     0,
     -31,     0,   -31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,
     -31,   -31,   420,   421,   -22,   -22,     0,     0,     0,   542,
     543,     0,     0,   -22,   -22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,   546,   547,   548,   549,     0,
     550,   551,   552,   553,   554,   555,   540,   -23,     0,     0,
       0,   542,   543,     0,     0,   -23,   -23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   545,   546,   547,   548,
     549,     0,   550,   551,   552,   553,   554,   555,   540,   541,
       0,     0,     0,   542,   543,     0,     0,   -24,   544,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   545,   546,
     547,   548,   549,     0,   550,   551,   552,   553,   554,   555,
     -25,   -25,     0,     0,     0,   -25,   -25,     0,     0,   -25,
     -25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -25,   -25,   -25,   -25,   549,     0,   550,   551,   552,   553,
     554,   555,   -27,   -27,     0,     0,     0,   -27,   -27,     0,
       0,   -27,   -27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     552,   553,   554,   555,   -28,   -28,     0,     0,     0,   -28,
     -28,     0,     0,   -28,   -28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,     0,
     -28,   -28,   552,   553,   554,   555,   -29,   -29,     0,     0,
       0,   -29,   -29,     0,     0,   -29,   -29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -29,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -29,   554,   555,   -30,   -30,
       0,     0,     0,   -30,   -30,     0,     0,   -30,   -30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -30,   -30,
     -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,   554,   555,
     -31,   -31,     0,     0,     0,   -31,   -31,     0,     0,   -31,
     -31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,
     554,   555,   -17,   -17,     0,     0,     0,     0,     0,     0,
     -17,     0,   -17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   411,   412,   413,   414,   415,     0,   416,   417,
     418,   419,   420,   421,   -16,   -16,     0,     0,     0,     0,
       0,     0,     0,   -16,   -16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,   546,   547,   548,   549,     0,
     550,   551,   552,   553,   554,   555,   -17,   -17,     0,     0,
       0,     0,     0,     0,     0,   -17,   -17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   545,   546,   547,   548,
     549,     0,   550,   551,   552,   553,   554,   555,   -18,   -18,
       0,     0,     0,   -18,   -18,     0,   -18,     0,   -18,   -20,
     -20,     0,     0,     0,   -20,   -20,     0,   -20,     0,   -20,
       0,     0,   415,     0,   416,   417,   418,   419,   420,   421,
       0,     0,     0,   415,     0,   416,   417,   418,   419,   420,
     421,   -19,   -19,     0,     0,     0,   -19,   -19,     0,   -19,
       0,   -19,   -21,   -21,     0,     0,     0,   -21,   -21,     0,
     -21,     0,   -21,     0,     0,   415,     0,   416,   417,   418,
     419,   420,   421,     0,     0,     0,   415,     0,   416,   417,
     418,   419,   420,   421,   -20,   -20,     0,     0,     0,   -20,
     -20,     0,     0,   -20,   -20,   -19,   -19,     0,     0,     0,
     -19,   -19,     0,     0,   -19,   -19,     0,     0,   549,     0,
     550,   551,   552,   553,   554,   555,     0,     0,     0,   549,
       0,   550,   551,   552,   553,   554,   555,   -21,   -21,     0,
       0,     0,   -21,   -21,     0,     0,   -21,   -21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   549,     0,   550,   551,   552,   553,   554,   555
};

static const yytype_int16 yycheck[] =
{
       0,   163,    46,     0,   177,    28,    10,    10,     8,     9,
       0,    15,    15,    13,    14,    10,    16,    11,    18,    47,
      15,     5,    11,     0,     0,    25,    15,     5,   201,    29,
      58,    15,    47,    46,    29,    47,    34,    26,    16,    23,
      24,    35,    68,    58,    28,    71,    58,    49,    52,    52,
      87,    51,   225,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    52,    47,
      68,    76,     5,    71,    20,   186,    47,    77,    78,   252,
       5,   243,    15,    10,    84,    15,    45,    58,    15,    48,
      15,    96,    92,    93,    49,    28,    47,    10,    47,   210,
      10,   274,    15,    28,   130,    15,   132,    58,     3,     4,
       5,     6,     7,     8,     9,    47,    49,    52,    54,    52,
      53,    10,    52,   234,    49,    52,    15,    52,    53,   129,
      25,   304,    51,   133,    15,    30,     0,   137,    57,    52,
      29,   167,    52,   143,     5,   145,    51,   184,    47,     5,
     261,    46,    57,    45,    15,   328,    48,    52,    53,    15,
      55,   161,    23,    24,     5,   165,     0,    28,   279,     5,
     193,   208,    28,    10,    15,   175,   176,   182,    15,    15,
     180,   181,    11,   183,   178,   185,    15,    28,   182,    47,
     190,    52,    28,    49,   217,   232,    52,    26,    10,   199,
     200,   206,   313,    15,   204,   205,    11,   207,   202,   209,
      15,    52,   206,    49,   214,    52,    52,    29,   241,    21,
       5,    26,   259,   223,   224,   230,   337,    47,   228,   229,
      15,   231,   226,   233,    45,    51,   230,    48,   238,    24,
     277,    57,    52,    28,    47,   268,     5,     5,   285,    43,
     250,   251,   257,    47,   291,   255,    15,    15,   281,   253,
     260,     0,    47,   257,    58,   265,    24,    52,    47,    28,
      28,     5,    10,    47,   311,     0,     5,    15,   278,    58,
      45,    11,   276,    48,    58,    15,    15,    16,    45,    47,
      49,    29,    47,    52,    52,    24,    26,   320,   335,    28,
      47,    47,   302,   303,   309,    54,     5,   307,   308,    49,
     310,   305,   312,   350,     5,   309,    15,   317,    47,   345,
     346,   344,     0,    52,    15,    16,   326,   327,   333,    28,
      45,   331,   332,    24,   334,   329,   336,    28,    47,   333,
      10,   341,    46,    10,    47,    15,    51,     0,    15,    58,
      49,   351,    57,    52,    47,    58,    47,   383,   356,    29,
     386,    52,    29,   357,     0,    58,   360,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,    47,     0,   383,    47,    11,   386,   389,
      49,    15,    49,    51,    58,   421,   394,    58,   424,    57,
      45,   395,    26,    48,   398,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,    46,    51,   421,    51,    11,   424,   427,    57,    15,
      57,    51,    51,   459,   432,    20,   462,    57,    57,   433,
      26,   467,   436,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,    20,
       5,   459,    46,     5,   462,    11,   466,    54,   468,    15,
      15,    16,    54,    15,    16,   501,   474,     5,   504,    24,
      26,   475,    24,    28,   478,   485,    28,    15,   514,    11,
      10,    51,    46,    15,    10,    15,    24,    57,    45,    15,
      28,    48,    47,   501,    26,    47,   504,    52,     5,    29,
      52,     5,   512,    29,   508,    47,   514,    10,    15,    47,
      47,    15,    15,   523,    52,    46,    23,    24,    46,   555,
     528,    28,   558,    21,    28,   529,    29,    21,   532,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,    52,    46,   555,    52,    11,
     558,   561,    45,    15,    46,    48,    20,   593,   566,    49,
     596,    49,    47,   567,    26,    52,   570,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,    54,    49,   593,    11,    46,   596,   636,
      15,   606,    20,    49,    47,    11,   643,   607,   608,    15,
     610,    26,   612,     3,     4,     5,     6,     7,     8,     9,
      26,     3,     4,     5,     6,     7,     8,     9,    52,    54,
      46,    20,    49,    47,    54,    25,    49,     5,    28,    47,
      30,    52,   679,    25,   649,    46,    28,    15,    30,   686,
     650,   651,    49,   653,    20,   655,    46,    49,    52,    47,
      28,    51,    52,    53,    46,    55,    56,    54,    52,    51,
      52,    53,     5,    55,    56,     3,     4,     5,     6,     7,
       8,     9,    15,    54,    52,   722,    47,   692,    52,    47,
      23,    24,   729,   693,   694,    28,   696,    25,   698,    52,
      28,    10,    30,    47,    47,    46,    15,    49,     3,     4,
       5,     6,     7,     8,     9,    20,    47,    49,    46,    52,
      29,    20,    52,    51,    52,    53,     5,    55,    56,    54,
      25,    46,   769,    28,   739,    30,    15,    49,    49,   776,
      47,   741,    52,    47,    23,    24,    54,    49,    20,    28,
      10,    46,    52,   790,    47,    15,    51,    52,    53,    49,
      55,    56,     3,     4,     5,     6,     7,     8,     9,    29,
      54,     5,   934,    52,     3,     4,     5,     6,     7,     8,
       9,    15,    16,    54,    25,    21,    47,    28,    10,    30,
      24,    49,    49,    15,    28,   832,    25,   802,    21,    28,
      49,    30,   839,   803,   804,    46,   806,    29,   808,     5,
      51,    52,    53,    47,    55,    56,    47,    46,    52,    52,
      10,    47,    51,    52,    53,    15,    55,    56,    52,    47,
      21,     3,     4,     5,     6,     7,     8,     9,   875,    29,
     845,    20,    20,    20,     5,   882,   846,   847,    47,   849,
      52,   851,     5,    25,    47,    52,    28,    21,    30,    47,
      54,     5,    15,     3,     4,     5,     6,     7,     8,     9,
      23,    24,    54,   899,    46,    28,    47,   903,    54,    51,
      52,    53,    10,    55,    56,    25,     5,    15,   914,    10,
      30,    47,   918,    52,    15,   895,    15,    16,    52,    52,
      47,    29,   902,   929,     5,    24,    46,   933,    29,    28,
     910,     5,    52,    53,    15,    55,    56,   917,    47,    21,
     946,    15,    16,    24,   950,   925,    10,    28,    47,   955,
      24,    15,   932,    52,    28,    47,    47,     5,    47,    52,
     966,    47,     5,    21,   970,    29,    47,     5,    52,   949,
      47,    52,    15,    47,   954,   981,     5,    15,    52,   985,
      23,    24,   962,    10,    52,    28,    15,    47,    15,   969,
      28,    21,     0,     5,     5,    24,    21,   977,    21,    28,
       8,     9,    29,    15,   984,    13,    14,   987,    16,    52,
      18,    23,    24,    47,    52,     5,    28,    25,    47,  1025,
    1000,    29,    10,    52,    52,    15,    47,    15,    52,    47,
      21,     5,    47,  1013,    47,    52,    52,    20,    28,    45,
      52,    29,    49,    51,    45,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      45,    10,    52,     5,    45,  1045,    15,    45,    54,    77,
      78,    47,    45,    15,    45,    45,    84,    45,  1058,     5,
      29,     5,    10,    21,    92,    93,    28,    15,    45,    15,
    1070,    15,  1072,  1073,    45,  1075,  1076,    45,  1078,    49,
      24,    29,    28,  1083,    28,  1085,  1086,    49,  1088,    20,
      52,     3,     4,     5,     6,     7,     8,     9,    54,    21,
      47,   129,     5,    47,     5,   133,    52,    49,    52,   137,
      49,    20,    15,    25,    15,   143,    28,   145,    30,    10,
      23,    24,    20,    24,    15,    28,    54,    28,    54,    47,
      47,    10,    21,   161,    46,     5,    15,   165,    29,    51,
      52,    53,    -1,    55,    56,    15,    47,   175,   176,    52,
      29,    52,   180,   181,    21,   183,    -1,   185,    28,    -1,
      -1,    -1,   190,     3,     4,     5,     6,     7,     8,     9,
      -1,   199,   200,    -1,     5,    -1,   204,   205,    -1,   207,
      -1,   209,    52,    -1,    15,    25,   214,    -1,    28,    -1,
      30,    -1,    23,    24,    -1,   223,   224,    28,    -1,    -1,
     228,   229,    -1,   231,    -1,   233,    46,     5,    -1,    -1,
     238,    51,    52,    53,     5,    55,    56,    15,    -1,    -1,
      -1,    52,   250,   251,    15,    -1,    24,   255,    -1,    -1,
      28,    -1,   260,    24,    -1,    -1,     5,    28,     3,     4,
       5,     6,     7,     8,     9,    -1,    15,     5,     5,    47,
     278,    -1,    -1,    -1,    52,    24,    47,    15,    15,    28,
      25,    52,     5,    28,    -1,    30,    23,    24,    -1,    -1,
      28,    28,    15,    -1,   302,   303,    -1,    -1,    47,   307,
     308,    46,   310,    52,   312,    28,    51,    52,    53,   317,
      55,    56,    -1,    -1,    52,    52,    -1,    -1,   326,   327,
      -1,    -1,    -1,   331,   332,    -1,   334,    -1,   336,    52,
      -1,    -1,     5,   341,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    15,   351,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    28,    -1,    -1,    28,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,    -1,    49,    47,    -1,    52,
      -1,   389,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    71,    -1,    -1,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,    -1,    -1,   130,    -1,   132,    -1,    -1,   466,    -1,
     468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,   485,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
     167,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,   512,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,   523,    -1,    -1,    51,    52,
      53,    -1,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,    -1,    -1,    -1,
      -1,    -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,    -1,     5,     5,     5,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    15,    15,    15,   607,
     608,    15,   610,    -1,   612,    -1,    24,    24,    -1,    28,
      28,    28,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    47,
      47,    12,    13,    52,    52,    52,    17,    18,    52,    -1,
       5,    22,   650,   651,    25,   653,    -1,   655,    -1,    30,
      15,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    28,    -1,    46,    47,    -1,   345,   346,
       5,    52,    53,     5,    55,    -1,    -1,    58,    -1,    -1,
      15,     5,    -1,    15,    49,   693,   694,    52,   696,    24,
     698,    15,    24,    28,    -1,     5,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    15,   383,    -1,    -1,   386,
      -1,    -1,    47,    -1,    24,    47,    -1,    52,    28,    -1,
      52,     3,     4,     5,     6,     7,     8,     9,    52,    -1,
      12,    13,    -1,   741,    -1,    17,    18,    47,    -1,     5,
      22,    -1,    52,    25,   421,     5,    28,   424,    30,    15,
      32,    33,    34,    35,    36,    15,    38,    39,    40,    41,
      42,    43,    28,    45,    46,    47,    48,    -1,    28,    51,
      52,    53,    -1,    55,     5,    -1,    58,    -1,    -1,    -1,
      -1,    -1,   459,    49,    15,   462,    52,    -1,    -1,    49,
     467,    -1,    52,    24,    -1,   803,   804,    28,   806,    -1,
     808,     3,     4,     5,     6,     7,     8,     9,    -1,     3,
       4,     5,     6,     7,     8,     9,    47,    -1,    -1,    -1,
      -1,    52,    -1,    25,   501,    -1,    28,   504,    30,    -1,
      -1,    25,     5,    -1,    28,    -1,    30,   514,   846,   847,
      -1,   849,    15,   851,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    46,    55,    56,    28,    -1,    51,    52,    53,
      -1,    55,    56,     3,     4,     5,     6,     7,     8,     9,
      -1,     3,     4,     5,     6,     7,     8,     9,   555,    52,
      -1,   558,     5,    -1,    -1,    25,    -1,   895,    -1,    -1,
      30,    -1,    15,    25,   902,    -1,    -1,    -1,    30,    39,
      -1,    -1,   910,    -1,    -1,    28,    46,    39,    -1,   917,
      50,    -1,    52,    53,    46,    55,   593,   925,    50,   596,
      52,    53,    -1,    55,   932,    -1,    49,     5,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,     3,     4,
       5,     6,     7,     8,     9,    -1,   954,    -1,    -1,    -1,
      28,    -1,     5,    -1,   962,    -1,    -1,    -1,    -1,    -1,
      25,   969,    15,    28,     0,    30,    -1,    -1,    -1,   977,
      -1,    24,     8,     9,    52,    28,   984,    13,    14,   987,
      16,    46,    18,    -1,    -1,     5,    51,    52,    53,    25,
      55,    56,  1000,    29,    47,    15,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,  1013,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    52,    -1,    -1,     5,    -1,  1045,    -1,    -1,
      -1,    77,    78,    -1,    -1,    15,    -1,    -1,    84,    -1,
    1058,     5,    -1,     5,    -1,    -1,    92,    93,    28,    -1,
      -1,    15,  1070,    15,  1072,  1073,    -1,  1075,  1076,    -1,
    1078,     5,    24,    -1,    28,  1083,    28,  1085,  1086,    49,
    1088,    15,    52,     3,     4,     5,     6,     7,     8,     9,
      24,    -1,    -1,   129,    28,    47,    -1,   133,    52,    -1,
      52,   137,    -1,    -1,    -1,    25,    -1,   143,    28,   145,
      30,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    46,    -1,    -1,   165,
      -1,    51,    52,    53,    -1,    55,    56,    -1,    -1,   175,
     176,    -1,    -1,    -1,   180,   181,    -1,   183,    -1,   185,
      -1,    -1,    -1,    -1,   190,     3,     4,     5,     6,     7,
       8,     9,    -1,   199,   200,    -1,    -1,    -1,   204,   205,
      -1,   207,    -1,   209,    -1,    -1,    -1,    25,   214,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,   223,   224,    -1,
      -1,    -1,   228,   229,    -1,   231,    -1,   233,    46,    -1,
      -1,    -1,   238,    51,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,   250,   251,    -1,    -1,    -1,   255,
      -1,    -1,   899,    -1,   260,    -1,   903,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,   914,    17,    18,
      -1,   918,   278,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   929,    -1,    -1,    -1,   933,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,   302,   303,    47,   946,
      -1,   307,   308,   950,   310,    -1,   312,    -1,   955,    58,
      -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   966,
     326,   327,    -1,   970,    -1,   331,   332,    -1,   334,    -1,
     336,    -1,    -1,    -1,   981,   341,    -1,    -1,   985,    -1,
      -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,    -1,  1025,    -1,
      -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,    -1,    -1,    -1,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,   485,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,   512,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,   523,    -1,    -1,
      51,    52,    53,    -1,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,    -1,
      -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,   607,   608,    -1,   610,    -1,   612,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,     0,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    46,    -1,    -1,    17,    18,    51,    52,    53,
      22,    55,    56,    25,   650,   651,    28,   653,    30,   655,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    -1,    48,    -1,    -1,    51,
      52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   693,   694,    -1,
     696,    -1,   698,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,     0,    38,    39,
      40,    41,    42,    43,    -1,   741,    46,    47,    -1,    12,
      13,    51,    52,    53,    -1,    55,    -1,    -1,    58,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,   803,   804,    28,
     806,    30,   808,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     846,   847,    -1,   849,    -1,   851,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,   895,
      -1,    46,    47,    -1,    -1,    -1,   902,    52,    53,    -1,
      55,    -1,    -1,    58,   910,    -1,    -1,    -1,    -1,    -1,
      -1,   917,     3,     4,     5,     6,     7,     8,     9,   925,
      -1,    -1,    -1,    12,    13,    -1,   932,    -1,    17,    18,
      -1,    -1,    -1,    22,    25,    -1,    -1,    28,    -1,    30,
      -1,    -1,    -1,    32,    33,    34,    35,    36,   954,    38,
      39,    40,    41,    42,    43,    46,   962,    -1,    47,    -1,
      51,    52,    53,   969,    55,    56,     0,    -1,    -1,    58,
      -1,   977,    -1,    -1,     8,     9,    -1,    -1,   984,    13,
      14,   987,    16,    -1,    18,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,  1000,    29,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1013,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,    41,    42,    43,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,  1045,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      84,    -1,  1058,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    -1,    -1,  1070,    -1,  1072,  1073,    -1,  1075,
    1076,    -1,  1078,    -1,    -1,    -1,    -1,  1083,    -1,  1085,
    1086,    -1,  1088,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    12,    13,    -1,   129,    -1,    17,    18,   133,
      -1,    -1,    22,   137,    -1,    -1,    -1,    25,    -1,    -1,
      28,   145,    30,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,   161,    46,    49,
      -1,   165,    -1,    51,    52,    53,    -1,    55,    56,    -1,
      -1,   175,   176,    -1,    -1,    -1,   180,   181,    -1,   183,
      -1,   185,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,   199,   200,    -1,    -1,    -1,
     204,   205,    -1,   207,    -1,   209,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,    -1,    -1,    -1,   228,   229,    -1,   231,    46,   233,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,    56,     3,
       4,     5,     6,     7,     8,     9,   250,   251,    -1,    12,
      13,   255,   256,    -1,   258,    -1,   260,    -1,    -1,    22,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    -1,    32,
      33,    34,    35,    36,   278,    38,    39,    40,    41,    42,
      43,    -1,    46,    -1,    47,    -1,    -1,    51,    52,    53,
      -1,    55,    56,    -1,    -1,    58,    -1,    -1,   302,   303,
      -1,    -1,    -1,   307,   308,    -1,   310,    -1,   312,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   326,   327,    -1,    -1,    -1,   331,   332,    -1,
     334,    25,   336,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,    56,    -1,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,    -1,
      -1,    -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,    -1,    -1,    -1,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   466,    -1,   468,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,    25,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,   523,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,    25,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   607,   608,    -1,   610,    -1,   612,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      56,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,   650,   651,    28,   653,
      30,   655,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   693,
     694,    -1,   696,    -1,   698,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,     0,
      38,    39,    40,    41,    42,    43,    -1,   741,    46,    47,
      -1,    12,    13,    51,    52,    53,    -1,    55,    -1,    -1,
      58,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,   803,
     804,    28,   806,    30,   808,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   846,   847,    -1,   849,    -1,   851,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,   895,    46,    47,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,    -1,    -1,    58,    -1,   910,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,   925,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,   962,    -1,
      -1,    51,    52,    53,    -1,    55,     0,    -1,    58,    -1,
      -1,    -1,    -1,   977,     8,     9,    -1,    12,    13,    13,
      14,    -1,    16,   987,    18,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,  1000,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,  1013,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    25,    -1,    -1,    -1,    -1,    30,
      -1,  1045,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,  1058,    46,    -1,    -1,    92,    93,
      -1,    52,    53,    -1,    55,    56,  1070,    -1,  1072,  1073,
      -1,  1075,  1076,    -1,  1078,    -1,    -1,    -1,    -1,  1083,
       0,  1085,  1086,    -1,  1088,     3,     4,     5,     6,     7,
       8,     9,    12,    13,    -1,   129,    -1,    17,    18,   133,
      -1,    -1,    22,   137,    -1,    -1,    -1,    25,    -1,    -1,
      -1,   145,    30,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,   161,    46,    -1,
      -1,   165,    -1,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,   175,   176,    -1,    -1,    -1,   180,   181,    -1,   183,
      -1,   185,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,   199,   200,    -1,    -1,    -1,
     204,   205,    -1,   207,    -1,   209,    -1,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,    -1,    -1,    -1,   228,   229,    -1,   231,    46,   233,
      -1,    -1,    -1,    -1,    52,    53,    -1,    55,    56,     3,
       4,     5,     6,     7,     8,     9,   250,   251,    -1,    12,
      13,   255,    -1,    -1,    17,    18,   260,    -1,    -1,    22,
      -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    32,
      33,    34,    35,    36,   278,    38,    39,    40,    41,    42,
      43,    -1,    46,    -1,    47,    -1,    -1,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    58,    -1,    -1,   302,   303,
      -1,    -1,    -1,   307,   308,    -1,   310,    -1,   312,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   326,   327,    -1,    -1,    -1,   331,   332,    -1,
     334,    25,   336,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    55,    56,    -1,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,    -1,
      -1,    -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,    -1,    -1,    -1,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,    25,    -1,    -1,    -1,    -1,
      30,    -1,   466,    -1,   468,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    46,    -1,    -1,    17,
      18,    -1,    52,    53,    22,    55,    56,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,    -1,   523,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   607,   608,    -1,   610,    -1,   612,    -1,
      46,    -1,    -1,    -1,     0,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
       0,    17,    18,    -1,    -1,    -1,    22,    -1,     8,     9,
      -1,    -1,    -1,    13,    -1,    -1,   650,   651,    18,   653,
      36,   655,    38,    39,    40,    41,    42,    43,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,   693,
     694,    -1,   696,    30,   698,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    77,    78,    46,
      47,    -1,    -1,    -1,    84,    52,    53,    -1,    55,    -1,
      -1,    58,    92,    93,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,   741,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,   129,
      25,    -1,    -1,   133,    -1,    30,    -1,   137,    -1,    -1,
      46,    -1,    -1,    -1,    39,   145,    52,    53,    -1,    55,
      56,    46,    -1,    -1,    -1,    50,    -1,    52,    53,    -1,
      55,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,   803,
     804,    -1,   806,    -1,   808,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,   199,
     200,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,   209,
      -1,    25,   846,   847,    -1,   849,    30,   851,    -1,    -1,
      -1,    -1,    -1,   223,   224,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    46,   233,    -1,    -1,    -1,    -1,    52,    53,
      -1,    55,    56,     3,     4,     5,     6,     7,     8,     9,
     250,   251,    -1,    12,    13,   255,    -1,    -1,    17,    18,
     260,   895,    -1,    22,    -1,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,   910,    36,   278,    38,
      39,    40,    41,    42,    43,    -1,    46,    -1,    47,    -1,
      -1,   925,    52,    53,    -1,    55,    56,    -1,    -1,    58,
      -1,    -1,   302,   303,    -1,    -1,    -1,   307,    -1,    -1,
      -1,    -1,   312,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,   326,   327,   962,    -1,
      -1,   331,    -1,    -1,    -1,    -1,   336,    25,    -1,    -1,
      -1,    -1,    30,   977,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   351,    -1,   987,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    52,    53,  1000,    55,    56,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,  1013,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,   389,
      -1,    -1,    -1,    25,    -1,    27,    -1,     0,    30,    31,
      -1,    -1,    -1,    -1,    -1,     8,     9,    39,    -1,    -1,
      13,  1045,    -1,    -1,    46,    18,    -1,    -1,    50,    -1,
      52,    53,    -1,    55,  1058,    -1,    29,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1070,    -1,  1072,  1073,
      -1,  1075,  1076,    -1,  1078,    -1,    -1,    -1,    -1,  1083,
      -1,  1085,  1086,    -1,  1088,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,   466,    14,   468,   469,
      -1,    -1,    19,    -1,    77,    78,    -1,    -1,    25,    -1,
      27,    84,    -1,    30,    31,    -1,    -1,    -1,    -1,    92,
      93,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    50,    -1,    52,    53,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,   523,    -1,    -1,   129,    14,    -1,    -1,
     133,    -1,    19,    -1,   137,    -1,    -1,    -1,    25,    -1,
      27,    -1,   145,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,   161,    46,
      -1,   561,   165,    50,    -1,    52,    53,    -1,    55,    -1,
      -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   200,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,   209,   607,   608,    -1,
     610,    -1,   612,     3,     4,     5,     6,     7,     8,     9,
     223,   224,    -1,    -1,    14,   228,    -1,    -1,    -1,    19,
     233,    -1,    -1,    -1,    -1,    25,    -1,    27,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,   250,   251,    39,
     650,   651,   255,   653,    -1,   655,    46,   260,    -1,    -1,
      50,    -1,    52,    53,    -1,    55,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,   278,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,   693,   694,    30,   696,    -1,   698,   302,
     303,    -1,    -1,    -1,   307,    -1,    -1,    -1,    -1,   312,
      -1,    46,    -1,     0,    -1,    -1,    -1,    52,    53,    -1,
      55,    -1,    -1,   326,   327,    12,    13,    -1,   331,    -1,
      17,    18,    -1,   336,    -1,    22,    -1,    -1,    -1,    -1,
     740,   741,    -1,   743,    -1,   745,    -1,    -1,   351,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,     0,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,   389,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,   803,   804,    46,   806,    -1,   808,    -1,
      51,    52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,   846,   847,    -1,   849,
      36,   851,    38,    39,    40,    41,    42,    43,    -1,    25,
      -1,    -1,    -1,   466,    30,   468,    -1,    -1,    54,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      46,    -1,    -1,    17,    18,    -1,    52,    53,    22,    55,
      -1,    25,    -1,    -1,    28,   895,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
     910,    -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,
     523,    55,    -1,    -1,    58,   925,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      14,    -1,   942,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    -1,    -1,    30,    31,   561,    -1,
      -1,    -1,   962,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    50,   977,    52,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,   987,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
    1000,    14,    -1,    -1,   607,   608,    19,   610,    -1,   612,
      -1,    -1,    25,  1013,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    -1,    52,
      53,    -1,    55,    -1,    -1,  1045,    -1,   650,   651,    -1,
     653,    -1,   655,    -1,    -1,    -1,    -1,    -1,  1058,     8,
       9,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    18,
    1070,    -1,  1072,  1073,    -1,  1075,  1076,    -1,  1078,    -1,
    1080,    -1,  1082,  1083,    -1,  1085,  1086,    -1,  1088,    -1,
     693,   694,    -1,   696,    -1,   698,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    78,
      14,    80,    -1,    -1,    83,    19,    -1,    -1,   741,    -1,
      -1,    25,    -1,    27,    93,    -1,    30,    31,    97,    -1,
      -1,    -1,   101,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    50,    -1,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
     129,    -1,    -1,    -1,   133,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    25,    -1,   145,    -1,    -1,    30,
     803,   804,    -1,   806,    -1,   808,    -1,    25,    39,    -1,
      -1,    -1,    30,    -1,    -1,    46,    -1,    -1,    -1,    50,
      -1,    52,    53,    -1,    55,    -1,   175,   176,    46,    -1,
      -1,   180,    -1,    -1,    52,    53,   185,    55,    -1,    -1,
      -1,    -1,    -1,   846,   847,    -1,   849,    -1,   851,    -1,
     199,   200,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
     209,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,   223,   224,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    25,
      -1,    -1,   895,   242,    30,    -1,    -1,    -1,    -1,    -1,
      -1,   250,   251,    39,    -1,    -1,   255,   910,    -1,    -1,
      46,   260,    -1,    -1,    50,    -1,    52,    53,    -1,    55,
      -1,    -1,   925,    -1,    -1,    -1,     0,    -1,    -1,   278,
      -1,    -1,    -1,    -1,   283,    -1,    -1,    -1,    12,    13,
     289,    -1,    -1,    17,    18,   294,    -1,   296,    22,    -1,
      -1,    -1,    -1,   302,   303,    -1,    -1,    -1,   307,   962,
      -1,    -1,    36,   312,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,   977,    -1,    -1,   326,   327,    -1,
      -1,    -1,   331,    -1,   987,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1000,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1013,     0,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,  1045,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,  1058,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,  1070,    -1,  1072,
    1073,    -1,  1075,  1076,    -1,  1078,    -1,    -1,    -1,    -1,
    1083,    -1,  1085,  1086,    -1,  1088,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,   466,    30,   468,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,    -1,    -1,    58,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      -1,    -1,    58,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,    -1,    -1,    58,   608,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,   634,    -1,    22,    -1,    -1,
      25,    -1,   641,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,   651,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,   677,    -1,
      -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   694,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,   720,    25,    -1,    -1,    28,    -1,    30,   727,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,   741,    46,    47,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,
      -1,    -1,    -1,    -1,    -1,   774,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,   788,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,   804,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
      -1,   830,    58,    -1,    -1,    -1,    -1,    -1,   837,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,   847,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,   873,    38,    39,    40,    41,    42,
      43,   880,    -1,    46,    47,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,    -1,    -1,    58,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,    -1,
      -1,    58,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,   987,    38,
      39,    40,    41,    42,    43,    12,    13,    46,    47,    -1,
      -1,  1000,    51,    52,    53,    22,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,  1013,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,  1027,    -1,
      47,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    58,    12,    13,    -1,    -1,  1045,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,  1058,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,    -1,    -1,    58,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,    -1,    -1,    58,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,     0,    -1,
      58,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,     0,    55,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,     0,    55,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
       0,    55,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,     0,    55,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,     0,    55,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,     0,    55,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,     0,    55,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
       0,    55,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,     0,    55,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,     0,    55,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,     0,    55,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,     0,    55,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
       0,    55,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,     0,    55,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,     0,    55,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,     0,    55,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,     0,    55,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
       0,    55,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,     0,    55,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,     0,    55,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    55,    -1,    -1,    58,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    55,     0,    -1,    58,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    52,    53,     0,    55,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,
      53,     0,    55,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    52,    53,     0,    55,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    52,    53,     0,
      55,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    -1,
      48,    49,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    -1,    48,    -1,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    -1,    48,    -1,    -1,    51,
      52,    53,    54,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    45,
      46,    -1,    48,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    49,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    49,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    49,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    49,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    49,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    49,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      49,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    49,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    49,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    49,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    49,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    49,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    49,    -1,    51,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    49,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      49,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,
      53,    -1,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    -1,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    -1,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    -1,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    53,    -1,    55,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    55,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    -1,    52,    53,    -1,    55,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    55,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    39,    -1,    -1,    50,    -1,    52,
      53,    46,    55,    -1,    -1,    50,    -1,    52,    53,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      52,    53,    46,    55,    -1,    -1,    -1,    -1,    52,    53,
      -1,    55,     3,     4,     5,     6,     7,     8,     9,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    52,    53,    46,    55,     0,    -1,    -1,    -1,    52,
      53,    -1,    55,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,     0,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    12,    13,    51,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,     0,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    12,    13,    51,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,     0,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    12,    13,
      51,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,     0,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    12,    13,    51,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
       0,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    12,    13,    51,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,     0,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    12,
      13,    51,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,     0,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    12,    13,    51,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,     0,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    12,    13,    51,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    -1,    -1,
      17,    18,    51,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      47,    -1,    17,    18,    51,    -1,    -1,    22,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    47,    -1,    17,    18,    51,    -1,    -1,    22,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    47,    -1,    17,    18,    51,    -1,
      -1,    22,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    47,    -1,    17,    18,
      51,    -1,    -1,    22,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    47,    -1,
      17,    18,    51,    -1,    -1,    22,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      47,    -1,    17,    18,    51,    -1,    -1,    22,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    47,    -1,    17,    18,    51,    -1,    -1,    22,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    47,    -1,    17,    18,    51,    -1,
      -1,    22,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    47,    -1,    17,    18,
      51,    -1,    -1,    22,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    47,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      47,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    47,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    47,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    47,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    47,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      47,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    47,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    47,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    47,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    12,    13,    58,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,     0,    -1,    -1,    47,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    58,
      47,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,     0,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,     0,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,     0,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,     0,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
       0,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,     0,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,     0,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,     0,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,     0,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,     0,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,     0,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    12,    13,    -1,    -1,    51,    17,    18,    54,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    12,    13,    -1,    -1,
      51,    17,    18,    54,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    12,    13,    -1,    -1,    51,    17,    18,    54,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    12,    13,    -1,    -1,
      51,    17,    18,    54,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    12,    13,    -1,    -1,    51,    17,    18,    54,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    12,    13,    -1,    -1,
      51,    17,    18,    54,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    12,    13,    -1,    -1,    51,    17,    18,    54,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    12,    13,    -1,    -1,
      51,    17,    18,    54,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    12,    13,    -1,    -1,    51,    17,    18,    54,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    54,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    54,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    54,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    54,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    54,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    54,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    54,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    54,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    54,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      54,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    54,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    54,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    54,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    54,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    54,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    12,    13,    49,
      -1,    51,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    12,    13,    49,    -1,    51,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    12,    13,    49,
      -1,    51,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    12,    13,    49,    -1,    51,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    12,    13,    49,
      -1,    51,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    -1,    -1,    17,    18,    51,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    -1,    -1,    17,    18,    51,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    -1,    -1,    17,    18,
      51,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    -1,    -1,
      17,    18,    51,    20,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      -1,    -1,    17,    18,    51,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    47,    -1,    17,    18,    51,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    47,    -1,    17,    18,    51,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    47,    -1,    17,    18,
      51,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    47,    -1,
      17,    18,    51,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      47,    -1,    17,    18,    51,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    -1,    -1,    17,    18,    51,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    -1,    -1,    17,    18,    51,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    -1,    -1,    17,    18,
      51,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    -1,    -1,
      17,    18,    51,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      -1,    -1,    17,    18,    51,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    12,    13,    49,    -1,    51,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    12,    13,    49,
      -1,    51,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    12,    13,    49,    -1,    51,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    12,    13,    49,
      -1,    51,    17,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    -1,    -1,    17,    18,    51,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    -1,    -1,    17,    18,    51,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    -1,    -1,    17,    18,
      51,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    -1,    -1,
      17,    18,    51,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      47,    -1,    17,    18,    51,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    47,    -1,    17,    18,    51,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    47,    -1,    17,    18,    51,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    12,    13,    -1,    47,    -1,    17,    18,
      51,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    12,    13,    -1,    -1,    -1,
      17,    18,    51,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      -1,    -1,    17,    18,    51,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    12,
      13,    -1,    -1,    -1,    17,    18,    51,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    -1,    -1,    17,    18,    51,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    12,    13,    -1,    -1,    49,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    12,    13,    -1,
      -1,    49,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    -1,
      12,    13,    -1,    -1,    49,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    12,    13,    -1,    -1,    49,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    12,    13,    -1,    -1,
      49,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    12,
      13,    -1,    -1,    49,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    12,    13,    -1,    -1,    49,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    12,    13,    -1,    -1,    49,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    42,    43,    -1,    12,    13,
      -1,    -1,    49,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    12,    13,    -1,    -1,    49,    17,    18,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    12,    13,    -1,    -1,    49,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    12,    13,    -1,    -1,    49,    17,    18,    -1,    -1,
      -1,    22,    -1,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    36,    49,    38,
      39,    40,    41,    42,    43,    -1,    12,    13,    -1,    -1,
      49,    17,    18,    -1,    -1,    -1,    22,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    32,    33,
      34,    35,    36,    49,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    47,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    47,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    47,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    47,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    47,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    47,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    47,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    47,    -1,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    47,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    47,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    47,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    47,
      -1,    17,    18,    -1,    -1,    -1,    22,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    47,    -1,    17,    18,    -1,    -1,    -1,
      22,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    47,    -1,    17,
      18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    22,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    22,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    14,    19,
      25,    27,    30,    31,    39,    46,    50,    52,    53,    55,
      60,    61,    62,    63,    64,    65,    66,    67,    70,    45,
      48,    61,    61,    71,    72,    46,    61,     5,    46,    64,
       5,    16,    72,    78,    79,    64,    10,    15,    68,    69,
      61,    77,     0,    12,    13,    17,    18,    22,    32,    33,
      34,    35,    36,    38,    39,    40,    41,    42,    43,    66,
      28,    51,    10,    29,    69,    62,    46,    49,    20,    11,
      15,    26,     5,    15,    23,    24,    28,    52,    74,    75,
      76,    72,    49,    43,    47,    47,    58,    15,    61,    52,
      10,    15,    54,    56,    66,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      74,    74,    29,    78,    62,    61,    61,    61,    62,    53,
      73,    68,    51,    57,    47,    62,    61,    45,    48,    78,
      61,    47,    61,    28,    47,    21,    47,    47,    61,    49,
      75,    76,    52,    75,    76,    61,    62,     5,    47,    47,
      66,    45,    61,    54,    49,    45,    62,    73,    62,    49,
       3,     4,     5,     8,     9,    14,    19,    25,    27,    30,
      31,    39,    46,    50,    52,    53,    55,    62,    63,    64,
      65,    66,    67,    70,     3,     4,     5,     8,     9,    14,
      19,    25,    27,    30,    31,    39,    46,    50,    52,    53,
      55,    62,    63,    64,    65,    66,    67,    70,     3,     4,
       5,     8,     9,    14,    19,    25,    27,    30,    31,    39,
      46,    50,    52,    53,    55,    62,    63,    64,    65,    66,
      67,    70,    15,    24,    74,     3,     4,     5,     8,     9,
      14,    19,    25,    27,    30,    31,    39,    46,    50,    52,
      53,    55,    62,    63,    64,    65,    66,    67,    70,     3,
       4,     5,     8,     9,    25,    30,    46,    52,    53,    55,
      67,    70,     5,    15,    28,    52,    75,    76,     5,    15,
      28,    52,    75,    76,    15,    10,    15,     3,     4,     5,
       8,     9,    14,    19,    25,    27,    30,    31,    39,    46,
      50,    52,    53,    55,    62,    63,    64,    65,    66,    67,
      70,     3,     4,     5,     8,     9,    14,    19,    25,    27,
      30,    31,    39,    46,    50,    52,    53,    55,    62,    63,
      64,    65,    66,    67,    70,    51,    51,     5,    15,    28,
      52,    45,    48,    61,    61,    71,    72,    46,    61,     5,
      46,    64,    72,    78,    64,    68,    61,    77,    12,    13,
      17,    18,    22,    32,    33,    34,    35,    36,    38,    39,
      40,    41,    42,    43,    66,    28,    51,    29,    69,    45,
      48,    61,    61,    71,    72,    46,    61,     5,    46,    64,
      72,    78,    64,    68,    61,    77,    12,    13,    17,    18,
      22,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    43,    66,    28,    51,    29,    69,    45,    48,    61,
      61,    71,    72,    46,    61,     5,    46,    64,    72,    78,
      64,    68,    61,    77,    12,    13,    17,    18,    22,    32,
      33,    34,    35,    36,    38,    39,    40,    41,    42,    43,
      66,    28,    51,    29,    69,    61,    53,    73,    57,    45,
      48,    61,    61,    71,    72,    46,    61,     5,    46,    64,
      72,    78,    64,    68,    61,    77,    12,    13,    17,    18,
      22,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    43,    66,    28,    51,    29,    69,    71,    46,    72,
      68,    61,    77,    28,    51,    29,    69,    61,    68,    61,
      68,    61,    61,    45,    48,    61,    61,    71,    72,    46,
      61,     5,    46,    64,    72,    78,    64,    68,    61,    77,
      12,    13,    17,    18,    22,    32,    33,    34,    35,    36,
      38,    39,    40,    41,    42,    43,    66,    28,    51,    29,
      69,    45,    48,    61,    61,    71,    72,    46,    61,     5,
      46,    64,    72,    78,    64,    68,    61,    77,    12,    13,
      17,    18,    22,    32,    33,    34,    35,    36,    38,    39,
      40,    41,    42,    43,    66,    28,    51,    29,    69,    75,
      76,    75,    76,    61,    68,    62,    46,    49,    20,    26,
      23,    72,    49,    47,    47,    52,    54,    56,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,     5,    15,    28,    52,    74,    75,    76,
       5,    15,    28,    52,    74,    75,    76,    29,    62,    46,
      49,    20,    26,    23,    72,    49,    47,    47,    52,    54,
      56,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,     5,    15,    28,    52,
      74,    75,    76,     5,    15,    28,    52,    74,    75,    76,
      29,    62,    46,    49,    20,    26,    23,    72,    49,    47,
      47,    52,    54,    56,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,     5,
      15,    28,    52,    74,    75,    76,     5,    15,    28,    52,
      74,    75,    76,    29,    47,    61,    49,    61,    62,    46,
      49,    20,    26,    23,    72,    49,    47,    47,    52,    54,
      56,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,     5,    15,    28,    52,
      74,    75,    76,     5,    15,    28,    52,    74,    75,    76,
      29,    26,    72,    47,    52,    54,    56,     5,    15,    28,
      52,    74,    75,    76,    29,    47,    52,    47,    52,    47,
      47,    62,    46,    49,    20,    26,    23,    72,    49,    47,
      47,    52,    54,    56,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,     5,
      15,    28,    52,    74,    75,    76,     5,    15,    28,    52,
      74,    75,    76,    29,    62,    46,    49,    20,    26,    23,
      72,    49,    47,    47,    52,    54,    56,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,     5,    15,    28,    52,    74,    75,    76,     5,
      15,    28,    52,    74,    75,    76,    29,    47,    52,    78,
      62,    61,    62,    47,    62,    45,    48,    61,    68,    51,
      61,    68,    28,    51,    78,    62,    61,    62,    47,    62,
      45,    48,    61,    68,    51,    61,    68,    28,    51,    78,
      62,    61,    62,    47,    62,    45,    48,    61,    68,    51,
      61,    68,    28,    51,    54,    49,    78,    62,    61,    62,
      47,    62,    45,    48,    61,    68,    51,    61,    68,    28,
      51,    47,    61,    68,    28,    51,    78,    62,    61,    62,
      47,    62,    45,    48,    61,    68,    51,    61,    68,    28,
      51,    78,    62,    61,    62,    47,    62,    45,    48,    61,
      68,    51,    61,    68,    28,    51,    47,    21,    62,     5,
      47,    52,    75,    76,    47,    52,    66,    75,    76,    47,
      21,    62,     5,    47,    52,    75,    76,    47,    52,    66,
      75,    76,    47,    21,    62,     5,    47,    52,    75,    76,
      47,    52,    66,    75,    76,    73,    47,    21,    62,     5,
      47,    52,    75,    76,    47,    52,    66,    75,    76,    47,
      52,    66,    75,    76,    47,    21,    62,     5,    47,    52,
      75,    76,    47,    52,    66,    75,    76,    47,    21,    62,
       5,    47,    52,    75,    76,    47,    52,    66,    75,    76,
      45,    61,    45,    45,    61,    45,    45,    61,    45,    49,
      45,    61,    45,    45,    61,    45,    45,    61,    45,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     5,     7,     7,     4,     4,
       4,     1,     6,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     1,     3,     5,     2,     1,     1,
       1,     1,     3,     3,     2,     3,     1,     1,     3,     4,
       3,     3,     1,     1,     0,     2,     4,     3,     4,     1,
       1,     2,     4,     0,     5,     4,     7,     0,     2,     2,
       0,     3,     3,     1,     1,     1,     1,     3,     3,     2,
       0,     3,     1,     0,     1,     1,     3
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    67,     0,    83,     0,    67,     0,    83,     0,    67,
       0,    83,     0,    67,     0,    83,     0,    67,     0,    83,
       0,    67,     0,    83,     0,    67,     0,    83,     0
};


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, void* scanner, Parsed*& parsed, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, scanner, parsed, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FLOAT", "INT", "ID",
  "PATH", "HPATH", "SPATH", "URI", "STR", "IND_STR", "AND", "OR", "ASSERT",
  "DOLLAR_CURLY", "ELLIPSIS", "EQ", "NEQ", "IF", "THEN", "ELSE", "IMPL",
  "IN", "INHERIT", "IND_STRING_OPEN", "IND_STRING_CLOSE", "LET", "OR_KW",
  "PATH_END", "REC", "WITH", "'<'", "'>'", "LEQ", "GEQ", "UPDATE", "NOT",
  "'+'", "'-'", "'*'", "'/'", "CONCAT", "'?'", "NEGATE", "':'", "'{'",
  "'}'", "'@'", "';'", "'!'", "'.'", "'\"'", "'('", "')'", "'['", "']'",
  "'='", "','", "$accept", "start", "expr", "expr_function", "expr_if",
  "expr_op", "expr_app", "expr_select", "expr_simple", "string_parts",
  "string_parts_interpolated", "path_start", "ind_string_parts", "binds",
  "attrs", "attrpath", "attr", "string_attr", "expr_list", "formals",
  "formal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* scanner, Parsed*& parsed)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (parsed);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* scanner, Parsed*& parsed)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, parsed);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value, Location, scanner, parsed);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, void* scanner, Parsed*& parsed);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp, yyGLRStack* yystackp, void* scanner, Parsed*& parsed)
{
  yysymbol_kind_t yytoken;
  YY_USE (scanner);
  YY_USE (parsed);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex (&yylval, &yylloc, scanner, parsed);
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, void* scanner, Parsed*& parsed)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yylocp);
  YY_USE (scanner);
  YY_USE (parsed);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, scanner, parsed, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule, scanner, parsed));
  switch (yyrule)
    {
  case 2: /* start: expr  */
#line 94 "src/parser/generator.y"
         {
    parsed->expression = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
  }
#line 8116 "src/vendored/parser.cc"
    break;

  case 3: /* expr: expr_function  */
#line 100 "src/parser/generator.y"
                  {
    ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
  }
#line 8124 "src/vendored/parser.cc"
    break;

  case 4: /* expr_function: ID ':' expr_function  */
#line 106 "src/parser/generator.y"
                         {
    ((*yyvalp).expression) = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindSimple,
      .head_ptr = (any*) new FunctionHeadSimple{
        .identifier=(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string),
      },
      .body = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8139 "src/vendored/parser.cc"
    break;

  case 5: /* expr_function: '{' formals '}' ':' expr_function  */
#line 116 "src/parser/generator.y"
                                      {
    ((*yyvalp).expression) = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindDestructured,
      .head_ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.function_head_destructured),
      .body = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8152 "src/vendored/parser.cc"
    break;

  case 6: /* expr_function: '{' formals '}' '@' ID ':' expr_function  */
#line 124 "src/parser/generator.y"
                                             {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.function_head_destructured)->identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierRightAt;
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.function_head_destructured)->identifier_ptr = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
    ((*yyvalp).expression) = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindDestructured,
      .head_ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.function_head_destructured),
      .body = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8167 "src/vendored/parser.cc"
    break;

  case 7: /* expr_function: ID '@' '{' formals '}' ':' expr_function  */
#line 134 "src/parser/generator.y"
                                             {
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.function_head_destructured)->identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierLeftAt;
    (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.function_head_destructured)->identifier_ptr = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string);
    ((*yyvalp).expression) = to_expr(new Function{
      .head_kind = FunctionHeadKind::FunctionHeadKindDestructured,
      .head_ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.function_head_destructured),
      .body = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8182 "src/vendored/parser.cc"
    break;

  case 8: /* expr_function: ASSERT expr ';' expr_function  */
#line 144 "src/parser/generator.y"
                                  {
    ((*yyvalp).expression) = to_expr(new Assert{
      .expression = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .target = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8194 "src/vendored/parser.cc"
    break;

  case 9: /* expr_function: WITH expr ';' expr_function  */
#line 151 "src/parser/generator.y"
                                {
    ((*yyvalp).expression) = to_expr(new With{
      .expression = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .target = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8206 "src/vendored/parser.cc"
    break;

  case 10: /* expr_function: LET binds IN expr_function  */
#line 158 "src/parser/generator.y"
                               {
    ((*yyvalp).expression) = to_expr(new LetIn{
      .bindings = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.bindings),
      .target = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8218 "src/vendored/parser.cc"
    break;

  case 11: /* expr_function: expr_if  */
#line 165 "src/parser/generator.y"
            {
    ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
  }
#line 8226 "src/vendored/parser.cc"
    break;

  case 12: /* expr_if: IF expr THEN expr ELSE expr  */
#line 171 "src/parser/generator.y"
                                {
    ((*yyvalp).expression) = to_expr(new IfThenElse{
      .predicate = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.expression),
      .then = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .else_ = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8239 "src/vendored/parser.cc"
    break;

  case 13: /* expr_if: expr_op  */
#line 179 "src/parser/generator.y"
            {
    ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
  }
#line 8247 "src/vendored/parser.cc"
    break;

  case 14: /* expr_op: '!' expr_op  */
#line 185 "src/parser/generator.y"
                          {
    ((*yyvalp).expression) = to_expr(new UnaryOperation{
      .operator_ = UnaryOperator::UnaryOperatorNot,
      .operand = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8259 "src/vendored/parser.cc"
    break;

  case 15: /* expr_op: '-' expr_op  */
#line 192 "src/parser/generator.y"
                             {
    ((*yyvalp).expression) = to_expr(new UnaryOperation{
      .operator_ = UnaryOperator::UnaryOperatorNegate,
      .operand = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
      .span = SPAN,
    });
  }
#line 8271 "src/vendored/parser.cc"
    break;

  case 16: /* expr_op: expr_op EQ expr_op  */
#line 199 "src/parser/generator.y"
                       {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorEqualTo,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8283 "src/vendored/parser.cc"
    break;

  case 17: /* expr_op: expr_op NEQ expr_op  */
#line 206 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorNotEqualTo,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8295 "src/vendored/parser.cc"
    break;

  case 18: /* expr_op: expr_op '<' expr_op  */
#line 213 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorLessThan,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8307 "src/vendored/parser.cc"
    break;

  case 19: /* expr_op: expr_op LEQ expr_op  */
#line 220 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorLessThanOrEqualTo,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8319 "src/vendored/parser.cc"
    break;

  case 20: /* expr_op: expr_op '>' expr_op  */
#line 227 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorGreaterThan,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8331 "src/vendored/parser.cc"
    break;

  case 21: /* expr_op: expr_op GEQ expr_op  */
#line 234 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorGreaterThanOrEqualTo,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8343 "src/vendored/parser.cc"
    break;

  case 22: /* expr_op: expr_op AND expr_op  */
#line 241 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorLogicalAnd,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8355 "src/vendored/parser.cc"
    break;

  case 23: /* expr_op: expr_op OR expr_op  */
#line 248 "src/parser/generator.y"
                       {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorLogicalOr,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8367 "src/vendored/parser.cc"
    break;

  case 24: /* expr_op: expr_op IMPL expr_op  */
#line 255 "src/parser/generator.y"
                         {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorImplication,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8379 "src/vendored/parser.cc"
    break;

  case 25: /* expr_op: expr_op UPDATE expr_op  */
#line 262 "src/parser/generator.y"
                           {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorUpdate,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8391 "src/vendored/parser.cc"
    break;

  case 26: /* expr_op: expr_op '?' attrpath  */
#line 269 "src/parser/generator.y"
                         {
    ((*yyvalp).expression) = to_expr(new HasAttribute{
      .expression = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .attribute_path = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.parts),
    });
  }
#line 8402 "src/vendored/parser.cc"
    break;

  case 27: /* expr_op: expr_op '+' expr_op  */
#line 275 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorAddition,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8414 "src/vendored/parser.cc"
    break;

  case 28: /* expr_op: expr_op '-' expr_op  */
#line 282 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorSubtraction,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8426 "src/vendored/parser.cc"
    break;

  case 29: /* expr_op: expr_op '*' expr_op  */
#line 289 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorMultiplication,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8438 "src/vendored/parser.cc"
    break;

  case 30: /* expr_op: expr_op '/' expr_op  */
#line 296 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorDivision,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8450 "src/vendored/parser.cc"
    break;

  case 31: /* expr_op: expr_op CONCAT expr_op  */
#line 303 "src/parser/generator.y"
                           {
    ((*yyvalp).expression) = to_expr(new BinaryOperation{
      .left = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .operator_ = BinaryOperator::BinaryOperatorConcatenation,
      .right = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8462 "src/vendored/parser.cc"
    break;

  case 32: /* expr_op: expr_app  */
#line 310 "src/parser/generator.y"
             {
    ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
  }
#line 8470 "src/vendored/parser.cc"
    break;

  case 33: /* expr_app: expr_app expr_select  */
#line 316 "src/parser/generator.y"
                         {
    if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression)->kind == ExpressionKind::ExpressionKindFunctionApplication) {
      ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
    } else {
      ((*yyvalp).expression) = to_expr(new FunctionApplication{
        .function = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
        .arguments = LL_new(),
      });
    }

    LL_insert(((FunctionApplication*) ((*yyvalp).expression)->ptr)->arguments, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression));
  }
#line 8487 "src/vendored/parser.cc"
    break;

  case 34: /* expr_app: expr_select  */
#line 328 "src/parser/generator.y"
                {
    ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
  }
#line 8495 "src/vendored/parser.cc"
    break;

  case 35: /* expr_select: expr_simple '.' attrpath  */
#line 334 "src/parser/generator.y"
                             {
    ((*yyvalp).expression) = to_expr(new PropertyAccess {
      .expression = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.expression),
      .attribute_path = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.parts),
      .default_ = nullptr,
    });
  }
#line 8507 "src/vendored/parser.cc"
    break;

  case 36: /* expr_select: expr_simple '.' attrpath OR_KW expr_select  */
#line 341 "src/parser/generator.y"
                                               {
    ((*yyvalp).expression) = to_expr(new PropertyAccess {
      .expression = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.expression),
      .attribute_path = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.parts),
      .default_ = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    });
  }
#line 8519 "src/vendored/parser.cc"
    break;

  case 37: /* expr_select: expr_simple OR_KW  */
#line 348 "src/parser/generator.y"
                      {
    ((*yyvalp).expression) = to_expr(new FunctionApplication{
      .function = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
      .arguments = LL_new(),
    });

    LL_insert(((FunctionApplication*) ((*yyvalp).expression)->ptr)->arguments, to_expr(new Identifier{
      .id = Str_new("or", 2),
      .span = SPAN,
    }));
    TRIVIA_BOUNDARY;
  }
#line 8536 "src/vendored/parser.cc"
    break;

  case 38: /* expr_select: expr_simple  */
#line 360 "src/parser/generator.y"
                {
    ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression);
  }
#line 8544 "src/vendored/parser.cc"
    break;

  case 39: /* expr_simple: FLOAT  */
#line 366 "src/parser/generator.y"
          {
    ((*yyvalp).expression) = to_expr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.float_));
    TRIVIA_BOUNDARY;
  }
#line 8553 "src/vendored/parser.cc"
    break;

  case 40: /* expr_simple: ID  */
#line 370 "src/parser/generator.y"
       {
    ((*yyvalp).expression) = to_expr(new Identifier{
      .id = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8565 "src/vendored/parser.cc"
    break;

  case 41: /* expr_simple: INT  */
#line 377 "src/parser/generator.y"
        {
    ((*yyvalp).expression) = to_expr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer));
    TRIVIA_BOUNDARY;
  }
#line 8574 "src/vendored/parser.cc"
    break;

  case 42: /* expr_simple: '"' string_parts '"'  */
#line 381 "src/parser/generator.y"
                         {
    ((*yyvalp).expression) = to_expr(new String_{
      .parts = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8586 "src/vendored/parser.cc"
    break;

  case 43: /* expr_simple: IND_STRING_OPEN ind_string_parts IND_STRING_CLOSE  */
#line 388 "src/parser/generator.y"
                                                      {
    ((*yyvalp).expression) = to_expr(new IndentedString{
      .parts = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8598 "src/vendored/parser.cc"
    break;

  case 44: /* expr_simple: path_start PATH_END  */
#line 395 "src/parser/generator.y"
                        {
    ((*yyvalp).expression) = to_expr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.path));
    TRIVIA_BOUNDARY;
  }
#line 8607 "src/vendored/parser.cc"
    break;

  case 45: /* expr_simple: path_start string_parts_interpolated PATH_END  */
#line 399 "src/parser/generator.y"
                                                  {
    // TODO
    // std::copy($2->begin(), $2->end(), std::back_inserter(*($1->parts)));
    delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts);
    ((*yyvalp).expression) = to_expr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.path));
    TRIVIA_BOUNDARY;
  }
#line 8619 "src/vendored/parser.cc"
    break;

  case 46: /* expr_simple: URI  */
#line 406 "src/parser/generator.y"
        {
    ((*yyvalp).expression) = to_expr(new Uri{
      .uri = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8631 "src/vendored/parser.cc"
    break;

  case 47: /* expr_simple: SPATH  */
#line 413 "src/parser/generator.y"
          {
    ((*yyvalp).expression) = to_expr(new SearchNixPath{
      .path = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8643 "src/vendored/parser.cc"
    break;

  case 48: /* expr_simple: '(' expr ')'  */
#line 420 "src/parser/generator.y"
                 {
    ((*yyvalp).expression) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression);
    TRIVIA_BOUNDARY;
  }
#line 8652 "src/vendored/parser.cc"
    break;

  case 49: /* expr_simple: REC '{' binds '}'  */
#line 424 "src/parser/generator.y"
                      {
    ((*yyvalp).expression) = to_expr(new Map{
      .recursive = true,
      .bindings = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.bindings),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8665 "src/vendored/parser.cc"
    break;

  case 50: /* expr_simple: '{' binds '}'  */
#line 432 "src/parser/generator.y"
                  {
    ((*yyvalp).expression) = to_expr(new Map{
      .recursive = false,
      .bindings = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.bindings),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8678 "src/vendored/parser.cc"
    break;

  case 51: /* expr_simple: '[' expr_list ']'  */
#line 440 "src/parser/generator.y"
                      {
    ((*yyvalp).expression) = to_expr(new List{
      .elements = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expressions),
      .span = SPAN,
    });
    TRIVIA_BOUNDARY;
  }
#line 8690 "src/vendored/parser.cc"
    break;

  case 52: /* string_parts: STR  */
#line 450 "src/parser/generator.y"
        {
    ((*yyvalp).parts) = LL_new();
    LL_insert(((*yyvalp).parts), new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.util_string),
        .span = SPAN,
      },
    });
    TRIVIA_BOUNDARY;
  }
#line 8706 "src/vendored/parser.cc"
    break;

  case 53: /* string_parts: string_parts_interpolated  */
#line 461 "src/parser/generator.y"
                              {
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.parts);
  }
#line 8714 "src/vendored/parser.cc"
    break;

  case 54: /* string_parts: %empty  */
#line 464 "src/parser/generator.y"
    {
    ((*yyvalp).parts) = LL_new();
    TRIVIA_BOUNDARY;
  }
#line 8723 "src/vendored/parser.cc"
    break;

  case 55: /* string_parts_interpolated: string_parts_interpolated STR  */
#line 471 "src/parser/generator.y"
                                  {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts), new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.util_string),
        .span = SPAN,
      },
    });
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts);
    TRIVIA_BOUNDARY;
  }
#line 8739 "src/vendored/parser.cc"
    break;

  case 56: /* string_parts_interpolated: string_parts_interpolated DOLLAR_CURLY expr '}'  */
#line 482 "src/parser/generator.y"
                                                    {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.parts), new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
    });
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.parts);
    TRIVIA_BOUNDARY;
  }
#line 8752 "src/vendored/parser.cc"
    break;

  case 57: /* string_parts_interpolated: DOLLAR_CURLY expr '}'  */
#line 490 "src/parser/generator.y"
                          {
    ((*yyvalp).parts) = LL_new();
    LL_insert(((*yyvalp).parts), new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
    });
    TRIVIA_BOUNDARY;
  }
#line 8765 "src/vendored/parser.cc"
    break;

  case 58: /* string_parts_interpolated: STR DOLLAR_CURLY expr '}'  */
#line 498 "src/parser/generator.y"
                              {
    ((*yyvalp).parts) = LL_new();
    LL_insert(((*yyvalp).parts), new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.util_string),
        .span = SPAN,
      },
    });
    LL_insert(((*yyvalp).parts), new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
    });
    TRIVIA_BOUNDARY;
  }
#line 8785 "src/vendored/parser.cc"
    break;

  case 59: /* path_start: PATH  */
#line 516 "src/parser/generator.y"
         {
    ((*yyvalp).path) = new Path{
      .parts = LL_new(),
      .span = SPAN,
    };
    LL_insert(((*yyvalp).path)->parts, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string),
          .should_unescape = false,
        },
        .span = SPAN,
      },
    });
    TRIVIA_BOUNDARY;
  }
#line 8807 "src/vendored/parser.cc"
    break;

  case 60: /* path_start: HPATH  */
#line 533 "src/parser/generator.y"
          {
    ((*yyvalp).path) = new Path{
      .parts = LL_new(),
      .span = SPAN,
    };
    LL_insert(((*yyvalp).path)->parts, new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string),
          .should_unescape = false,
        },
        .span = SPAN,
      },
    });
    TRIVIA_BOUNDARY;
  }
#line 8829 "src/vendored/parser.cc"
    break;

  case 61: /* ind_string_parts: ind_string_parts IND_STR  */
#line 553 "src/parser/generator.y"
                             {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts), new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.util_string),
        .span = SPAN,
      },
    });
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts);
    TRIVIA_BOUNDARY;
  }
#line 8845 "src/vendored/parser.cc"
    break;

  case 62: /* ind_string_parts: ind_string_parts DOLLAR_CURLY expr '}'  */
#line 564 "src/parser/generator.y"
                                           {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.parts), new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
    });
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.parts);
    TRIVIA_BOUNDARY;
  }
#line 8858 "src/vendored/parser.cc"
    break;

  case 63: /* ind_string_parts: %empty  */
#line 572 "src/parser/generator.y"
    {
    ((*yyvalp).parts) = LL_new();
    TRIVIA_BOUNDARY;
  }
#line 8867 "src/vendored/parser.cc"
    break;

  case 64: /* binds: binds attrpath '=' expr ';'  */
#line 579 "src/parser/generator.y"
                                {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.bindings), new Binding{
      .kind = BindingKind::BindingKindBinding,
      .ptr = (any*) new BindingKeyValue{
        .from = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.parts),
        .to = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
      },
    });
    ((*yyvalp).bindings) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.bindings);
    TRIVIA_BOUNDARY;
  }
#line 8883 "src/vendored/parser.cc"
    break;

  case 65: /* binds: binds INHERIT attrs ';'  */
#line 590 "src/parser/generator.y"
                            {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.bindings), new Binding{
      .kind = BindingKind::BindingKindInherit,
      .ptr = (any*) new BindingInherit{
        .from = nullptr,
        .attributes = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts),
        .span = SPAN,
      },
    });
    ((*yyvalp).bindings) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.bindings);
    TRIVIA_BOUNDARY;
  }
#line 8900 "src/vendored/parser.cc"
    break;

  case 66: /* binds: binds INHERIT '(' expr ')' attrs ';'  */
#line 602 "src/parser/generator.y"
                                         {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.bindings), new Binding{
      .kind = BindingKind::BindingKindInherit,
      .ptr = (any*) new BindingInherit{
        .from = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.expression),
        .attributes = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts),
        .span = SPAN,
      },
    });
    ((*yyvalp).bindings) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.bindings);
    TRIVIA_BOUNDARY;
  }
#line 8917 "src/vendored/parser.cc"
    break;

  case 67: /* binds: %empty  */
#line 614 "src/parser/generator.y"
    {
    ((*yyvalp).bindings) = LL_new();
    TRIVIA_BOUNDARY;
  }
#line 8926 "src/vendored/parser.cc"
    break;

  case 68: /* attrs: attrs attr  */
#line 621 "src/parser/generator.y"
               {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.part));
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts);
  }
#line 8935 "src/vendored/parser.cc"
    break;

  case 69: /* attrs: attrs string_attr  */
#line 625 "src/parser/generator.y"
                      {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.part));
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts);
  }
#line 8944 "src/vendored/parser.cc"
    break;

  case 70: /* attrs: %empty  */
#line 629 "src/parser/generator.y"
    {
    ((*yyvalp).parts) = LL_new();
    TRIVIA_BOUNDARY;
  }
#line 8953 "src/vendored/parser.cc"
    break;

  case 71: /* attrpath: attrpath '.' attr  */
#line 636 "src/parser/generator.y"
                      {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.parts), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.part));
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.parts);
  }
#line 8962 "src/vendored/parser.cc"
    break;

  case 72: /* attrpath: attrpath '.' string_attr  */
#line 640 "src/parser/generator.y"
                             {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.parts), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.part));
    ((*yyvalp).parts) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.parts);
  }
#line 8971 "src/vendored/parser.cc"
    break;

  case 73: /* attrpath: attr  */
#line 644 "src/parser/generator.y"
         {
    ((*yyvalp).parts) = LL_new();
    LL_insert(((*yyvalp).parts), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.part));
  }
#line 8980 "src/vendored/parser.cc"
    break;

  case 74: /* attrpath: string_attr  */
#line 648 "src/parser/generator.y"
                {
    ((*yyvalp).parts) = LL_new();
    LL_insert(((*yyvalp).parts), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.part));
  }
#line 8989 "src/vendored/parser.cc"
    break;

  case 75: /* attr: ID  */
#line 655 "src/parser/generator.y"
       {
    ((*yyvalp).part) = new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string),
          .should_unescape = false,
        },
        .span = SPAN,
      },
    };
    TRIVIA_BOUNDARY;
  }
#line 9007 "src/vendored/parser.cc"
    break;

  case 76: /* attr: OR_KW  */
#line 668 "src/parser/generator.y"
          {
    ((*yyvalp).part) = new Part{
      .kind = PartKind::PartKindRaw,
      .ptr = (any*) new PartRaw{
        .content = new UtilString{
          .content = Str_new("or", 2),
          .should_unescape = false,
        },
        .span = SPAN,
      },
    };
    TRIVIA_BOUNDARY;
  }
#line 9025 "src/vendored/parser.cc"
    break;

  case 77: /* string_attr: '"' string_parts '"'  */
#line 684 "src/parser/generator.y"
                         {
    ((*yyvalp).part) = new Part{
      .kind = PartKind::PartKindExpression,
      .ptr = (any*) to_expr(new String_{
        .parts = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.parts),
        .span = SPAN,
      }),
    };
    TRIVIA_BOUNDARY;
  }
#line 9040 "src/vendored/parser.cc"
    break;

  case 78: /* string_attr: DOLLAR_CURLY expr '}'  */
#line 694 "src/parser/generator.y"
                          {
    ((*yyvalp).part) = new Part{
      .kind = PartKind::PartKindInterpolation,
      .ptr = (any*) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expression),
    };
    TRIVIA_BOUNDARY;
  }
#line 9052 "src/vendored/parser.cc"
    break;

  case 79: /* expr_list: expr_list expr_select  */
#line 704 "src/parser/generator.y"
                          {
    LL_insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expressions), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression));
    ((*yyvalp).expressions) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.expressions);
  }
#line 9061 "src/vendored/parser.cc"
    break;

  case 80: /* expr_list: %empty  */
#line 708 "src/parser/generator.y"
    {
    ((*yyvalp).expressions) = LL_new();
    TRIVIA_BOUNDARY;
  }
#line 9070 "src/vendored/parser.cc"
    break;

  case 81: /* formals: formal ',' formals  */
#line 715 "src/parser/generator.y"
                       {
    ((*yyvalp).function_head_destructured) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.function_head_destructured);
    LL_insert(((*yyvalp).function_head_destructured)->arguments, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.function_head_destructured_argument));
  }
#line 9079 "src/vendored/parser.cc"
    break;

  case 82: /* formals: formal  */
#line 719 "src/parser/generator.y"
           {
    ((*yyvalp).function_head_destructured) = new FunctionHeadDestructured{
      .ellipsis = false,
      .identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierNone,
      .identifier_ptr = nullptr,
      .arguments = LL_new(),
    };
    LL_insert(((*yyvalp).function_head_destructured)->arguments, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.function_head_destructured_argument));
  }
#line 9093 "src/vendored/parser.cc"
    break;

  case 83: /* formals: %empty  */
#line 728 "src/parser/generator.y"
    {
    ((*yyvalp).function_head_destructured) = new FunctionHeadDestructured{
      .ellipsis = false,
      .identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierNone,
      .identifier_ptr = nullptr,
      .arguments = LL_new(),
    };
    TRIVIA_BOUNDARY;
  }
#line 9107 "src/vendored/parser.cc"
    break;

  case 84: /* formals: ELLIPSIS  */
#line 737 "src/parser/generator.y"
             {
    ((*yyvalp).function_head_destructured) = new FunctionHeadDestructured{
      .ellipsis = true,
      .identifier_kind = FunctionHeadDestructuredIdentifier::FunctionHeadDestructuredIdentifierNone,
      .identifier_ptr = nullptr,
      .arguments = LL_new(),
    };
    TRIVIA_BOUNDARY;
  }
#line 9121 "src/vendored/parser.cc"
    break;

  case 85: /* formal: ID  */
#line 749 "src/parser/generator.y"
       {
    ((*yyvalp).function_head_destructured_argument) = new FunctionHeadDestructuredArgument{
      .identifier = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string),
      .default_ = nullptr,
    };
    TRIVIA_BOUNDARY;
  }
#line 9133 "src/vendored/parser.cc"
    break;

  case 86: /* formal: ID '?' expr  */
#line 756 "src/parser/generator.y"
                {
    ((*yyvalp).function_head_destructured_argument) = new FunctionHeadDestructuredArgument{
      .identifier = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string),
      .default_ = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.expression),
    };
  }
#line 9144 "src/vendored/parser.cc"
    break;


#line 9148 "src/vendored/parser.cc"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void* scanner, Parsed*& parsed)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (parsed);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).float_); }
#line 9203 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).integer); }
#line 9209 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_ID: /* ID  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).string); }
#line 9215 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_PATH: /* PATH  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).string); }
#line 9221 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_HPATH: /* HPATH  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).string); }
#line 9227 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_SPATH: /* SPATH  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).string); }
#line 9233 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_URI: /* URI  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).string); }
#line 9239 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_STR: /* STR  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).util_string); }
#line 9245 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_IND_STR: /* IND_STR  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).util_string); }
#line 9251 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr: /* expr  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expression); }
#line 9257 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr_function: /* expr_function  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expression); }
#line 9263 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr_if: /* expr_if  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expression); }
#line 9269 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr_op: /* expr_op  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expression); }
#line 9275 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr_app: /* expr_app  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expression); }
#line 9281 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr_select: /* expr_select  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expression); }
#line 9287 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr_simple: /* expr_simple  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expression); }
#line 9293 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_string_parts: /* string_parts  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).parts); }
#line 9299 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_string_parts_interpolated: /* string_parts_interpolated  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).parts); }
#line 9305 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_path_start: /* path_start  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).path); }
#line 9311 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_ind_string_parts: /* ind_string_parts  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).parts); }
#line 9317 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_binds: /* binds  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).bindings); }
#line 9323 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_attrs: /* attrs  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).parts); }
#line 9329 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_attrpath: /* attrpath  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).parts); }
#line 9335 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_attr: /* attr  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).part); }
#line 9341 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_string_attr: /* string_attr  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).part); }
#line 9347 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_expr_list: /* expr_list  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).expressions); }
#line 9353 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_formals: /* formals  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).function_head_destructured); }
#line 9359 "src/vendored/parser.cc"
        break;

    case YYSYMBOL_formal: /* formal  */
#line 31 "src/parser/generator.y"
            { delete ((*yyvaluep).function_head_destructured_argument); }
#line 9365 "src/vendored/parser.cc"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, void* scanner, Parsed*& parsed)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval, &yys->yyloc, scanner, parsed);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, scanner, parsed);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, void* scanner, Parsed*& parsed)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , scanner, parsed);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, void* scanner, Parsed*& parsed)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp, yylocp, scanner, parsed);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp, yylocp, scanner, parsed);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval, void* scanner, Parsed*& parsed)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval, &yyloc, scanner, parsed);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval, &yyloc);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, void* scanner, Parsed*& parsed);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, void* scanner, Parsed*& parsed)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, scanner, parsed));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, scanner, parsed));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, void* scanner, Parsed*& parsed)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, scanner, parsed);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, scanner, parsed);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp, yylocp, scanner, parsed);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, void* scanner, Parsed*& parsed)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (yylocp, scanner, parsed, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, void* scanner, Parsed*& parsed)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, scanner, parsed);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, scanner, parsed);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, void* scanner, Parsed*& parsed)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, scanner, parsed);
              return yyreportAmbiguity (yybest, yyp, yylocp, scanner, parsed);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, scanner, parsed);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other, &yydummy, scanner, parsed);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval, yylocp, scanner, parsed);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, scanner, parsed);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, void* scanner, Parsed*& parsed)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , scanner, parsed));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn, YYLTYPE *yylocp, void* scanner, Parsed*& parsed)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], scanner, parsed);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner, parsed);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], scanner, parsed);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, scanner, parsed));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], scanner, parsed);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp, void* scanner, Parsed*& parsed)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (&yylloc, scanner, parsed, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, scanner, parsed, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, void* scanner, Parsed*& parsed)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, scanner, parsed, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, scanner, parsed);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, scanner, parsed);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, &yylloc, scanner, parsed, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, scanner, parsed);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, scanner, parsed, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void* scanner, Parsed*& parsed)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, scanner, parsed);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, scanner, parsed));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner, parsed);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack, scanner, parsed);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, scanner, parsed));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, scanner, parsed));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, scanner, parsed, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, scanner, parsed));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, scanner, parsed);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, scanner, parsed));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, scanner, parsed);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (&yylloc, scanner, parsed, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, scanner, parsed);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, scanner, parsed);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc




#line 764 "src/parser/generator.y"


#include "parser/parse.cc"
