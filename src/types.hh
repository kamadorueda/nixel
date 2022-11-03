// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

#pragma once
#include <stddef.h>

typedef void any;

enum BinaryOperator {
  BinaryOperatorAddition,
  BinaryOperatorConcatenation,
  BinaryOperatorEqualTo,
  BinaryOperatorGreaterThan,
  BinaryOperatorGreaterThanOrEqualTo,
  BinaryOperatorDivision,
  BinaryOperatorImplication,
  BinaryOperatorLessThan,
  BinaryOperatorLessThanOrEqualTo,
  BinaryOperatorLogicalAnd,
  BinaryOperatorLogicalOr,
  BinaryOperatorMultiplication,
  BinaryOperatorNotEqualTo,
  BinaryOperatorSubtraction,
  BinaryOperatorUpdate,
};

enum BindingKind {
  BindingKindBinding,
  BindingKindInherit,
};

enum ExpressionKind {
  ExpressionKindAssert,
  ExpressionKindBinaryOperation,
  ExpressionKindError,
  ExpressionKindFloat,
  ExpressionKindFunction,
  ExpressionKindFunctionApplication,
  ExpressionKindHasAttribute,
  ExpressionKindIdentifier,
  ExpressionKindIfThenElse,
  ExpressionKindIndentedString,
  ExpressionKindInteger,
  ExpressionKindLetIn,
  ExpressionKindList,
  ExpressionKindMap,
  ExpressionKindPath,
  ExpressionKindPropertyAccess,
  ExpressionKindSearchNixPath,
  ExpressionKindString_,
  ExpressionKindUnaryOperation,
  ExpressionKindUri,
  ExpressionKindWith,
};

enum FunctionHeadKind {
  FunctionHeadKindDestructured,
  FunctionHeadKindSimple,
};

enum FunctionHeadDestructuredIdentifier {
  FunctionHeadDestructuredIdentifierNone,
  FunctionHeadDestructuredIdentifierLeftAt,
  FunctionHeadDestructuredIdentifierRightAt,
};

enum PartKind {
  PartKindExpression,
  PartKindInterpolation,
  PartKindRaw,
};

enum TriviaKind {
  TriviaKindBoundary,
  TriviaKindComment,
  TriviaKindMultilineComment,
  TriviaKindWhitespace,
};

enum UnaryOperator {
  UnaryOperatorNot,
  UnaryOperatorNegate,
};

struct Node {
  any* ptr;
  Node* next;
};

struct LL {
  Node* next;
};

struct Part {
  PartKind kind;
  any* ptr;
};

struct Position {
  size_t line;
  size_t column;
};

struct Span {
  Position* start;
  Position* end;
};

struct Str {
  const char* ptr;
  size_t len;
};

struct Trivia {
  TriviaKind kind;
  Str* ptr;
  Span* span;
};

struct UtilString {
  Str* content;
  bool should_unescape;
};

struct Expression {
  ExpressionKind kind;
  any* ptr;
};

struct Parsed {
  Expression* expression;
  LL* trivia;  // Trivia
};

struct Assert {
  Expression* expression;
  Expression* target;
  Span* span;
};

struct BinaryOperation {
  Expression* left;
  BinaryOperator operator_;
  Expression* right;
};

struct Binding {
  BindingKind kind;
  any* ptr;
};

struct BindingKeyValue {
  LL* from;  // LL<Part>
  Expression* to;
};

struct BindingInherit {
  Expression* from;
  LL* attributes;  // LL<Part>
  Span* span;
};

struct Error {
  Str* message;
  Span* span;
};

struct Float {
  Str* value;
  Span* span;
};

struct Function {
  FunctionHeadKind head_kind;
  any* head_ptr;
  Expression* body;
  Span* span;
};

struct FunctionApplication {
  Expression* function;
  LL* arguments;  // LL<Expression*>
};

struct FunctionHeadDestructuredArgument {
  Str* identifier;
  Expression* default_;
};

struct FunctionHeadDestructured {
  bool ellipsis;
  FunctionHeadDestructuredIdentifier identifier_kind;
  Str* identifier_ptr;
  LL* arguments;  // LL<FunctionHeadDestructuredArgument*>
};

struct FunctionHeadSimple {
  Str* identifier;
};

struct HasAttribute {
  Expression* expression;
  LL* attribute_path;  // LL<Part*>
};

struct Identifier {
  Str* id;
  Span* span;
};

struct IfThenElse {
  Expression* predicate;
  Expression* then;
  Expression* else_;
  Span* span;
};

struct IndentedString {
  LL* parts;  // LL<Part*>
  Span* span;
};

struct Integer {
  Str* value;
  Span* span;
};

struct LetIn {
  LL* bindings;  // LL<Binding*>
  Expression* target;
  Span* span;
};

struct List {
  LL* elements;  // LL<Expression*>
  Span* span;
};

struct Map {
  bool recursive;
  LL* bindings;
  Span* span;
};

struct Path {
  LL* parts;
  Span* span;
};

struct PartRaw {
  UtilString* content;
  Span* span;
};

struct PropertyAccess {
  Expression* expression;
  LL* attribute_path;
  Expression* default_;
};

struct SearchNixPath {
  Str* path;
  Span* span;
};

struct String_ {
  LL* parts;
  Span* span;
};

struct UnaryOperation {
  UnaryOperator operator_;
  Expression* operand;
  Span* span;
};

struct Uri {
  Str* uri;
  Span* span;
};

struct With {
  Expression* expression;
  Expression* target;
  Span* span;
};

extern "C" {
Parsed* parse(unsigned char* input, size_t len);
}
