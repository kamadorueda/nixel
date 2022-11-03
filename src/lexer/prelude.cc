// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include "vendored/parser.hh"

#define POP_STATE() yy_pop_state(yyscanner)
#define SPAN \
  new Span { \
    .start = \
      new Position{ \
        .line = (size_t)yylloc->first_line, \
        .column = (size_t)yylloc->first_column, \
      }, \
    .end = new Position{ \
      .line = (size_t)yylloc->last_line, \
      .column = (size_t)yylloc->last_column, \
    }, \
  }

#define PUSH_STATE(state) yy_push_state(state, yyscanner)
#define YY_USER_INIT init_yylloc(yylloc)
#define YY_USER_ACTION update_yylloc(yylloc, yytext, yyleng);

YYLTYPE prev_yylloc;

static inline void init_yylloc(YYLTYPE* loc) {
  loc->first_line = loc->last_line = 1;
  loc->first_column = loc->last_column = 1;
}

static inline void update_yylloc(YYLTYPE* loc, const char* s, size_t len) {
  prev_yylloc = *loc;

  loc->first_line = loc->last_line;
  loc->first_column = loc->last_column;

  for (size_t i = 0; i < len; i++) {
    switch (*s++) {
      case '\r':
        if (*s == '\n') {
          i++;
          s++;
        }
        [[fallthrough]];
      case '\n':
        ++loc->last_line;
        loc->last_column = 1;
        break;
      default:
        ++loc->last_column;
    }
  }
}
