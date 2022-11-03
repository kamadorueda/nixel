// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#ifndef BISON_HEADER
#define BISON_HEADER

#include "types.hh"
#include "utils.hh"

#define YY_DECL \
  int yylex( \
    YYSTYPE* yylval_param, \
    YYLTYPE* yylloc_param, \
    yyscan_t yyscanner, \
    Parsed*& parsed \
  )

#endif
