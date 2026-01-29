# Design of Language Processor (DLP) - Practical Implementations

[![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lex/Flex](https://img.shields.io/badge/Tool-Lex%2FFlex-green.svg)](https://github.com/westes/flex)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)](https://www.linux.org/)
[![Progress](https://img.shields.io/badge/Progress-4%2F14%20Practicals-orange.svg)](#practicals-overview)
[![Status](https://img.shields.io/badge/Status-Active%20Development-brightgreen.svg)](#)

A comprehensive collection of practical implementations for the **Design of Language Processor (DLP)** course, covering fundamental concepts of automata theory, lexical analysis, parsing, and compiler design principles.

> **📌 Note:** This repository is actively maintained and will be continuously updated with new practicals throughout the semester. Expected total: **13-14 practicals**.

## 📚 Course Overview

This repository contains implementations of various compiler design and automata theory concepts, organized as practical assignments for the **Design of Language Processor (DLP)** course in Semester 6 of the Computer Science curriculum.

**Student Information:**
- **Name:** Debdoot Manna
- **Roll No:** 23CS043
- **Course:** Design of Language Processor (DLP)
- **Semester:** 6

**Repository Status:**
- ✅ **Completed Practicals:** 4/14
- 🔄 **Status:** Active Development
- 📅 **Last Updated:** January 2026

---

## 📋 Table of Contents

- [Course Overview](#course-overview)
- [Practicals Overview](#practicals-overview)
- [Completed Practical Assignments](#completed-practical-assignments)
- [Technologies Used](#technologies-used)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Learning Outcomes](#learning-outcomes)
- [Upcoming Practicals](#upcoming-practicals)
- [Contributing](#contributing)

---

## 📊 Practicals Overview

| Status | Practical | Topic | Files |
|:------:|:---------:|:------|:------|
| ✅ | 1 | String Pattern Matching | `1.cpp` |
| ✅ | 2 | Finite Automata Validator | `2.c`, `2.md` |
| ✅ | 3 | Lexical Analyzer for C | `3.c`, `3.md` |
| ✅ | 4 | Lex/Flex Programming | `4/` directory |
| 🔜 | 5-14 | *To be added as course progresses* | - |

**Legend:** ✅ Completed | 🔜 Upcoming | 🚧 In Progress

---

## 🎯 Completed Practical Assignments

### **Practical 1: String Pattern Matching**
**File:** `1.cpp`

Simple C++ program that validates if a given string follows the pattern: `a*bb` (multiple 'a's followed by exactly two 'b's).

**Concepts Covered:**
- Basic string validation
- Pattern matching using loops
- Input/output handling

**Execution:**
```bash
clang++ -o 1 1.cpp && ./1
```

---

### **Practical 2: Finite Automata String Validator**
**Files:** `2.c`, `2.md`

Implementation of a string validator using finite automata concepts. The program reads the definition of a finite automaton (states, transitions, accepting states) and validates whether a given input string is accepted.

**Concepts Covered:**
- Finite State Machines (FSM)
- Transition tables
- Accepting/Rejecting states
- Automata simulation

**Execution:**
```bash
gcc -o 2 2.c -Wall && ./2
```

**Documentation:** Refer to [2.md](2.md) for detailed input format and examples.

---

### **Practical 3: Lexical Analyzer for C Language**
**Files:** `3.c`, `3.md`, `3test1.c`, `3test2.c`, `3test3.c`

A comprehensive lexical analyzer (scanner) that tokenizes C source code and performs the first phase of compilation. Includes symbol table management, comment removal, and error detection.

**Features:**
- Recognizes all 32 ANSI C keywords
- Tokenizes identifiers, constants, strings, operators, and punctuation
- Handles single-line (`//`) and multi-line (`/* */`) comments
- Detects lexical errors with line/column information
- Maintains a symbol table for identifiers

**Concepts Covered:**
- Lexical analysis
- Tokenization
- Symbol table management
- Error handling and reporting

**Execution:**
```bash
gcc -o 3 3.c -Wall && ./3 3test1.c
```

**Documentation:** Refer to [3.md](3.md) for comprehensive documentation and test cases.

---

### **Practical 4: Lex (Flex) Programming - String Validation**
**Directory:** `4/`

Collection of **Lex** programs demonstrating string validation and manipulation using the Lex/Flex tool. This practical contains 4 objectives covering different aspects of lexical analysis.

#### Objectives:

| Objective | File | Description |
|-----------|------|-------------|
| **1** | `objective1.l` | Extract and display numbers from input strings |
| **2** | `objective2.l` | Case-insensitive string replacement ("charusat" → "university") |
| **3** | `objective3.l` | Count characters, words, and lines in text files |
| **4** | `objective4.l` | Password validation (8+ chars, uppercase, lowercase, digit, special char) |

**Concepts Covered:**
- Lex/Flex tool usage
- Regular expressions in Lex
- Pattern matching
- Token extraction
- Text processing

**Compilation & Execution:**
```bash
cd 4/
flex objective1.l
gcc -o objective1 lex.yy.c -lfl
./objective1
```

**Documentation:** Refer to [4/README.md](4/README.md) for detailed instructions, troubleshooting, and platform-specific guides.

---

## 🛠️ Technologies Used

- **Languages:** C, C++
- **Tools:** 
  - Lex/Flex (Lexical Analyzer Generator)
  - GCC/Clang (C/C++ Compilers)
- **Build Systems:** Manual compilation, shell scripts
- **Version Control:** Git & GitHub

---

## 📦 Prerequisites

### Required Software

- **Operating System:** Linux, macOS, or Windows with WSL
- **Compilers:**
  - GCC (GNU Compiler Collection) - for C programs
  - Clang - for C++ programs
- **Lex Tool:** Flex (Fast Lexical Analyzer Generator)

### Installation Commands

#### Ubuntu/Debian Linux:
```bash
sudo apt-get update
sudo apt-get install build-essential flex
```

#### macOS:
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Install Flex (if needed)
brew install flex
```

#### Fedora/RHEL:
```bash
sudo dnf install gcc gcc-c++ flex
```

#### Windows (WSL):
```bash
# Install Ubuntu from Microsoft Store, then:
sudo apt-get install build-essential flex
```

---

## 📁 Project Structure

```
DLP/
│
├── README.md                    # This file
├── .gitignore                   # Git ignore configuration
│
├── 1                            # Compiled executable (Practical 1)
├── 1.cpp                        # String pattern matching
│
├── 2                            # Compiled executable (Practical 2)
├── 2.c                          # Finite automata validator
├── 2.md                         # Practical 2 documentation
├── 2.dSYM/                      # Debug symbols (macOS)
│
├── 3                            # Compiled executable (Practical 3)
├── 3.c                          # Lexical analyzer
├── 3.md                         # Practical 3 documentation
├── 3test1.c                     # Test file 1 for lexer
├── 3test2.c                     # Test file 2 for lexer
├── 3test3.c                     # Test file 3 for lexer
│
├── 4/                           # Lex/Flex practicals
│   ├── README.md                # Detailed Lex guide
│   ├── QUICK_REFERENCE.md       # Quick reference for Lex
│   ├── TROUBLESHOOTING.md       # Common issues and fixes
│   ├── MACOS_GUIDE.md           # macOS-specific instructions
│   ├── objective1.l             # Extract numbers
│   ├── objective2.l             # String replacement
│   ├── objective3.l             # Count chars/words/lines
│   ├── objective4.l             # Password validation
│   ├── objective1-4             # Compiled executables
│   ├── compile.sh               # Compilation script
│   ├── macos_setup.sh           # macOS setup script
│   └── test.sh                  # Test script
│
└── Docs/                        # Additional documentation
```

---

## 🚀 Usage

### General Workflow

1. **Navigate to the project directory:**
   ```bash
   cd DLP/
   ```

2. **For C programs (Practicals 1-3):**
   ```bash
   # Compile
   gcc -o <output> <source>.c -Wall
   
   # Execute
   ./<output>
   ```

3. **For C++ programs:**
   ```bash
   # Compile
   clang++ -o <output> <source>.cpp
   
   # Execute
   ./<output>
   ```

4. **For Lex programs (Practical 4):**
   ```bash
   cd 4/
   
   # Compile
   flex <objective>.l
   gcc -o <output> lex.yy.c -lfl
   
   # Execute
   ./<output>
   ```

### Quick Start Examples

```bash
# Run string pattern validator
./1

# Run finite automata validator
./2

# Run lexical analyzer on test file
./3 3test1.c

# Run Lex objective 1
cd 4 && ./objective1
```

---

## 📖 Learning Outcomes

Through these practical implementations, the following concepts are demonstrated:

### **Automata Theory**
- Finite State Machines (FSM)
- State transitions and transition tables
- Accepting and rejecting states
- String recognition using automata

### **Lexical Analysis**
- Tokenization and pattern recognition
- Symbol table management
- Comment handling (single-line and multi-line)
- Error detection and reporting
- Regular expressions

### **Lex/Flex Programming**
- Writing Lex specifications
- Pattern matching with regular expressions
- Building lexical analyzers
- Text processing and validation

### **Compiler Design Fundamentals**
- First phase of compilation (scanning/lexing)
- Token classification (keywords, identifiers, constants, operators)
- Source code preprocessing
- Error handling in compilers

---

## 🐛 Troubleshooting

### Common Issues

1. **Command not found: flex**
   ```bash
   # Install Flex
   sudo apt-get install flex  # Linux
   brew install flex          # macOS
   ```

2. **Compilation errors with Lex**
   ```bash
   # Use -lfl flag
   gcc -o output lex.yy.c -lfl
   ```

3. **Permission denied when executing**
   ```bash
   chmod +x <filename>
   ```

4. **macOS-specific issues**
   - Refer to [4/MACOS_GUIDE.md](4/MACOS_GUIDE.md) for platform-specific instructions

For detailed troubleshooting, see [4/TROUBLESHOOTING.md](4/TROUBLESHOOTING.md).

---

## 🔮 Upcoming Practicals

The following practicals will be added as the course progresses:

- **Practical 5-14:** Topics to be covered include:
  - Parsing techniques (Top-Down, Bottom-Up)
  - LL and LR parsers
  - Syntax-directed translation
  - Intermediate code generation
  - Symbol table management
  - Code optimization
  - Error handling and recovery
  - *Additional topics as per curriculum*

> **Note:** This section will be updated with specific details as each practical is assigned and completed.

---

## 🤝 Contributing

This repository is maintained for educational purposes as part of college coursework. While direct contributions are not expected, feel free to:

- **Report Issues:** Open an issue if you find bugs or errors
- **Suggest Improvements:** Propose enhancements or optimizations
- **Share Feedback:** Provide feedback on implementations
- **Star the Repository:** If you find this helpful for your own learning!

---

## 📄 License

This project is created for educational purposes as part of the Design of Languages and Parsers course curriculum. All code is provided as-is for learning and reference purposes.

---

## 📞 Contact

**Debdoot Manna**  
Roll No: 23CS043  
Course: Design of Language Processor (DLP)  
Semester 6 - Computer Science

*This repository is continuously updated with new practicals throughout the semester.*

---

## 🙏 Acknowledgments

- Course instructors and teaching assistants
- CHARUSAT University curriculum
- Open-source Flex/Lex community
- Various online compiler design resources

---

**Happy Coding! 🚀**
