# 🔧 LEX Practical - Troubleshooting Guide

## Common Issues and Solutions

---

## 🚫 Installation Issues

### Issue 1: "flex: command not found"

**Symptoms:**
```bash
$ flex objective1.l
bash: flex: command not found
```

**Solutions:**

**For Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install flex
```

**For Fedora/RHEL:**
```bash
sudo dnf install flex
```

**For macOS:**
```bash
brew install flex
```

**Verification:**
```bash
flex --version
# Should output: flex 2.6.4 or similar
```

---

### Issue 2: "gcc: command not found"

**Symptoms:**
```bash
$ gcc lex.yy.c -o program
bash: gcc: command not found
```

**Solutions:**

**For Ubuntu/Debian:**
```bash
sudo apt-get install gcc build-essential
```

**For Fedora/RHEL:**
```bash
sudo dnf install gcc
```

**For macOS:**
```bash
xcode-select --install
```

---

## ⚙️ Compilation Issues

### Issue 3: "ld: cannot find -lfl"

**Symptoms:**
```bash
$ gcc lex.yy.c -o program -lfl
/usr/bin/ld: cannot find -lfl
collect2: error: ld returned 1 exit status
```

**Why This Happens:**
The flex library (`libfl`) is not installed or not found.

**Solutions (Try in Order):**

**Solution 1: Install libfl-dev**
```bash
sudo apt-get install libfl-dev
```

**Solution 2: Use -ll instead of -lfl**
```bash
gcc lex.yy.c -o program -ll
```

**Solution 3: Compile without the library**
```bash
gcc lex.yy.c -o program
```
Note: This works if your program defines `yywrap()`.

**Solution 4: Link statically**
```bash
gcc lex.yy.c -o program -static -lfl
```

---

### Issue 4: "undefined reference to `yywrap'"

**Symptoms:**
```bash
/tmp/ccXXXXXX.o: In function `yylex':
lex.yy.c:(.text+0x...): undefined reference to `yywrap'
```

**Why This Happens:**
The `yywrap()` function is not defined in your code.

**Solution:**
Add this function to your Lex file (in the third section):

```c
%%
// ... your patterns ...
%%

int yywrap() {
    return 1;  // Return 1 to indicate end of input
}

int main() {
    yylex();
    return 0;
}
```

**Alternative:** Use the `-lfl` or `-ll` flag which provides `yywrap()`:
```bash
gcc lex.yy.c -o program -lfl
```

---

### Issue 5: "multiple definition of `main'"

**Symptoms:**
```bash
/usr/bin/ld: /tmp/ccXXXXXX.o: in function `main':
lex.yy.c:(.text+0x...): multiple definition of `main'
```

**Why This Happens:**
You have multiple `main()` functions or are linking with a library that has one.

**Solution:**
Ensure you only have ONE `main()` function in your Lex file.

---

## 🐛 Runtime Issues

### Issue 6: Program Doesn't Accept Input

**Symptoms:**
- Program starts but doesn't wait for input
- Program terminates immediately
- No output is produced

**Solutions:**

**Check 1: Verify newline handling**
```c
\n          { return 0; }  // Make sure this exists
```

**Check 2: Test with echo**
```bash
echo "test input" | ./program
```

**Check 3: Try redirecting from file**
```bash
echo "test input" > input.txt
./program < input.txt
```

**Check 4: Verify yylex() is called**
```c
int main() {
    printf("Enter input:\n");  // Add this for debugging
    yylex();
    return 0;
}
```

---

### Issue 7: Pattern Not Matching

**Symptoms:**
- Input is accepted but not processed correctly
- Expected pattern doesn't trigger action
- Wrong pattern matches

**Diagnostic Steps:**

**Step 1: Add debug output**
```c
pattern     { printf("DEBUG: Matched pattern\n"); }
```

**Step 2: Check pattern order**
Lex matches patterns in order. More specific patterns should come FIRST:

```c
// WRONG ORDER:
.           { printf("Any char\n"); }
[0-9]+      { printf("Number\n"); }  // Never matches!

// CORRECT ORDER:
[0-9]+      { printf("Number\n"); }
.           { printf("Any char\n"); }
```

**Step 3: Verify special characters are escaped**
```c
// WRONG:
.           { /* Matches ANY character */ }
price: $5   { /* This is WRONG */ }

// CORRECT:
\.          { /* Matches literal dot */ }
"price: $5" { /* Use quotes for literal strings */ }
```

**Step 4: Test pattern in isolation**
Create a minimal test file:
```c
%%
[0-9]+      { printf("Found: %s\n", yytext); }
.           { }
\n          { return 0; }
%%

int yywrap() { return 1; }
int main() { yylex(); return 0; }
```

---

### Issue 8: File Not Found (Objective 3)

**Symptoms:**
```bash
$ ./objective3 input.txt
Error: Cannot open file input.txt
```

**Solutions:**

**Check 1: Verify file exists**
```bash
ls -la input.txt
```

**Check 2: Check file permissions**
```bash
chmod 644 input.txt
```

**Check 3: Use absolute path**
```bash
./objective3 /full/path/to/input.txt
```

**Check 4: Verify your code**
```c
FILE *file = fopen(argv[1], "r");
if (!file) {
    perror("Error opening file");  // Better error message
    return 1;
}
```

---

### Issue 9: Wrong Character/Word/Line Count (Objective 3)

**Symptoms:**
- Count is off by one
- Doesn't count the last line
- Spaces counted as words

**Solutions:**

**For character count:**
```c
\n              { char_count++; line_count++; }
[ \t]+          { char_count += yyleng; }  // Use yyleng!
[^ \t\n]+       { word_count++; char_count += yyleng; }
```

**For line count:**
Ensure last line without `\n` is counted:
```c
<<EOF>>         { line_count++; return 0; }  // Count last line
```

**For word count:**
```c
[^ \t\n]+       { word_count++; }  // Match non-whitespace
```

---

### Issue 10: Case Sensitivity Issues (Objective 2)

**Symptoms:**
- "charusat" replaced but "CHARUSAT" is not
- Case-insensitive match not working

**Solution:**
Use explicit case-insensitive pattern:

```c
// Match all variations of "charusat"
[Cc][Hh][Aa][Rr][Uu][Ss][Aa][Tt]    { printf("university"); }
```

**Alternative using start conditions:**
```c
%option caseless

%%
charusat    { printf("university"); }
%%
```

---

### Issue 11: Password Validation Always Returns Invalid (Objective 4)

**Symptoms:**
- Valid password marked as invalid
- Rules not properly checked

**Debug Steps:**

**Step 1: Add debug output**
```c
int main() {
    printf("Enter password:\n");
    yylex();
    
    printf("DEBUG: Length=%d, Lower=%d, Upper=%d, Digit=%d, Special=%d\n",
           pwd_len, has_lower, has_upper, has_digit, has_special);
    
    // ... validation code ...
}
```

**Step 2: Verify special characters**
Ensure your pattern includes all required special characters:
```c
[*,;#$@]    { has_special = 1; }
```

**Step 3: Check length boundaries**
```c
if (pwd_len >= 9 && pwd_len <= 15) {
    // Valid length
}
```

---

## 📊 Output Format Issues

### Issue 12: Output Has Extra Characters

**Symptoms:**
- Unexpected spaces or newlines in output
- Output contains "text" variable name

**Solutions:**

**Check 1: Use correct format specifiers**
```c
// WRONG:
printf("%d", yytext);  // yytext is char*, not int!

// CORRECT:
printf("%s", yytext);  // Use %s for strings
printf("%d", atoi(yytext));  // Convert to int first
```

**Check 2: Handle whitespace properly**
```c
[ \t]+      { /* Ignore - don't print */ }
\n          { printf("\n"); }  // Only print newline when needed
```

---

### Issue 13: Numbers Not on Separate Lines (Objective 1)

**Symptoms:**
```bash
# Expected:
1
22
3

# Got:
1223
```

**Solution:**
Add `\n` after each number:
```c
[0-9]+      { printf("%s\n", yytext); }  // Note the \n
```

---

## 🔍 Debugging Techniques

### Technique 1: Examine Generated C Code
```bash
flex program.l
cat lex.yy.c | less
# Look for your patterns and actions
```

### Technique 2: Add Trace Statements
```c
%%
[0-9]+      { 
    printf("DEBUG: Found number: %s\n", yytext); 
    printf("%s\n", yytext); 
}
%%
```

### Technique 3: Test Incrementally
Start with a minimal program and add complexity:

**Step 1: Basic skeleton**
```c
%%
.           { printf("%c", yytext[0]); }
%%
int yywrap() { return 1; }
int main() { yylex(); return 0; }
```

**Step 2: Add your pattern**
```c
%%
[0-9]+      { printf("NUMBER: %s\n", yytext); }
.           { printf("%c", yytext[0]); }
%%
```

**Step 3: Refine**

### Technique 4: Use GDB
```bash
gcc -g lex.yy.c -o program -lfl
gdb ./program
(gdb) break yylex
(gdb) run
(gdb) step
```

---

## 🎯 Best Practices to Avoid Issues

### 1. Always Define yywrap()
```c
int yywrap() {
    return 1;
}
```

### 2. Initialize Variables
```c
int count = 0;  // Don't use uninitialized variables
```

### 3. Handle All Input Cases
```c
%%
[0-9]+      { /* Handle numbers */ }
[a-zA-Z]+   { /* Handle words */ }
[ \t]+      { /* Handle whitespace */ }
.           { /* Handle everything else */ }
\n          { /* Handle newline */ }
%%
```

### 4. Test Edge Cases
- Empty input
- Very long input
- Special characters
- Multiple spaces
- Lines without newlines

### 5. Use Descriptive Error Messages
```c
if (!file) {
    printf("Error: Cannot open file '%s'\n", argv[1]);
    return 1;
}
```

---

## 📞 Getting Help

If you're still stuck:

1. **Check error messages carefully** - They often tell you exactly what's wrong
2. **Search online** - Many others have had similar issues
3. **Review the Flex manual** - https://westes.github.io/flex/manual/
4. **Ask on forums** - Stack Overflow, Reddit r/learnprogramming
5. **Consult with peers or instructor**

---

## ✅ Pre-Submission Checklist

Before submitting your practical:

- [ ] All programs compile without errors
- [ ] All programs run without segmentation faults
- [ ] All test cases pass
- [ ] Output format matches requirements exactly
- [ ] Code is properly commented
- [ ] README.md is included
- [ ] No warnings during compilation

---

## 🚀 Quick Fix Commands

```bash
# Complete reinstall of tools
sudo apt-get remove flex gcc
sudo apt-get update
sudo apt-get install flex gcc build-essential

# Clean all build artifacts
rm -f *.o lex.yy.c objective1 objective2 objective3 objective4

# Recompile everything
./compile.sh

# Run tests
./test.sh
```

---

**Remember:** Most issues are simple typos or missing semicolons. Read error messages carefully! 🔍
