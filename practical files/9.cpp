#include <iostream>
#include <string>

using namespace std;

string input;
int pos = 0;

char peekChar() {
    while (pos < (int)input.size() && input[pos] == ' ') pos++;
    if (pos >= (int)input.size()) return '\0';
    return input[pos];
}

void consume() {
    while (pos < (int)input.size() && input[pos] == ' ') pos++;
    if (pos < (int)input.size()) pos++;
}

bool parseS();

bool parseE() {
    if (peekChar() == 'b') {
        consume();
        return true;
    }
    return false;
}

bool parseSPrime() {
    if (peekChar() == 'e') {
        consume();
        return parseS();
    }
    return true;
}

bool parseS() {
    if (peekChar() == 'i') {
        consume();
        if (!parseE()) return false;
        if (peekChar() != 't') return false;
        consume();
        if (!parseS()) return false;
        return parseSPrime();
    }

    if (peekChar() == 'a') {
        consume();
        return true;
    }

    return false;
}

int main() {
    cout << "Enter string: ";
    getline(cin, input);

    bool ok = parseS();
    while (pos < (int)input.size() && input[pos] == ' ') pos++;

    if (ok && pos == (int)input.size()) cout << "Valid string\n";
    else cout << "Invalid string\n";

    return 0;
}
