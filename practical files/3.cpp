#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cctype>

using namespace std;

bool isKeyword(const string& s) {
    static const set<string> keywords = {
        "auto","break","case","char","const","continue","default","do","double","else",
        "enum","extern","float","for","goto","if","int","long","register","return",
        "short","signed","sizeof","static","struct","switch","typedef","union","unsigned",
        "void","volatile","while"
    };
    return keywords.count(s) > 0;
}

bool isPunctuation(char c) {
    string p = "(){}[];,:";
    return p.find(c) != string::npos;
}

bool isOperatorChar(char c) {
    string o = "+-*/%=<>!&|^~";
    return o.find(c) != string::npos;
}

int main() {
    string fileName;
    cout << "Enter C source file name: ";
    cin >> fileName;

    ifstream in(fileName);
    if (!in) {
        cout << "Cannot open file\n";
        return 0;
    }

    set<string> symbolTable;
    string line;

    while (getline(in, line)) {
        for (int i = 0; i < (int)line.size();) {
            if (isspace((unsigned char)line[i])) { i++; continue; }

            if (isalpha((unsigned char)line[i]) || line[i] == '_') {
                string token;
                while (i < (int)line.size() && (isalnum((unsigned char)line[i]) || line[i] == '_')) {
                    token += line[i++];
                }
                if (isKeyword(token)) cout << "Keyword: " << token << "\n";
                else {
                    cout << "Identifier: " << token << "\n";
                    symbolTable.insert(token);
                }
                continue;
            }

            if (isdigit((unsigned char)line[i])) {
                string token;
                bool invalid = false;
                while (i < (int)line.size() && (isalnum((unsigned char)line[i]) || line[i] == '.')) {
                    if (isalpha((unsigned char)line[i])) invalid = true;
                    token += line[i++];
                }
                if (invalid) cout << "Error: " << token << " invalid lexeme\n";
                else cout << "Constant: " << token << "\n";
                continue;
            }

            if (line[i] == '"' || line[i] == '\'') {
                char quote = line[i++];
                string token(1, quote);
                while (i < (int)line.size() && line[i] != quote) token += line[i++];
                if (i < (int)line.size()) token += line[i++];
                cout << "String: " << token << "\n";
                continue;
            }

            if (i + 1 < (int)line.size()) {
                string two = line.substr(i, 2);
                static const set<string> twoOps = {"==","!=","<=",">=","&&","||","++","--","+=","-=","*=","/=","%=","->","<<",">>"};
                if (twoOps.count(two)) {
                    cout << "Operator: " << two << "\n";
                    i += 2;
                    continue;
                }
            }

            if (isOperatorChar(line[i])) {
                cout << "Operator: " << line[i++] << "\n";
                continue;
            }

            if (isPunctuation(line[i])) {
                cout << "Punctuation: " << line[i++] << "\n";
                continue;
            }

            i++;
        }
    }

    cout << "\nSYMBOL TABLE ENTRIES\n";
    int index = 1;
    for (const auto& id : symbolTable) cout << index++ << ") " << id << "\n";

    return 0;
}
