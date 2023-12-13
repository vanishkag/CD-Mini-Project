# Syntax Analyzer and Symbol Table Generator

This repository contains C code implementing a simple syntax analyzer along with a lexer to generate a symbol table for arithmetic expressions.

## Code Overview

### `syntax_analyzer.c`

This file comprises functions to parse arithmetic expressions based on a simple grammar, utilizing a recursive descent parser approach.

- **`E()`, `Eprime()`, `T()`, `Tprime()`, `F()`:** Functions implementing parsing rules for non-terminals in the grammar.
- **`generateCode()`:** Generates intermediate code for expressions.
- **`main()`:** Accepts an arithmetic expression as input, parses it, and verifies its validity.

### `lexer.c`

The lexer (`lex()` function) tokenizes the input string into tokens based on predefined token types:

- **`Token` Structure:** Contains `type` (enumerated token type) and `value` (if applicable).
- **`lex()` Function:** Tokenizes the input expression.
- **`printTokens()` and `freeTokens()` Functions:** Aid in printing tokens and freeing allocated memory, respectively.

### `symbol_table.c`

This file represents a basic symbol table functionality:

- **`SymbolEntry` Structure:** Defines a symbol entry with attributes (e.g., name, type, value, scope).
- **`symbolTable` Array:** Stores symbol entries.
- **`addSymbol()` and `findSymbol()` Functions:** Add and search for symbols in the table, respectively.

## Usage

1. Compile the code using a C compiler (`gcc` recommended).
2. Run the executable generated after compilation, providing an arithmetic expression as input.
3. The code will verify the validity of the expression and generate a symbol table for predefined symbols.

## Example

Consider the input expression `(i + i * i)`. Upon execution, the code will parse the expression and output whether it's valid or invalid, along with a symbol table if valid.

## Note

- This code serves as a basic demonstration and might need enhancements for more complex grammars or symbol table requirements.
- Modify and extend the code according to specific grammar or symbol table needs.
