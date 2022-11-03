LetIn(
 LetIn {
  bindings: [
   KeyValue(
    BindingKeyValue {
     from: [
      Raw(
       PartRaw {
        content: "name",
        span: Span {
         start: Position {
          line: 3,
          column: 3,
         },
         end: Position {
          line: 3,
          column: 7,
         },
        },
       },
      ),
     ],
     to: String(
      String_ {
       parts: [
        Raw(
         PartRaw {
          content: "John Doe",
          span: Span {
           start: Position {
            line: 3,
            column: 11,
           },
           end: Position {
            line: 3,
            column: 19,
           },
          },
         },
        ),
       ],
       span: Span {
        start: Position {
         line: 3,
         column: 10,
        },
        end: Position {
         line: 3,
         column: 20,
        },
       },
      },
     ),
    },
   ),
  ],
  target: String(
   String_ {
    parts: [
     Raw(
      PartRaw {
       content: "Hello, ",
       span: Span {
        start: Position {
         line: 4,
         column: 5,
        },
        end: Position {
         line: 4,
         column: 19,
        },
       },
      },
     ),
     Interpolation(
      PartInterpolation {
       expression: Identifier(
        Identifier {
         id: "name",
         span: Span {
          start: Position {
           line: 4,
           column: 14,
          },
          end: Position {
           line: 4,
           column: 18,
          },
         },
        },
       ),
      },
     ),
     Raw(
      PartRaw {
       content: "!",
       span: Span {
        start: Position {
         line: 4,
         column: 5,
        },
        end: Position {
         line: 4,
         column: 20,
        },
       },
      },
     ),
    ],
    span: Span {
     start: Position {
      line: 4,
      column: 4,
     },
     end: Position {
      line: 4,
      column: 21,
     },
    },
   },
  ),
  span: Span {
   start: Position {
    line: 1,
    column: 1,
   },
   end: Position {
    line: 4,
    column: 21,
   },
  },
 },
)