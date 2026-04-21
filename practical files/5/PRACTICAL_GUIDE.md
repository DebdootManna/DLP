# Practical Guide: Lexical Analyzer for C Language

## Step-by-Step Instructions for Lab Completion

---

## Part 1: Setup (5 minutes)

### Step 1: Verify Python Installation
```bash
python3 --version
```
Expected output: `Python 3.x.x`

If Python is not installed:
- **macOS**: `brew install python3`
- **Ubuntu**: `sudo apt-get install python3`
- **Windows**: Download from python.org

### Step 2: Create Working Directory
```bash
mkdir compiler-lab
cd compiler-lab
```

### Step 3: Download/Copy Files
You need these files:
- `lexical_analyzer.py` - The main program
- `test1.c`, `test2.c`, `test3.c` - Test inputs
- `README.md` - Documentation
- `PRACTICAL_GUIDE.md` - This guide

---

## Part 2: Understanding the Code (10 minutes)

### Architecture Overview

```
┌─────────────────────────────────────────────────────┐
│              INPUT: C Source File                   │
└─────────────────────┬───────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────┐
│         LEXICAL ANALYZER (lexical_analyzer.py)      │
│                                                      │
│  1. Read source code                                │
│  2. Pattern matching (regex)                        │
│  3. Token identification                            │
│  4. Classification                                   │
└─────────────────────┬───────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────┐
│          OUTPUT: Categorized Token List             │
│                                                      │
│  TOKENS                                             │
│  Keyword: int                                       │
│  Identifier: main                                   │
│  Punctuation: (                                     │
│  ...                                                │
└─────────────────────────────────────────────────────┘
```

### Key Components

#### 1. Token Patterns (Regular Expressions)
```python
TOKEN_PATTERNS = [
    ('COMMENT_MULTI', r'/\*([^*]|\*+[^*/])*\*+/'),  # /* ... */
    ('COMMENT_SINGLE', r'//.*'),                     # // ...
    ('STRING', r'"([^"\\]|\\.)*"'),                  # "string"
    ('CHAR', r"'([^'\\]|\\.)'"),                     # 'c'
    ('FLOAT', r'\d+\.\d+'),                          # 3.14
    ('INTEGER', r'\d+'),                             # 42
    ('IDENTIFIER', r'[a-zA-Z_][a-zA-Z0-9_]*'),       # variable
    ('OPERATOR', r'(\+\+|--|...'),                   # +, ++, ==
    ('PUNCTUATION', r'[(){}\[\];,#]'),               # ( ) { }
]
```

**Pattern Priority Matters!**
- More specific patterns come first
- Example: Check for `==` before `=`
- Example: Check for `3.14` (float) before `3` (integer)

#### 2. Keyword Set
```python
KEYWORDS = {
    'auto', 'break', 'case', 'char', 'const', ...
}
```
- When an IDENTIFIER matches a keyword, it's reclassified

#### 3. Token Classification Logic
```python
if token_type == 'IDENTIFIER':
    if value in KEYWORDS:
        tokens.append(('Keyword', value))
    else:
        tokens.append(('Identifier', value))
```

---

## Part 3: Running Tests (15 minutes)

### Test 1: Basic Program
```bash
python3 lexical_analyzer.py test1.c
```

**Input Analysis:**
```c
int main() {          // Line 1
int a = 5 , 7H;       // Line 2 - has error: 7H
// assign value       // Line 3 - comment (ignored)
char b = 'x';         // Line 4
/* return             // Lines 5-6 - multiline comment
value */
return a + b;         // Line 7
}                     // Line 8
```

**Expected Tokens:**
| Line | Token Type | Value |
|------|------------|-------|
| 1 | Keyword | int |
| 1 | Identifier | main |
| 1 | Punctuation | ( |
| 1 | Punctuation | ) |
| 1 | Punctuation | { |
| 2 | Keyword | int |
| 2 | Identifier | a |
| 2 | Operator | = |
| 2 | Constant | 5 |
| 2 | Punctuation | , |
| 2 | Constant | 7 |
| 2 | Identifier | H |

**Analysis:**
- Comments are ignored (lines 3, 5-6)
- `7H` is tokenized as two separate tokens: `7` (constant) and `H` (identifier)
- Character literal `'x'` is classified as String

### Test 2: Complex Program with Functions
```bash
python3 lexical_analyzer.py test2.c
```

**Key Features Tested:**
- ✓ Multi-line comments
- ✓ Function declarations
- ✓ String literals with escape sequences (`"\n"`)
- ✓ Format specifiers (`"%ld"`)
- ✓ Multiple functions
- ✓ Floating point arithmetic (`.40`, `.20`)

**Sample Output:**
```
TOKENS
Keyword: void
Identifier: main
Punctuation: (
Punctuation: )
Punctuation: {
Keyword: long
Keyword: int
Identifier: bs
...
String: "\nbs : %ld"
...
```

### Test 3: User-Defined Data Types
```bash
python3 lexical_analyzer.py test3.c
```

**Features Tested:**
- ✓ `struct` keyword
- ✓ Member access operator (`.`)
- ✓ Float constants (`8.7`)
- ✓ User-defined type names (`student`)

---

## Part 4: Creating Your Own Tests (10 minutes)

### Example 1: Operators Test
```bash
cat > operators_test.c << 'EOF'
int main() {
    int a = 10;
    int b = 20;
    int c = a + b;      // addition
    int d = a * b;      // multiplication
    int e = a == b;     // comparison
    int f = a && b;     // logical AND
    a++;                // increment
    b--;                // decrement
    return 0;
}
EOF

python3 lexical_analyzer.py operators_test.c
```

**Verify:** Should identify `+`, `*`, `==`, `&&`, `++`, `--` as operators

### Example 2: Loop Structures
```bash
cat > loop_test.c << 'EOF'
void test() {
    for(int i = 0; i < 10; i++) {
        while(i > 5) {
            break;
        }
    }
}
EOF

python3 lexical_analyzer.py loop_test.c
```

**Verify:** Should recognize `for`, `while`, `break` as keywords

### Example 3: Pointer Operations
```bash
cat > pointer_test.c << 'EOF'
int main() {
    int *ptr;
    int value = 100;
    ptr = &value;
    int result = *ptr;
    return 0;
}
EOF

python3 lexical_analyzer.py pointer_test.c
```

**Verify:** Should identify `*` and `&` as operators

---

## Part 5: Verification & Comparison (10 minutes)

### Comparing with Expected Output

#### Manual Verification Checklist

For each test file, verify:

1. **Keywords** - All C keywords correctly identified?
   - [ ] `int`, `char`, `void`, `return`, `struct`, etc.

2. **Identifiers** - Variable/function names correct?
   - [ ] `main`, `a`, `b`, `student`, `scanf`, etc.

3. **Constants** - Numbers recognized properly?
   - [ ] Integers: `5`, `10`, `20`
   - [ ] Floats: `8.7`, `0.40`, `0.20`

4. **Strings** - String literals with escapes?
   - [ ] `'x'`, `"%ld"`, `"\nbs : %ld"`

5. **Operators** - All operators detected?
   - [ ] `=`, `+`, `-`, `*`, `.`, `&`, etc.

6. **Punctuation** - Delimiters present?
   - [ ] `(`, `)`, `{`, `}`, `;`, `,`

7. **Comments** - Properly ignored?
   - [ ] `//` comments not in output
   - [ ] `/* */` comments not in output

#### Automated Comparison
```bash
# Save output
python3 lexical_analyzer.py test1.c > my_output.txt

# Compare with reference (if you have it)
diff my_output.txt expected_output.txt
```

---

## Part 6: Understanding Token Categories (5 minutes)

### Token Category Reference Table

| Category | Purpose | Examples | Regex Pattern |
|----------|---------|----------|---------------|
| **Keyword** | Reserved words | int, return, for | Exact match from set |
| **Identifier** | Names | main, count, x | `[a-zA-Z_][a-zA-Z0-9_]*` |
| **Constant** | Numbers | 42, 3.14 | `\d+` or `\d+\.\d+` |
| **String** | Text/chars | "hi", 'c' | `"..."` or `'.'` |
| **Operator** | Operations | +, ==, && | Special symbols |
| **Punctuation** | Structure | ( ) { } ; | Delimiters |

### Why This Classification?

```
C Source Code: int sum = a + b;

Token Classification:
┌─────────┬──────────────┬────────────────────────┐
│ Token   │ Category     │ Reason                 │
├─────────┼──────────────┼────────────────────────┤
│ int     │ Keyword      │ Reserved word          │
│ sum     │ Identifier   │ Variable name          │
│ =       │ Operator     │ Assignment             │
│ a       │ Identifier   │ Variable name          │
│ +       │ Operator     │ Addition               │
│ b       │ Identifier   │ Variable name          │
│ ;       │ Punctuation  │ Statement terminator   │
└─────────┴──────────────┴────────────────────────┘
```

---

## Part 7: Error Handling (5 minutes)

### Testing Error Detection

Create an error test file:
```bash
cat > error_test.c << 'EOF'
int main() {
    int x = 10;
    char c = '@';    // @ is valid in char literal
    int y = $100;    // $ is not valid in C
    return 0;
}
EOF

python3 lexical_analyzer.py error_test.c
```

**Expected Behavior:**
- `@` inside `'@'` is OK (part of string)
- `$` by itself triggers: `Lexical Error: Unrecognized character '$'`

### Common Lexical Errors

| Error Type | Example | Detection |
|------------|---------|-----------|
| Invalid character | `$`, `@` outside strings | Unrecognized char |
| Unterminated string | `"hello` (no closing `"`) | Regex won't match |
| Invalid identifier | `123abc` | Parsed as `123` + `abc` |
| Unknown symbol | `£`, `€` | Lexical error reported |

---

## Part 8: Modification Exercises (15 minutes)

### Exercise 1: Add New Keyword
Suppose C adds a new keyword `forever` (hypothetical).

```python
# In lexical_analyzer.py, add to KEYWORDS set:
KEYWORDS = {
    'auto', 'break', ..., 'while', 'forever'  # Add here
}
```

**Test:**
```c
forever {
    print("loop");
}
```

### Exercise 2: Recognize Hexadecimal Numbers
Currently, `0xFF` would be tokenized as `0`, `x`, `FF`.

**Add pattern:**
```python
('HEX', r'0[xX][0-9a-fA-F]+'),  # Add before INTEGER pattern
```

**Handle in tokenize():**
```python
elif token_type == 'HEX':
    self.tokens.append(('Constant', value))
```

**Test:**
```c
int x = 0xFF;      // Should recognize 0xFF as single constant
int y = 0x1A2B;    // Hexadecimal
```

### Exercise 3: Line Number Tracking Enhancement
Show line numbers with tokens:

```python
# Modify token append:
self.tokens.append(('Keyword', value, self.line_number))

# Modify print:
def print_tokens(self):
    for token_type, token_value, line_no in self.tokens:
        print(f"Line {line_no}: {token_type}: {token_value}")
```

---

## Part 9: Lab Report Structure (10 minutes)

### Recommended Report Format

#### 1. **Title Page**
- Practical Number: 5
- Title: Implementation of Lexical Analyzer for C Language Compiler
- Name, Roll Number, Date

#### 2. **Aim**
> To design and implement a lexical analyzer for C language that tokenizes source code into keywords, identifiers, constants, strings, operators, and punctuation.

#### 3. **Theory**
- What is lexical analysis?
- Role in compilation process
- Token categories
- Pattern matching approach

#### 4. **Algorithm**
```
1. Read input C source file
2. Initialize line counter and token list
3. For each character/pattern in source:
   a. Match against token patterns (in priority order)
   b. Identify token type
   c. Classify token
   d. Add to token list
   e. Handle special cases (comments, whitespace)
4. Print categorized tokens
5. Report any lexical errors
```

#### 5. **Implementation**
- Code listing (include key functions)
- Explain pattern matching approach
- Explain classification logic

#### 6. **Test Cases**
Include:
- Input code
- Generated tokens
- Analysis/explanation

#### 7. **Output Screenshots**
- Terminal screenshots showing:
  - Test 1 execution
  - Test 2 execution
  - Test 3 execution
  - Custom test execution

#### 8. **Observations**
- Comment handling: Single and multi-line comments correctly ignored
- String handling: Escape sequences properly recognized
- Error detection: Invalid characters reported with line numbers
- Token classification: All six categories correctly identified

#### 9. **Conclusion**
> Successfully implemented a lexical analyzer for C language that correctly tokenizes source code into six categories. The analyzer handles comments, whitespace, and reports lexical errors. Tested with multiple C programs including functions, structures, and operators.

#### 10. **References**
- Compiler Design by Aho, Sethi, Ullman
- The C Programming Language by Kernighan & Ritchie
- Python re module documentation

---

## Part 10: Common Questions & Answers

### Q1: Why use Python instead of Lex?
**A:** Both are valid. Python is:
- More portable (no installation needed on most systems)
- Easier to understand and modify
- Good for learning compiler concepts
- Lex is more efficient for production use

### Q2: What if my output doesn't match exactly?
**A:** Check:
- File encoding (should be UTF-8)
- Line endings (Unix LF vs Windows CRLF)
- Python version (use Python 3)
- Input file correctness

### Q3: How do I handle Unicode characters?
**A:** Current implementation supports ASCII. For Unicode:
```python
# When reading file:
with open(sys.argv[1], 'r', encoding='utf-8') as f:
```

### Q4: Can I add more token types?
**A:** Yes! Add patterns to `TOKEN_PATTERNS` and handle them in `tokenize()`.

### Q5: Why are some valid C constructs reported as errors?
**A:** This is a simple lexical analyzer. It only checks individual tokens, not syntax. For example:
- `7H` is lexically valid (7 + H) but syntactically invalid
- Syntax checking happens in the parsing phase

### Q6: How to handle macros and preprocessor directives?
**A:** Current version recognizes `#` as punctuation. Full preprocessor support requires:
- Separate preprocessing phase
- Macro expansion
- Conditional compilation handling

---

## Part 11: Quick Reference

### Commands Cheat Sheet

```bash
# Basic usage
python3 lexical_analyzer.py input.c

# Save output to file
python3 lexical_analyzer.py input.c > output.txt

# Run all tests
for test in test*.c; do
    echo "Testing $test"
    python3 lexical_analyzer.py "$test"
    echo "---"
done

# Create new test quickly
echo 'int main() { return 0; }' > simple.c
python3 lexical_analyzer.py simple.c

# Check Python version
python3 --version

# View file contents
cat test1.c

# Compare outputs
diff output1.txt output2.txt
```

### File Operations

```bash
# Copy files
cp lexical_analyzer.py backup.py

# Edit file
nano test1.c          # or vim, code, etc.

# Create directory
mkdir test_cases

# Move files
mv *.c test_cases/

# List files
ls -la
```

---

## Part 12: Troubleshooting Guide

### Problem: "No such file or directory"
```
Error: Could not open file test1.c
```
**Solution:**
```bash
# Check if file exists
ls test1.c

# Check current directory
pwd

# Use full path
python3 lexical_analyzer.py /full/path/to/test1.c
```

### Problem: "Permission denied"
**Solution:**
```bash
chmod +x lexical_analyzer.py
```

### Problem: Wrong output format
**Solution:** Ensure you're using the correct version:
```bash
python3 --version  # Should be 3.x
head -n 5 lexical_analyzer.py  # Should start with #!/usr/bin/env python3
```

### Problem: Unicode/Encoding errors
**Solution:**
```bash
file test1.c  # Check encoding
dos2unix test1.c  # Convert line endings if needed
```

---

## Part 13: Time Management

### Lab Session Timeline (60 minutes)

| Time | Activity | Duration |
|------|----------|----------|
| 0-5 min | Setup & file preparation | 5 min |
| 5-15 min | Code review & understanding | 10 min |
| 15-30 min | Running test cases | 15 min |
| 30-40 min | Custom tests & verification | 10 min |
| 40-50 min | Error testing & debugging | 10 min |
| 50-60 min | Documentation & screenshots | 10 min |

---

## Part 14: Advanced Exercises (Optional)

### Challenge 1: Token Statistics
Add functionality to count tokens:
```python
def print_statistics(self):
    stats = {}
    for token_type, _ in self.tokens:
        stats[token_type] = stats.get(token_type, 0) + 1
    print("\nStatistics:")
    for category, count in sorted(stats.items()):
        print(f"{category}: {count}")
```

### Challenge 2: Colored Output
```python
# Add ANSI color codes
COLORS = {
    'Keyword': '\033[94m',      # Blue
    'Identifier': '\033[92m',   # Green
    'Operator': '\033[91m',     # Red
    'ENDC': '\033[0m'
}

print(f"{COLORS['Keyword']}Keyword{COLORS['ENDC']}: {value}")
```

### Challenge 3: JSON Output
```python
import json

def export_json(self, filename):
    tokens_dict = [{"type": t, "value": v} for t, v in self.tokens]
    with open(filename, 'w') as f:
        json.dump(tokens_dict, f, indent=2)
```

---

## Completion Checklist

Before submitting, ensure:

- [ ] All 3 test cases run successfully
- [ ] Created at least 1 custom test
- [ ] Tested error handling
- [ ] Captured output screenshots
- [ ] Documented results
- [ ] Code is well-commented
- [ ] Report is complete
- [ ] Verified token classifications
- [ ] Tested with edge cases
- [ ] Ready for demonstration

---

## Success Criteria

Your practical is complete when:

✓ Lexical analyzer correctly tokenizes all test inputs  
✓ All six token categories are properly identified  
✓ Comments are ignored  
✓ Errors are detected and reported  
✓ Output matches expected format  
✓ Documentation is complete  
✓ Code is well-structured and commented

---

## Next Steps

After completing this practical:
1. Study **syntax analysis** (parsing)
2. Learn about **parser generators** (Yacc/Bison)
3. Explore **abstract syntax trees** (AST)
4. Understand **semantic analysis**
5. Study **code generation**

**Good luck with your practical!** 🚀
