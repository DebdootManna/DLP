# Lexical Analyzer for C Language Compiler

## Practical 5: Implementation of a Lexical Analyzer for C Language Compiler

### Objective
To design and implement a lexical analyzer to perform 1st, 2nd, 3rd, and 5th tasks as per the list given in practical 2.

### Language Constraint
- **Tool**: Lex (Lexical analyzer generator) or Python-based implementation
- **Target Language**: C programming language

---

## Overview

This lexical analyzer tokenizes C source code into six main categories:
1. **Keywords** (e.g., int, char, return, void, struct)
2. **Identifiers** (variable/function names)
3. **Constants** (integers and floating-point numbers)
4. **Strings** (string literals and character constants)
5. **Punctuation** (e.g., (, ), {, }, ;, ,)
6. **Operators** (e.g., +, -, *, =, ==, &&)

The analyzer also:
- Handles single-line (`//`) and multi-line (`/* */`) comments
- Detects and reports lexical errors
- Ignores whitespace

---

## Input Requirements

The lexical analyzer accepts:
- A C source code file as input
- The input can contain:
  - C keywords
  - Identifiers
  - Constants (integers and floats)
  - Strings and character literals
  - Punctuation marks
  - Operators
  - Comments (single and multi-line)
  - Whitespace

---

## Expected Output

**Tokenized output** categorizing tokens into six types:

| Token Type | Description | Examples |
|------------|-------------|----------|
| Keyword | C language reserved words | int, char, return, void, struct |
| Identifier | Variable/function names | main, a, b, student, scanf |
| Constant | Numeric values | 5, 10, 20, 8.7, 0.40 |
| String | String and char literals | "hello", 'x', "%ld" |
| Punctuation | Delimiters and separators | ( ) { } [ ] ; , # |
| Operator | Arithmetic/logical operators | + - * / = == && \|\| . |

---

## Implementation

### Two Versions Available

#### 1. Lex-based Implementation (lexical_analyzer.l)
Traditional Lex/Flex specification file.

**Compilation on macOS:**
```bash
flex lexical_analyzer.l
gcc lex.yy.c -o lexer -ll
./lexer input_file.c
```

**Note:** Requires flex and gcc to be installed.

#### 2. Python-based Implementation (lexical_analyzer.py)
Portable implementation using Python regex - **recommended for macOS users**.

**Usage:**
```bash
python3 lexical_analyzer.py input_file.c
```

**Advantages:**
- No external dependencies
- Works on any system with Python 3
- Easy to modify and understand
- Portable across platforms

---

## File Structure

```
lexical-analyzer/
│
├── lexical_analyzer.py    # Python implementation (recommended)
├── lexical_analyzer.l     # Lex specification file
│
├── test1.c                # Sample test input 1
├── test2.c                # Sample test input 2
├── test3.c                # Sample test input 3
│
├── test1_output.txt       # Expected output for test1
├── README.md              # This file
└── PRACTICAL_GUIDE.md     # Step-by-step practical guide
```

---

## Sample Input/Output

### Test 1 Input (test1.c)
```c
int main() {
int a = 5 , 7H;
// assign value
char b = 'x';
/* return
value */
return a + b;
}
```

### Test 1 Output
```
TOKENS
Keyword: int
Identifier: main
Punctuation: (
Punctuation: )
Punctuation: {
Keyword: int
Identifier: a
Operator: =
Constant: 5
Punctuation: ,
Constant: 7
Identifier: H
Punctuation: ;
Keyword: char
Identifier: b
Operator: =
String: 'x'
Punctuation: ;
Keyword: return
Identifier: a
Operator: +
Identifier: b
Punctuation: ;
Punctuation: }
```

---

## Token Recognition Rules

### Keywords
All 32 C keywords are recognized:
```
auto, break, case, char, const, continue, default, do, double, else,
enum, extern, float, for, goto, if, int, long, register, return,
short, signed, sizeof, static, struct, switch, typedef, union,
unsigned, void, volatile, while
```

### Identifiers
- Start with a letter or underscore
- Can contain letters, digits, and underscores
- Examples: `main`, `count`, `_temp`, `studentData`

### Constants
- **Integers**: Sequence of digits (e.g., `5`, `100`, `0`)
- **Floats**: Digits with decimal point (e.g., `3.14`, `0.5`, `8.7`)

### Strings
- **String literals**: Text enclosed in double quotes (e.g., `"hello"`)
- **Character constants**: Single character in single quotes (e.g., `'x'`, `'\n'`)

### Operators
```
Arithmetic: +, -, *, /, %
Assignment: =, +=, -=, *=, /=, %=
Comparison: ==, !=, <, >, <=, >=
Logical: &&, ||, !
Bitwise: &, |, ^, ~, <<, >>
Increment/Decrement: ++, --
Other: ., ->, ?:
```

### Punctuation
```
Parentheses: ( )
Braces: { }
Brackets: [ ]
Semicolon: ;
Comma: ,
Hash: #
```

---

## Testing

### Run All Tests
```bash
# Test 1
python3 lexical_analyzer.py test1.c

# Test 2
python3 lexical_analyzer.py test2.c

# Test 3
python3 lexical_analyzer.py test3.c
```

### Create Your Own Test
1. Create a C source file (e.g., `my_test.c`)
2. Run: `python3 lexical_analyzer.py my_test.c`
3. Verify the tokenized output

---

## Error Handling

The lexical analyzer detects and reports:
- **Unrecognized characters**: Characters that don't match any token pattern
- **File errors**: Missing or unreadable input files

Example error:
```
Lexical Error: Unrecognized character '@' at line 5
Error: Could not open file nonexistent.c
```

---

## Technical Details

### Python Implementation Architecture

```python
# Token Pattern Matching (using regex)
1. Comments (multi-line and single-line) - highest priority
2. Strings and character literals
3. Numeric constants (float before integer)
4. Identifiers and keywords
5. Operators (compound before single)
6. Punctuation
7. Whitespace (ignored)
8. Unknown characters (errors)
```

### Pattern Matching Priority
The order matters! More specific patterns are checked first:
- Multi-character operators (`==`, `++`) before single (`=`, `+`)
- Floats (`3.14`) before integers (`3`)
- Comments before division operator (`/`)

---

## Limitations & Assumptions

1. **Preprocessor directives**: Recognized but not fully processed
2. **Escape sequences**: Basic support for `\n`, `\t`, `\\`, etc.
3. **Number formats**: Decimal only (no hex, octal, binary)
4. **Unicode**: ASCII characters only
5. **Nested comments**: Not supported (standard C behavior)

---

## Troubleshooting

### Common Issues

**Issue**: `python3: command not found`
- **Solution**: Use `python` instead of `python3`

**Issue**: `flex: command not found` (for Lex version)
- **Solution**: Use Python version, or install flex:
  ```bash
  # macOS
  brew install flex
  
  # Ubuntu/Debian
  sudo apt-get install flex
  ```

**Issue**: Output doesn't match expected
- **Solution**: Ensure input file uses Unix line endings (LF not CRLF)

---

## Compilation Comparison

### Using Lex/Flex (Traditional)

| Advantage | Disadvantage |
|-----------|--------------|
| Industry standard tool | Requires installation |
| Fast execution | Platform-specific |
| Generates efficient C code | More complex setup |

### Using Python (Recommended for Mac)

| Advantage | Disadvantage |
|-----------|--------------|
| No installation needed | Slightly slower |
| Easy to understand/modify | Requires Python 3 |
| Cross-platform | Not industry tool |
| Better for learning | N/A |

---

## Extending the Analyzer

To add new features:

1. **New token type**: Add pattern to `TOKEN_PATTERNS` list
2. **New keyword**: Add to `KEYWORDS` set
3. **New operator**: Update operator regex pattern
4. **Better error messages**: Enhance error reporting in tokenize()

Example - Adding a new operator:
```python
# In TOKEN_PATTERNS, update the OPERATOR pattern
('OPERATOR', r'(\?\?|...existing patterns...)')
```

---

## References

- C Programming Language Specification (K&R C)
- Lex & Yacc by John R. Levine
- Python Regular Expressions Documentation
- Compiler Design Principles (Aho, Sethi, Ullman)

---

## Author & Course Information

**Practical**: Implementation of Lexical Analyzer for C Language Compiler  
**Course**: Compiler Design Laboratory  
**Tools Used**: Python 3 / Lex (Flex)  
**Platform**: macOS / Linux / Windows

---

## License

This is educational software created for academic purposes.

---

## Appendix: Complete Token Classification

### All 32 C Keywords
```
auto     break    case     char     const    continue default  do
double   else     enum     extern   float    for      goto     if
int      long     register return   short    signed   sizeof   static
struct   switch   typedef  union    unsigned void     volatile while
```

### All Recognized Operators (30+)
```
++   --   +    -    *    /    %    =    ==   !=
<    >    <=   >=   &&   ||   !    &    |    ^
~    <<   >>   +=   -=   *=   /=   %=   &=   |=
^=   <<= >>=  ->   .    ?    :
```

### All Punctuation Marks
```
(    )    {    }    [    ]    ;    ,    #
```
