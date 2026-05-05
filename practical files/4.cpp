#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void objective1() {
    cout << "Enter string: ";
    string s;
    getline(cin, s);
    string num;
    for (char c : s) {
        if (isdigit((unsigned char)c)) num += c;
        else if (!num.empty()) {
            cout << num << "\n";
            num.clear();
        }
    }
    if (!num.empty()) cout << num << "\n";
}

bool equalIgnoreCase(const string& text, int pos, const string& target) {
    if (pos + (int)target.size() > (int)text.size()) return false;
    for (int i = 0; i < (int)target.size(); i++) {
        if (tolower((unsigned char)text[pos + i]) != tolower((unsigned char)target[i])) return false;
    }
    return true;
}

void objective2() {
    cout << "Enter string: ";
    string s;
    getline(cin, s);

    string out;
    string from = "charusat";
    string to = "university";

    for (int i = 0; i < (int)s.size();) {
        if (equalIgnoreCase(s, i, from)) {
            out += to;
            i += (int)from.size();
        } else {
            out += s[i++];
        }
    }

    cout << out << "\n";
}

void objective3() {
    cout << "Enter file name: ";
    string fileName;
    getline(cin, fileName);

    ifstream in(fileName);
    if (!in) {
        cout << "Cannot open file\n";
        return;
    }

    long long chars = 0, words = 0, lines = 0;
    bool inWord = false;
    char c;
    while (in.get(c)) {
        chars++;
        if (c == '\n') lines++;
        if (isspace((unsigned char)c)) inWord = false;
        else if (!inWord) {
            words++;
            inWord = true;
        }
    }
    if (chars > 0 && lines == 0) lines = 1;

    cout << "Characters : " << chars << "\n";
    cout << "Words : " << words << "\n";
    cout << "Line : " << lines << "\n";
}

void objective4() {
    cout << "Enter password: ";
    string p;
    getline(cin, p);

    if ((int)p.size() < 9 || (int)p.size() > 15) {
        cout << "Invalid password\n";
        return;
    }

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    string specials = "*,;#$@";

    for (char c : p) {
        if (islower((unsigned char)c)) hasLower = true;
        else if (isupper((unsigned char)c)) hasUpper = true;
        else if (isdigit((unsigned char)c)) hasDigit = true;
        else if (specials.find(c) != string::npos) hasSpecial = true;
    }

    if (hasLower && hasUpper && hasDigit && hasSpecial) cout << "Valid password\n";
    else cout << "Invalid password\n";
}

int main() {
    cout << "Choose objective (1-4): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) objective1();
    else if (choice == 2) objective2();
    else if (choice == 3) objective3();
    else if (choice == 4) objective4();
    else cout << "Invalid choice\n";

    return 0;
}
