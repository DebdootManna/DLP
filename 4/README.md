# LEX Practical - String Validation Using Lex Tool

## 📋 Table of Contents
- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Installation Guide](#installation-guide)
- [Project Structure](#project-structure)
- [Compilation Instructions](#compilation-instructions)
- [Execution Guide](#execution-guide)
- [Objectives Explained](#objectives-explained)
- [Troubleshooting](#troubleshooting)

---

## 🎯 Overview

This practical demonstrates string validation and manipulation using **Lex (Lexical Analyzer Generator)**. The project contains 4 objectives covering:
1. Number extraction from strings
2. String replacement (case-insensitive)
3. Character, word, and line counting
4. Password validation

---

## 📦 Prerequisites

### Required Software
- **Operating System**: Linux (Ubuntu/Debian recommended) or Windows with WSL
- **Compiler**: GCC (GNU Compiler Collection)
- **Lex Tool**: Flex (Fast Lexical Analyzer Generator)

### Check Prerequisites
```bash
# Check if GCC is installed
gcc --version

# Check if Flex is installed
flex --version
```

---

## 🔧 Installation Guide

### For Ubuntu/Debian Linux:
```bash
# Update package list
sudo apt-get update

# Install Flex
sudo apt-get install flex

# Install GCC (if not already installed)
sudo apt-get install gcc

# Install build-essential (recommended)
sudo apt-get install build-essential
```

### For Fedora/RHEL:
```bash
sudo dnf install flex gcc
```

### For Arch Linux:
```bash
sudo pacman -S flex gcc
```

### For Windows (WSL):
```bash
# First, enable WSL and install Ubuntu from Microsoft Store
# Then run the Ubuntu/Debian commands above
```

---

## 📁 Project Structure

```
lex-practical/
│
├── objective1.l          # Extract numbers from string
├── objective2.l          # Replace "charusat" with "university"
├── objective3.l          # Count characters, words, lines
├── objective4.l          # Password validation
├── test_input.txt        # Test file for Objective 3
└── README.md             # This file
```

---

## ⚙️ Compilation Instructions

### General Compilation Process
For each objective, follow these steps:

```bash
# Step 1: Generate C code from Lex file
flex objective1.l

# Step 2: Compile the generated C code
gcc lex.yy.c -o objective1 -lfl

# If you get an error about -lfl, try:
gcc lex.yy.c -o objective1 -ll
```

### Compile All Objectives

```bash
# Objective 1: Number Extraction
flex objective1.l
gcc lex.yy.c -o objective1 -lfl

# Objective 2: String Replacement
flex objective2.l
gcc lex.yy.c -o objective2 -lfl

# Objective 3: Character/Word/Line Counter
flex objective3.l
gcc lex.yy.c -o objective3 -lfl

# Objective 4: Password Validator
flex objective4.l
gcc lex.yy.c -o objective4 -lfl
```

### One-Line Compilation (Alternative)
```bash
# You can also compile in one command:
flex objective1.l && gcc lex.yy.c -o objective1 -lfl
```

---

## 🚀 Execution Guide

### Objective 1: Extract Numbers
**Purpose**: Extract all numbers from input string and display them line by line.

```bash
# Run the program
./objective1

# Input example:
a1b22c3

# Expected output:
1
22
3
```

**Test Cases**:
```bash
# Test 1
Input: a1b22c3
Output:
1
22
3

# Test 2 (from practical sheet)
Input: power operation -> 12 ** 3 = 1728
Output:
12
3
1728

# Test 3
Input: You multiply 804569 with 1 then will be :
Output:
804569
1
```

---

### Objective 2: Replace String
**Purpose**: Replace all occurrences of "charusat" with "university" (case-insensitive).

```bash
# Run the program
./objective2

# Input example:
This is charusat.

# Expected output:
This is university.
```

**Test Cases**:
```bash
# Test 1
Input: This is charusat.
Output: This is university.

# Test 2
Input: Charusat is in Anand district.
Output: university is in Anand district.

# Test 3
Input: I am doing my BTech from CHARSAT.
Output: I am doing my BTech from university.

# Test 4
Input: Charusat , What is charusat?
Output: university , What is university?

# Test 5
Input: Every where it is charusat , charusat and only charusat.
Output: Every where it is university , university and only university.
```

---

### Objective 3: Count Characters, Words, Lines
**Purpose**: Read from a text file and count characters (including spaces), words, and lines.

```bash
# Create a test file
echo "The 45 is odd number." > test_input.txt

# Run the program
./objective3 test_input.txt

# Expected output:
Characters : 22
Words : 5
Line : 1
```

**Test Cases**:
```bash
# Test 1
File content: "The 45 is odd number."
Output:
Characters : 22
Words : 5
Line : 1

# Test 2
File content: "I want to calculate a number. The number of characters, words and lines.

All know that \n is ending character of line.
45 + 89 =40"

Output:
Characters : 129
Words : 27
Line : 3
```

**Note**: To create multi-line test files:
```bash
cat > multiline_test.txt << EOF
I want to calculate a number. The number of characters, words and lines.

All know that \n is ending character of line.
45 + 89 =40
EOF

./objective3 multiline_test.txt
```

---

### Objective 4: Password Validation
**Purpose**: Validate password based on these rules:
- Length: 9 to 15 characters
- Must include: lowercase letter, uppercase letter, digit, special symbol (*, ,, ;, #, $, @)
- Minimum count for each category: 1

```bash
# Run the program
./objective4

# Input example:
a@1T

# Expected output:
Invalid password
```

**Test Cases**:
```bash
# Test 1 - Invalid (too short)
Input: a@1T
Output: Invalid password

# Test 2 - Valid
Input: Passw0rd@123
Output: Valid password

# Test 3 - Valid
Input: MyP@ssw0rd99
Output: Valid password

# Test 4 - Invalid (no uppercase)
Input: password@123
Output: Invalid password

# Test 5 - Invalid (no special character)
Input: Password123
Output: Invalid password

# Test 6 - Invalid (too long)
Input: VeryLongPassword@12345
Output: Invalid password
```

---

## 📚 Objectives Explained

### How Lex Works

| **Component** | **Description** |
|---------------|-----------------|
| **Pattern Matching** | Lex uses regular expressions to match patterns in input |
| **Token Recognition** | Each matched pattern can trigger an action |
| **Lexical Analysis** | Breaks input into meaningful tokens |
| **Code Generation** | Lex generates C code that can be compiled |

### Lex File Structure

```c
%{
// C declarations (includes, variables)
%}

%%
// Pattern-Action rules
pattern1    { action1; }
pattern2    { action2; }
%%

// C functions (main, yywrap)
int yywrap() {
    return 1;
}

int main() {
    // Your code
}
```

### Regular Expression Patterns Used

| **Pattern** | **Meaning** | **Example** |
|-------------|-------------|-------------|
| `[0-9]+` | One or more digits | Matches: 123, 5, 999 |
| `[a-z]` | Single lowercase letter | Matches: a, b, z |
| `[A-Z]` | Single uppercase letter | Matches: A, B, Z |
| `[Cc][Hh][Aa]...` | Case-insensitive string | Matches: charusat, CHARUSAT, ChArUsAt |
| `.` | Any single character | Matches: a, 5, @ |
| `\n` | Newline character | End of line |
| `[ \t]+` | One or more spaces/tabs | Whitespace |

---

## 🐛 Troubleshooting

### Common Errors and Solutions

#### Error 1: "flex: command not found"
**Solution**:
```bash
# Install flex
sudo apt-get install flex
```

#### Error 2: "ld: cannot find -lfl"
**Problem**: The flex library is not found during linking.

**Solution**:
```bash
# Option 1: Use -ll instead
gcc lex.yy.c -o program -ll

# Option 2: Install libfl-dev
sudo apt-get install libfl-dev

# Option 3: Compile without the library (add yywrap yourself)
gcc lex.yy.c -o program
```

#### Error 3: "undefined reference to `yywrap'"
**Solution**: Add this function to your Lex file:
```c
int yywrap() {
    return 1;
}
```

#### Error 4: "No rule matches" or unexpected behavior
**Solution**:
- Check your regular expressions
- Ensure patterns are in the correct order (most specific first)
- Add a catch-all pattern: `. { /* ignore */ }`

#### Error 5: Program doesn't read from file
**Solution**: Make sure you're using `yyin`:
```c
FILE *file = fopen(argv[1], "r");
yyin = file;
yylex();
fclose(file);
```

---

## 💡 Tips for Success

### Best Practices

1. **Test incrementally**: Test each objective separately before moving to the next
2. **Use test files**: Create comprehensive test files for Objective 3
3. **Check edge cases**: Test with empty input, very long input, special characters
4. **Read error messages**: Flex and GCC provide helpful error messages
5. **Comment your code**: Add comments explaining complex patterns

### Understanding Pattern Priority

Lex matches patterns in order of:
1. **Longest match**: If multiple patterns match, the longest one wins
2. **First match**: If patterns are equal length, the first one in the file wins

Example:
```c
%%
"char"      { printf("Found: char\n"); }
"charusat"  { printf("Found: charusat\n"); }
%%
```
Input: "charusat" → Matches "charusat" (longer match wins)

---

## 📖 Additional Resources

### Learning Lex/Flex
- [Official Flex Manual](https://westes.github.io/flex/manual/)
- [Lex & Yacc Tutorial](https://www.tutorialspoint.com/lex/index.htm)
- Regular Expressions Guide: [regex101.com](https://regex101.com)

### Regular Expressions Quick Reference
- `.` - Any character except newline
- `*` - Zero or more occurrences
- `+` - One or more occurrences
- `?` - Zero or one occurrence
- `[abc]` - Any character in the set
- `[^abc]` - Any character NOT in the set
- `[a-z]` - Any character in range
- `\n` - Newline
- `\t` - Tab

---

## 🎓 Learning Outcomes

After completing this practical, you will understand:

✅ How lexical analysis works  
✅ Pattern matching with regular expressions  
✅ Token recognition and extraction  
✅ File I/O operations in Lex  
✅ String manipulation and validation  
✅ Building practical text processing tools  

---

## 📝 Assignment Submission Checklist

- [ ] All 4 objectives completed
- [ ] Code compiles without errors
- [ ] All test cases pass
- [ ] README.md included
- [ ] Source files (.l files) included
- [ ] Test input files included
- [ ] Screenshots of output (optional but recommended)

---

## 🤝 Getting Help

If you encounter issues:

1. **Check compilation errors**: Read error messages carefully
2. **Verify installation**: Ensure flex and gcc are properly installed
3. **Test patterns**: Use simple patterns first, then make them complex
4. **Review regular expressions**: Make sure your patterns are correct
5. **Ask for help**: Consult with peers or instructor

---

## 📄 File Descriptions

| **File** | **Purpose** | **Input** | **Output** |
|----------|-------------|-----------|------------|
| `objective1.l` | Extract numbers | String from stdin | Numbers, each on new line |
| `objective2.l` | Replace string | String from stdin | Modified string |
| `objective3.l` | Count chars/words/lines | Text file path | Character, word, line counts |
| `objective4.l` | Validate password | Password from stdin | "Valid" or "Invalid" |

---

## 🏆 Conclusion

This practical demonstrates the power of lexical analysis for text processing tasks. Lex/Flex is widely used in:
- Compilers and interpreters
- Text editors
- Data validation tools
- Log file analyzers
- Configuration file parsers

Master these fundamentals, and you'll have a strong foundation for building more complex language processing tools!

---

**Version**: 1.0  
**Last Updated**: January 2026  
**Tested On**: Ubuntu 24.04 with Flex 2.6.4 and GCC 13.2.0

---

## 🎉 Happy Coding! 🚀
