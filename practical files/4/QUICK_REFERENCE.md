# LEX Quick Reference Guide

## 📋 Quick Start Commands

### Installation
```bash
sudo apt-get install flex gcc
```

### Compilation (2 Steps)
```bash
flex program.l              # Generate lex.yy.c
gcc lex.yy.c -o program -lfl  # Compile to executable
```

### One-Line Compilation
```bash
flex program.l && gcc lex.yy.c -o program -lfl
```

---

## 🎯 Regular Expression Patterns

| Pattern | Meaning | Example Match |
|---------|---------|--------------|
| `[0-9]` | Single digit | 5 |
| `[0-9]+` | One or more digits | 123, 45 |
| `[a-z]` | Lowercase letter | a, x |
| `[A-Z]` | Uppercase letter | A, X |
| `[a-zA-Z]` | Any letter | a, B, x, Z |
| `[abc]` | Any of a, b, or c | a, b, c |
| `[^abc]` | Anything except a, b, c | d, 1, @ |
| `[0-9a-z]` | Digit or lowercase | 5, a |
| `.` | Any character (except \n) | a, 5, @ |
| `\.` | Literal dot | . |
| `\n` | Newline | End of line |
| `\t` | Tab | Tab character |
| `" "` | Space | Space character |
| `[ \t]+` | One or more spaces/tabs | Whitespace |

### Quantifiers
| Pattern | Meaning | Example |
|---------|---------|---------|
| `*` | Zero or more | `[0-9]*` matches "", "1", "123" |
| `+` | One or more | `[0-9]+` matches "1", "123" (not "") |
| `?` | Zero or one | `[0-9]?` matches "", "5" |
| `{n}` | Exactly n times | `[0-9]{3}` matches "123" |
| `{n,m}` | Between n and m | `[0-9]{2,4}` matches "12", "123" |

---

## 📝 Lex File Structure

```c
%{
/* Section 1: C Declarations */
#include <stdio.h>
int count = 0;
%}

%%
/* Section 2: Pattern-Action Rules */
[0-9]+      { printf("Number: %s\n", yytext); }
[a-z]+      { printf("Word: %s\n", yytext); }
.           { /* Ignore other characters */ }
\n          { return 0; }
%%

/* Section 3: C Functions */
int yywrap() {
    return 1;  // Return 1 to indicate end of input
}

int main() {
    yylex();  // Start lexical analysis
    return 0;
}
```

---

## 🔑 Important Variables and Functions

### Built-in Variables
| Variable | Type | Description |
|----------|------|-------------|
| `yytext` | char* | Matched text string |
| `yyleng` | int | Length of matched text |
| `yyin` | FILE* | Input file pointer (default: stdin) |
| `yyout` | FILE* | Output file pointer (default: stdout) |

### Built-in Functions
| Function | Purpose |
|----------|---------|
| `yylex()` | Start lexical analysis |
| `yywrap()` | Called at end of file (return 1 to stop, 0 to continue) |

---

## 💻 Common Lex Patterns

### Extract Numbers
```c
[0-9]+      { printf("%s\n", yytext); }
```

### Extract Words
```c
[a-zA-Z]+   { printf("%s\n", yytext); }
```

### Case-Insensitive Match "hello"
```c
[Hh][Ee][Ll][Ll][Oo]   { printf("Found hello!\n"); }
```

### Count Lines
```c
\n          { line_count++; }
```

### Count Words
```c
[^ \t\n]+   { word_count++; }
```

### Ignore Whitespace
```c
[ \t]+      { /* Do nothing */ }
```

### Pass Through Everything Else
```c
.           { printf("%c", yytext[0]); }
```

---

## 🎨 Action Code Examples

### Print Matched Text
```c
pattern     { printf("%s", yytext); }
```

### Replace Text
```c
"old"       { printf("new"); }
```

### Count Occurrences
```c
pattern     { count++; }
```

### Store in Variable
```c
[0-9]+      { number = atoi(yytext); }
```

### Multiple Statements
```c
pattern     { 
    count++; 
    printf("Found: %s\n", yytext); 
}
```

---

## 📁 File I/O in Lex

### Read from File
```c
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Cannot open file\n");
        return 1;
    }
    
    yyin = file;
    yylex();
    fclose(file);
    
    return 0;
}
```

### Write to File
```c
int main() {
    FILE *output = fopen("output.txt", "w");
    yyout = output;
    yylex();
    fclose(output);
    return 0;
}
```

---

## 🐛 Common Errors and Fixes

### Error: "flex: command not found"
```bash
sudo apt-get install flex
```

### Error: "cannot find -lfl"
```bash
# Try these alternatives:
gcc lex.yy.c -o program -ll
# or
gcc lex.yy.c -o program
```

### Error: "undefined reference to yywrap"
Add this function to your Lex file:
```c
int yywrap() {
    return 1;
}
```

### Pattern Not Matching
- Check pattern order (longer patterns first)
- Escape special characters: `\.` for dot
- Use `[ \t]+` not ` ` for whitespace

---

## 🚀 Testing Your Programs

### Objective 1 (Extract Numbers)
```bash
echo "a1b22c3" | ./objective1
# Output: 1, 22, 3 (each on new line)
```

### Objective 2 (Replace String)
```bash
echo "This is charusat." | ./objective2
# Output: This is university.
```

### Objective 3 (Count)
```bash
echo "The 45 is odd number." > test.txt
./objective3 test.txt
# Output: Characters: 22, Words: 5, Line: 1
```

### Objective 4 (Password)
```bash
echo "Passw0rd@123" | ./objective4
# Output: Valid password
```

---

## 📚 Character Classes

### POSIX Character Classes (Alternative Syntax)
| Class | Equivalent | Matches |
|-------|-----------|---------|
| `[:digit:]` | `[0-9]` | Digits |
| `[:alpha:]` | `[a-zA-Z]` | Letters |
| `[:alnum:]` | `[0-9a-zA-Z]` | Alphanumeric |
| `[:space:]` | `[ \t\n\r]` | Whitespace |
| `[:upper:]` | `[A-Z]` | Uppercase |
| `[:lower:]` | `[a-z]` | Lowercase |

Usage example:
```c
[[:digit:]]+    { printf("Number: %s\n", yytext); }
```

---

## 🎯 Pro Tips

1. **Pattern Order Matters**: Place more specific patterns before general ones
2. **Longest Match Wins**: Lex always matches the longest possible string
3. **Test Incrementally**: Start with simple patterns, then add complexity
4. **Use Comments**: Document complex patterns
5. **Handle All Cases**: Add a catch-all pattern (`.`) to avoid unmatched input
6. **Escape Special Chars**: Use `\` before special characters like `.`, `*`, `+`

---

## 🔗 Useful Resources

- **Flex Manual**: https://westes.github.io/flex/manual/
- **Regex Tester**: https://regex101.com
- **Tutorial**: https://www.tutorialspoint.com/lex/

---

## ⚡ Cheat Sheet Summary

```bash
# Install
sudo apt-get install flex gcc

# Compile
flex program.l && gcc lex.yy.c -o program -lfl

# Run
./program < input.txt
./program input.txt  # If program reads argv[1]

# Debug - See generated C code
cat lex.yy.c

# Clean
rm lex.yy.c program
```

---

**Remember**: Practice makes perfect! Try modifying patterns and see what happens. 🚀
