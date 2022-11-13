// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#include <cstring>

#include "utils.hh"

Str* Str_new(const char* ptr, size_t len) {
  return new Str{.ptr = ptr, .len = len};
}

Str* Str_new(const char* ptr) { return Str_new(ptr, strlen(ptr)); }

Str* Str_clone(const char* ptr) { return Str_clone(ptr, strlen(ptr)); }

Str* Str_clone(const char* ptr, size_t len) {
  char* clone = new char[len];
  memcpy(clone, ptr, len * sizeof(char));
  return new Str{.ptr = clone, .len = len};
}

LL* LL_new() { return new LL{.next = nullptr}; }

#define _(Ptr) \
  void LL_insert(LL* ll, Ptr* ptr) { \
    ll->next = new Node{.ptr = (any*)ptr, .next = ll->next}; \
  }

_(Binding)
_(Expression)
_(FunctionHeadDestructuredArgument)
_(Part)
_(Trivia)

#undef _
