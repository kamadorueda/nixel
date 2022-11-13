// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#include "types.hh"

Str* Str_clone(const char*);
Str* Str_clone(const char*, size_t);
Str* Str_new(const char*);
Str* Str_new(const char*, size_t);

LL* LL_new();

#define _(Ptr) void LL_insert(LL* ll, Ptr* ptr);

_(Binding)
_(Expression)
_(FunctionHeadDestructuredArgument)
_(Part)
_(Trivia)

#undef _

#define TRIVIA_BOUNDARY \
  LL_insert( \
    parsed->trivia, \
    new Trivia{ \
      .kind = TriviaKind::TriviaKindBoundary, \
      .ptr = nullptr, \
      .span = SPAN, \
    } \
  )
