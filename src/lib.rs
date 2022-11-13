// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only

//! NixEl is a Rust library that turns
//! [Nix](https://nixos.org) code
//! into a correct, typed data-structured.
//!
//! Just use the [parse()] or [parse_bytes()] methods
//! to build a [Parsed] structure
//! and use the [Expression] enum variants to traverse the AST.
//!
//! You can also retrieve [Trivia::Comment]s,
//! [Trivia::MultilineComment]s
//! and [Trivia::Whitespace],
//! using the [Parsed::trivia_before()] and [Parsed::trivia_after()]
//! methods.
//!
//! For example:
//!
//! ```
//! let input: String = String::from(
//!     r#"
//!         ## Greet the user
//!         "Hello, World!"
//!         ## Bye!
//!     "#,
//! );
//!
//! let parsed: nixel::Parsed = nixel::parse(input);
//!
//! match &*parsed.expression {
//!     nixel::Expression::String(string) => {
//!         assert_eq!(
//!             &string.span,
//!             &nixel::Span {
//!                 start: nixel::Position { line: 3, column: 9 }.into(),
//!                 end: nixel::Position { line: 3, column: 24 }.into(),
//!             }
//!             .into()
//!         );
//!         assert_eq!(
//!             &parsed.trivia_before(&string.span.start)[1],
//!             &nixel::Trivia::Comment(nixel::TriviaComment {
//!                 content: "# Greet the user".into(),
//!                 span: nixel::Span {
//!                     start: nixel::Position { line: 2, column: 9 }.into(),
//!                     end: nixel::Position { line: 2, column: 25 }.into(),
//!                 }
//!                 .into()
//!             })
//!         );
//!         assert_eq!(
//!             &string.parts[0],
//!             &nixel::Part::Raw(nixel::PartRaw {
//!                 content: "Hello, World!".into(),
//!                 span: nixel::Span {
//!                     start: nixel::Position { line: 3, column: 10 }.into(),
//!                     end: nixel::Position { line: 3, column: 23 }.into(),
//!                 }
//!                 .into()
//!             })
//!         );
//!         assert_eq!(
//!             &parsed.trivia_after(&string.span.end)[1],
//!             &nixel::Trivia::Comment(nixel::TriviaComment {
//!                 content: "# Bye!".into(),
//!                 span: nixel::Span {
//!                     start: nixel::Position { line: 4, column: 9 }.into(),
//!                     end: nixel::Position { line: 4, column: 15 }.into(),
//!                 }
//!                 .into()
//!             })
//!         );
//!     },
//!     expression => unreachable!("Expected a String, got: {expression:#?}"),
//! }
//! ```
//!
//! Source code can be found at
//! [github.com/kamadorueda/nixel](https://github.com/kamadorueda/nixel).
pub(crate) mod ffi;
pub(crate) mod mem;
mod parse;
mod types;

pub use parse::*;
pub use types::assert::*;
pub use types::binary_operation::*;
pub use types::binary_operator::*;
pub use types::binding::*;
pub use types::error::*;
pub use types::expression::*;
pub use types::float::*;
pub use types::function::*;
pub use types::function_application::*;
pub use types::function_head::*;
pub use types::function_head_destructured_argument::*;
pub use types::function_head_destructured_identifier::*;
pub use types::has_attribute::*;
pub use types::identifier::*;
pub use types::if_then_else::*;
pub use types::indented_string::*;
pub use types::integer::*;
pub use types::let_in::*;
pub use types::list::*;
pub use types::map::*;
pub use types::parsed::*;
pub use types::part::*;
pub use types::path::*;
pub use types::position::*;
pub use types::property_access::*;
pub use types::search_nix_path::*;
pub use types::span::*;
pub use types::string::*;
pub use types::trivia::*;
pub use types::unary_operation::*;
pub use types::unary_operator::*;
pub use types::uri::*;
pub use types::with::*;
