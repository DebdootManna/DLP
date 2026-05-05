#include <iostream>
#include <string>

using namespace std;

string input;
int pos = 0;
bool errorFlag = false;

char currentChar() {
    if (pos >= (int)input.size()) return '\0';
    return input[pos];
}

void consume(char expected) {
    if (currentChar() == expected) pos++;
    else errorFlag = true;
}

void parseS();
void parseL();
void parseLPrime();

void parseS() {
    if (errorFlag) return;
    if (currentChar() == '(') {
        consume('(');
        parseL();
        consume(')');
    } else if (currentChar() == 'a') {
        consume('a');
    } else {
        errorFlag = true;
    }
}

void parseL() {
    parseS();
    parseLPrime();
}

void parseLPrime() {
    if (currentChar() == ',') {
        consume(',');
        parseS();
        parseLPrime();
    }
}

int main() {
    cout << "Enter string: ";
    getline(cin, input);

    string cleaned;
    for (char c : input) if (c != ' ') cleaned += c;
    input = cleaned;

    parseS();

    if (!errorFlag && pos == (int)input.size()) cout << "Valid string\n";
    else cout << "Invalid string\n";

    return 0;
}
