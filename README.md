# Design of Language Processor (DLP) - Practical Implementations

[![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lex/Flex](https://img.shields.io/badge/Tool-Lex%2FFlex-green.svg)](https://github.com/westes/flex)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)](https://www.linux.org/)
[![Progress](https://img.shields.io/badge/Progress-10%2F14%20Practicals-orange.svg)](#practicals-overview)
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
- ✅ **Completed Practicals:** 10/14
- 🔄 **Status:** Active Development
- 📅 **Last Updated:** May 2026

---

## 📋 Table of Contents

- [Course Overview](#course-overview)
- [Practicals Overview](#practicals-overview)
- [Completed Practical Assignments](#completed-practical-assignments)
- [Study Materials](#-study-materials)
- [Technologies Used](#technologies-used)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Learning Outcomes](#learning-outcomes)
- [Upcoming Practicals](#upcoming-practicals)
- [Contributing](#contributing)

---

## 📊 Practicals Overview

| Status | Practical | Topic | Location |
|:------:|:---------:|:------|:---------|
| ✅ | 1 | String Pattern Matching | `practical files/1.cpp` |
| ✅ | 2 | Finite Automata Validator | `practical files/2.c` |
| ✅ | 3 | Lexical Analyzer (Manual) | `practical files/3.c` |
| ✅ | 4 | Lex/Flex Programming | `practical files/4/` |
| ✅ | 5 | Lexical Analyzer (Lex/Python) | `practical files/5/` |
| ✅ | 6 | Recursive Descent Parsing (RDP) | `practical files/6.c` |
| ✅ | 7 | FIRST and FOLLOW Sets | `practical files/7.cpp` |
| ✅ | 8 | LL(1) Parsing Table | `practical files/8.cpp` |
| ✅ | 9 | YACC-style Grammar Parsing | `practical files/9.cpp` |
| ✅ | 10 | SDD-based Bottom-Up Evaluation | `practical files/10.cpp` |
| 🔜 | 11-14 | *To be added as course progresses* | - |

**Legend:** ✅ Completed | 🔜 Upcoming | 🚧 In Progress

---

## 🎯 Completed Practical Assignments

### **Practical 1: String Pattern Matching**
**File:** `practical files/1.cpp`

Simple C++ program that validates if a given string follows the pattern: `a*bb` (multiple 'a's followed by exactly two 'b's).

---

### **Practical 2: Finite Automata String Validator**
**Files:** `practical files/2.c`, `practical files/2.md`

Implementation of a string validator using finite automata concepts. The program reads the definition of a finite automaton and validates input strings.

---

### **Practical 3: Lexical Analyzer for C Language (Manual)**
**Files:** `practical files/3.c`, `practical files/3.md`, `practical files/3test1.c`, etc.

A manual implementation of a lexical analyzer (scanner) that tokenizes C source code. Includes symbol table management and comment removal.

---

### **Practical 4: Lex (Flex) Programming - Basics**
**Directory:** `practical files/4/`

Collection of Lex programs for:
1. Extracting numbers.
2. Case-insensitive string replacement.
3. Counting characters, words, and lines.
4. Password validation.

---

### **Practical 5: Lexical Analyzer using Lex/Python**
**Directory:** `practical files/5/`

Advanced lexical analyzer implementation using **Lex/Flex** and **Python** to tokenize C source code into keywords, identifiers, constants, strings, operators, and punctuation.

---

### **Practical 6: Recursive Descent Parsing (RDP)**
**Files:** `practical files/6.c`, `practical files/6.md`

Implementation of a Recursive Descent Parser for a given grammar:
```
S → ( L ) | a
L → S L'
L' → , S L' | ε
```

---

### **Practical 7: FIRST and FOLLOW Sets**
**Files:** `practical files/7.cpp`, `practical files/7.md`

A C++ program to compute the **FIRST** and **FOLLOW** sets for all non-terminals in a given Context-Free Grammar (CFG).

---

### **Practical 8: LL(1) Parsing Table Construction**
**Files:** `practical files/8.cpp`, `practical files/8.md`

Constructs a predictive LL(1) parsing table and validates input strings using a non-recursive predictive parser.

---

### **Practical 9: YACC-style Grammar Parsing**
**Files:** `practical files/9.cpp`, `practical files/9.md`

Validates input strings based on an if-then-else grammar using recursive descent techniques typical of YACC-style parsers.

---

### **Practical 10: SDD-based Arithmetic Evaluation**
**Files:** `practical files/10.cpp`, `practical files/10.md`

Evaluates arithmetic expressions using a bottom-up parsing approach and Syntax-Directed Definitions (SDD). Supports operators like `+`, `-`, `*`, `/`, and `^`.

---

## 📚 Study Materials

The `study materials/` directory contains resources for learning DLP:
- **Notes:** Comprehensive notes for Internals and specific units.
- **PPTs:** Slides covering topics from Lexical Analysis to Code Generation.
- **Previous Papers:** University and internal exam papers for practice.
- **Syllabus:** Detailed course curriculum.

---

## 📁 Project Structure

```
DLP/
├── README.md                    # This file
├── .gitignore                   # Git ignore configuration
├── practical files/             # Implementation of practicals
│   ├── 1.cpp                    # String pattern matching
│   ├── 2.c, 2.md                # Finite automata validator
│   ├── 3.c, 3.md                # Lexical analyzer
│   ├── 4/                       # Lex/Flex practicals (Objectives 1-4)
│   ├── 5/                       # Advanced Lexical Analyzer
│   ├── 6.c, 6.md                # Recursive Descent Parser
│   ├── 7.cpp, 7.md              # First and Follow sets
│   ├── 8.cpp, 8.md              # LL(1) Parser
│   ├── 9.cpp, 9.md              # YACC-style Parsing
│   ├── 10.cpp, 10.md            # SDD Arithmetic Evaluation
│   └── Docs/                    # Practical write-ups (PDF/DOCX)
└── study materials/             # Course resources
    ├── notes/                   # PDF/Word notes
    ├── PPTs/                    # Presentation slides
    └── previous years papers/   # Exam papers
```

---

## 🛠️ Technologies Used

- **Languages:** C, C++, Python
- **Tools:** 
  - Lex/Flex (Lexical Analyzer Generator)
  - GCC/Clang (C/C++ Compilers)
- **Platforms:** macOS, Linux

---

## 🚀 Usage

### Compiling and Running

Most practicals can be compiled using GCC or Clang. Example for Practical 7:
```bash
cd "practical files"
g++ -o 7 7.cpp
./7
```

For Lex programs (Practical 4 & 5):
```bash
cd "practical files/4"
flex objective1.l
gcc -o objective1 lex.yy.c -lfl
./objective1
```

---

## 🔮 Upcoming Practicals

The following topics will be covered in upcoming practicals:
- LALR and SLR Parsing
- Intermediate Code Generation (Three-address code)
- Code Optimization techniques
- Target Code Generation

---

## 📄 License

This project is created for educational purposes as part of the Design of Language Processor course curriculum.

**Happy Coding! 🚀**
