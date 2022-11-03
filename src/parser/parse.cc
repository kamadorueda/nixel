// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

Parsed* parse(unsigned char* input, size_t len) {
  Parsed* parsed = new Parsed{
    .expression = nullptr,
    .trivia = LL_new(),
  };

  yyscan_t scanner;
  yylex_init(&scanner);
  yy_scan_buffer((char*)input, len, scanner);
  try {
    yyparse(scanner, parsed);
  } catch (Error* error) {
    delete parsed->expression;
    parsed->expression = to_expr(error);
  }
  yylex_destroy(scanner);

  return parsed;
}
