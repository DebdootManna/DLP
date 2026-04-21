/*
 * String Parsing using YACC-style Grammar (Recursive Descent Parser in C++)
 *
 * Grammar:
 *   S  -> i E t S S' | a
 *   S' -> e S | ε
 *   E  -> b
 *
 * This is an LL(1) grammar implemented as a recursive descent parser.
 * Tokens: i, b, t, e, a (single characters)
 *
 * Usage: echo "ibtai" | ./string_parser
 *    or: ./string_parser <<< "ibtai"
 */

#include <iostream>
#include <string>
using namespace std;

string input;
int pos;

// Forward declarations
bool parseS();
bool parseSPrime();
bool parseE();

// Peek at current character (skip spaces)
char peek() {
    while (pos < (int)input.size() && input[pos] == ' ')
        pos++;
    if (pos >= (int)input.size()) return '\0';
    return input[pos];
}

// Consume and return current character
char consume() {
    while (pos < (int)input.size() && input[pos] == ' ')
        pos++;
    if (pos >= (int)input.size()) return '\0';
    return input[pos++];
}

// E -> b
bool parseE() {
    if (peek() == 'b') {
        consume();
        return true;
    }
    return false;
}

// S' -> e S | ε
bool parseSPrime() {
    if (peek() == 'e') {
        consume(); // consume 'e'
        return parseS();
    }
    // ε production — always succeeds (S' can be empty)
    return true;
}

// S -> i E t S S' | a
bool parseS() {
    char c = peek();

    if (c == 'i') {
        consume(); // consume 'i'
        if (!parseE()) return false;
        if (peek() != 't') return false;
        consume(); // consume 't'
        if (!parseS()) return false;
        return parseSPrime();
    } else if (c == 'a') {
        consume(); // consume 'a'
        return true;
    }
    return false;
}

int main() {
    string line;
    if (!getline(cin, line)) {
        cerr << "No input provided." << endl;
        return 1;
    }

    input = line;
    pos = 0;

    bool valid = parseS();

    // After parsing S, we must have consumed all input
    // (skip trailing spaces)
    while (pos < (int)input.size() && input[pos] == ' ')
        pos++;

    if (valid && pos == (int)input.size()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}
