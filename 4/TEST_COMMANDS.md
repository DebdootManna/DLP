# Test Cases - Command Lines for Lab Practical Performa

## 🎯 Objective 1: Extract Numbers

### Test Case 1: Basic Example (a1b22c3)
```bash
echo "a1b22c3" | ./objective1
```
**Expected Output:**
```
1
22
3
```

### Test Case 2: Power Operation (12 ** 3 = 1728)
```bash
echo "power operation -> 12 ** 3 = 1728" | ./objective1
```
**Expected Output:**
```
12
3
1728
```

### Test Case 3: Multiplication Example
```bash
echo "You multiply 804569 with 1 then will be :" | ./objective1
```
**Expected Output:**
```
804569
1
```

---

## 🎯 Objective 2: Replace "charusat" with "university"

### Test Case 1: Simple Replacement (lowercase)
```bash
echo "This is charusat." | ./objective2
```
**Expected Output:**
```
This is university.
```

### Test Case 2: Capitalized Word
```bash
echo "Charusat is in Anand district." | ./objective2
```
**Expected Output:**
```
university is in Anand district.
```

### Test Case 3: Multiple Occurrences with Question
```bash
echo "Charusat , What is charusat?" | ./objective2
```
**Expected Output:**
```
university , What is university?
```

### Test Case 4: All Caps (CHARSAT - note typo in original)
```bash
echo "I am doing my BTech from CHARSAT." | ./objective2
```
**Expected Output:**
```
I am doing my BTech from university.
```

### Test Case 5: Multiple Occurrences
```bash
echo "Every where it is charusat , charusat and only charusat." | ./objective2
```
**Expected Output:**
```
Every where it is university , university and only university.
```

---

## 🎯 Objective 3: Count Characters, Words, Lines

### Test Case 1: Simple Line ("The 45 is odd number.")
```bash
# Create test file
echo "The 45 is odd number." > test3_case1.txt

# Run the program
./objective3 test3_case1.txt
```
**Expected Output:**
```
Characters : 22
Words : 5
Line : 1
```

### Test Case 2: Multi-line Text
```bash
# Create test file with multiple lines
cat > test3_case2.txt << 'EOF'
I want to calculate a number. The number of characters, words and lines.

All know that \n is ending character of line.
45 + 89 =40
EOF

# Run the program
./objective3 test3_case2.txt
```
**Expected Output:**
```
Characters : [count]
Words : [count]
Line : 3 or 4 (depending on final newline)
```

**Note:** The exact character and word count may vary based on how your program handles spaces and newlines.

---

## 🎯 Objective 4: Password Validation

### Test Case 1: Invalid (too short - a@1T)
```bash
echo "a@1T" | ./objective4
```
**Expected Output:**
```
Invalid password
```

### Test Case 2: Valid Password Examples
```bash
# Example 1: Passw0rd@123
echo "Passw0rd@123" | ./objective4
```
**Expected Output:**
```
Valid password
```

```bash
# Example 2: MyP@ssw0rd99
echo "MyP@ssw0rd99" | ./objective4
```
**Expected Output:**
```
Valid password
```

### Test Case 3: Invalid - No Uppercase
```bash
echo "password@123" | ./objective4
```
**Expected Output:**
```
Invalid password
```

### Test Case 4: Invalid - No Special Character
```bash
echo "Password123" | ./objective4
```
**Expected Output:**
```
Invalid password
```

### Test Case 5: Invalid - Too Long
```bash
echo "VeryLongPassword@12345" | ./objective4
```
**Expected Output:**
```
Invalid password
```

### Test Case 6: Invalid - No Digit
```bash
echo "Password@Only" | ./objective4
```
**Expected Output:**
```
Invalid password
```

### Test Case 7: Invalid - No Lowercase
```bash
echo "PASSWORD@123" | ./objective4
```
**Expected Output:**
```
Invalid password
```

---

## 📋 Quick Copy-Paste Version for Lab Performa

### Objective 1 - All Test Cases
```bash
# Test 1
echo "a1b22c3" | ./objective1

# Test 2
echo "power operation -> 12 ** 3 = 1728" | ./objective1

# Test 3
echo "You multiply 804569 with 1 then will be :" | ./objective1
```

### Objective 2 - All Test Cases
```bash
# Test 1
echo "This is charusat." | ./objective2

# Test 2
echo "Charusat is in Anand district." | ./objective2

# Test 3
echo "Charusat , What is charusat?" | ./objective2

# Test 4
echo "I am doing my BTech from CHARSAT." | ./objective2

# Test 5
echo "Every where it is charusat , charusat and only charusat." | ./objective2
```

### Objective 3 - Test Cases
```bash
# Test 1
echo "The 45 is odd number." > test_obj3.txt
./objective3 test_obj3.txt

# Test 2
cat > test_obj3_multi.txt << 'EOF'
I want to calculate a number. The number of characters, words and lines.

All know that \n is ending character of line.
45 + 89 =40
EOF
./objective3 test_obj3_multi.txt
```

### Objective 4 - All Test Cases
```bash
# Test 1 - Invalid (too short)
echo "a@1T" | ./objective4

# Test 2 - Valid
echo "Passw0rd@123" | ./objective4

# Test 3 - Invalid (no uppercase)
echo "password@123" | ./objective4

# Test 4 - Invalid (no special char)
echo "Password123" | ./objective4
```

---

## 💡 Pro Tips for Lab Performa

### Capturing Output to File
```bash
# Run test and save output to file
echo "a1b22c3" | ./objective1 > output1.txt
cat output1.txt
```

### Running All Tests at Once
```bash
# Create a test script
cat > run_all_tests.sh << 'EOF'
#!/bin/bash

echo "=== OBJECTIVE 1 TESTS ==="
echo "Test 1:"
echo "a1b22c3" | ./objective1
echo ""

echo "Test 2:"
echo "power operation -> 12 ** 3 = 1728" | ./objective1
echo ""

echo "=== OBJECTIVE 2 TESTS ==="
echo "Test 1:"
echo "This is charusat." | ./objective2
echo ""

echo "Test 2:"
echo "Charusat is in Anand district." | ./objective2
echo ""

echo "=== OBJECTIVE 4 TESTS ==="
echo "Test 1:"
echo "a@1T" | ./objective4
echo ""

echo "Test 2:"
echo "Passw0rd@123" | ./objective4
echo ""
EOF

chmod +x run_all_tests.sh
./run_all_tests.sh
```

### Taking Screenshots for Performa
```bash
# Run command and the output will appear on screen
# Then take screenshot using Cmd+Shift+4 on Mac

echo "a1b22c3" | ./objective1
# Take screenshot of terminal
```

---

## 📸 Screenshot Guide for Performa

For your lab practical performa, you'll need screenshots. Here's how:

1. **MacOS Screenshot Shortcuts:**
   - `Cmd + Shift + 3` - Full screen
   - `Cmd + Shift + 4` - Select area (recommended)
   - `Cmd + Shift + 5` - Screenshot menu with options

2. **What to Capture:**
   - Command line with input
   - Program output
   - Compile commands
   - Test results

3. **Example Session to Screenshot:**
```bash
# Clear terminal first
clear

# Show compilation
flex objective1.l && gcc lex.yy.c -o objective1 -ll

# Run test case
echo "a1b22c3" | ./objective1

# Now take screenshot (Cmd+Shift+4)
```

---

## 🎯 Format for Lab Performa Documentation

```
OBJECTIVE 1: Extract Numbers

Test Case 1:
Input: a1b22c3
Command: echo "a1b22c3" | ./objective1
Output:
1
22
3

Test Case 2:
Input: power operation -> 12 ** 3 = 1728
Command: echo "power operation -> 12 ** 3 = 1728" | ./objective1
Output:
12
3
1728
```

---

## ⚡ Complete Test Session (Copy-Paste Ready)

```bash
# Compile all programs first
flex objective1.l && gcc lex.yy.c -o objective1 -ll
flex objective2.l && gcc lex.yy.c -o objective2 -ll
flex objective3.l && gcc lex.yy.c -o objective3 -ll
flex objective4.l && gcc lex.yy.c -o objective4 -ll

# Clean up intermediate files
rm lex.yy.c

# Now run all test cases
echo "=== OBJECTIVE 1 ===" 
echo "a1b22c3" | ./objective1
echo ""
echo "power operation -> 12 ** 3 = 1728" | ./objective1
echo ""

echo "=== OBJECTIVE 2 ===" 
echo "This is charusat." | ./objective2
echo ""
echo "Charusat is in Anand district." | ./objective2
echo ""

echo "=== OBJECTIVE 3 ===" 
echo "The 45 is odd number." > test.txt
./objective3 test.txt
echo ""

echo "=== OBJECTIVE 4 ===" 
echo "a@1T" | ./objective4
echo ""
echo "Passw0rd@123" | ./objective4
```
