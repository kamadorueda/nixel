// SPDX-FileCopyrightText: 2022 Kevin Amado <kamadorueda@gmail.com>
//
// SPDX-License-Identifier: AGPL-3.0-only

// use crate::ast::AST;
// use santiago::lexer::Lexeme;

// pub enum CST {
//     Leaf(Rc<Lexeme>),
//     Node { kind: Rc<String>, leaves: Vec<CST> },
// }

// pub fn build_concrete_syntax_tree(ast: AST) -> CST {
//     let mut todo: LinkedList<&CST> = LinkedList::new();
//     let mut ordered: LinkedList<&CST> = LinkedList::new();

//     todo.push_front(self);
//     while !todo.is_empty() {
//         ordered.push_back(todo.pop_front().unwrap());

//         // match tree {
//         //     Tree::Leaf(lexeme) => {
//         //         writeln!(f, "{indent}{lexeme}")?;
//         //     }
//         //     Tree::Node { rule_name, production, .. } => {
//         //         writeln!(f, "{indent}{rule_name} := {production}")?;
//         //         stack.push_back(production.symbols.len());
//         //     }
//         // }

//         // while let Some(remaining) = stack.back_mut() {
//         //     if *remaining == 0 {
//         //         stack.pop_back();
//         //     } else {
//         //         *remaining -= 1;
//         //         break;
//         //     };
//         // }

//         if let Some(Tree::Node { leaves, .. }) = ordered.back() {
//             for tree in leaves.iter().rev() {
//                 todo.push_front(tree);
//             }
//         }
//     }

//     ordered
// }
