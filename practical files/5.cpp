#include <iostream>
#include <fstream>
#include <string>
#include <set>
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

int main() {
    cout << "Enter C file name: ";
    string file;
    cin >> file;

    ifstream in(file);
    if (!in) {
        cout << "Cannot open file\n";
        return 0;
    }

    set<string> identifiers;
    string line;
    while (getline(in, line)) {
        for (int i = 0; i < (int)line.size();) {
            if (isspace((unsigned char)line[i])) { i++; continue; }

            if (i + 1 < (int)line.size() && line[i] == '/' && line[i + 1] == '/') break;

            if (isalpha((unsigned char)line[i]) || line[i] == '_') {
                string t;
                while (i < (int)line.size() && (isalnum((unsigned char)line[i]) || line[i] == '_')) t += line[i++];
                if (isKeyword(t)) cout << "Keyword: " << t << "\n";
                else {
                    cout << "Identifier: " << t << "\n";
                    identifiers.insert(t);
                }
                continue;
            }

            if (isdigit((unsigned char)line[i])) {
                string t;
                while (i < (int)line.size() && (isdigit((unsigned char)line[i]) || line[i] == '.')) t += line[i++];
                cout << "Constant: " << t << "\n";
                continue;
            }

            if (line[i] == '"' || line[i] == '\'') {
                char q = line[i++];
                string t(1, q);
                while (i < (int)line.size() && line[i] != q) t += line[i++];
                if (i < (int)line.size()) t += line[i++];
                cout << "String: " << t << "\n";
                continue;
            }

            string punct = "(){}[];,:";
            string ops = "+-*/%=<>!&|^~";
            if (punct.find(line[i]) != string::npos) cout << "Punctuation: " << line[i] << "\n";
            else if (ops.find(line[i]) != string::npos) cout << "Operator: " << line[i] << "\n";
            i++;
        }
    }

    cout << "\nSYMBOL TABLE ENTRIES\n";
    int n = 1;
    for (const string& id : identifiers) cout << n++ << ") " << id << "\n";

    return 0;
}
