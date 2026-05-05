#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <cctype>

using namespace std;

class Parser {
    string s;
    int pos = 0;

    void skipSpaces() {
        while (pos < (int)s.size() && s[pos] == ' ') pos++;
    }

    double parseE() {
        double val = parseT();
        while (true) {
            skipSpaces();
            if (pos < (int)s.size() && s[pos] == '+') {
                pos++;
                val += parseT();
            } else if (pos < (int)s.size() && s[pos] == '-') {
                pos++;
                val -= parseT();
            } else break;
        }
        return val;
    }

    double parseT() {
        double val = parseF();
        while (true) {
            skipSpaces();
            if (pos < (int)s.size() && s[pos] == '*') {
                pos++;
                val *= parseF();
            } else if (pos < (int)s.size() && s[pos] == '/') {
                pos++;
                double d = parseF();
                if (d == 0) throw runtime_error("Invalid expression");
                val /= d;
            } else break;
        }
        return val;
    }

    double parseF() {
        double base = parseG();
        skipSpaces();
        if (pos < (int)s.size() && s[pos] == '^') {
            pos++;
            double exp = parseF(); // right associative
            return pow(base, exp);
        }
        return base;
    }

    double parseG() {
        skipSpaces();

        if (pos < (int)s.size() && s[pos] == '(') {
            pos++;
            double val = parseE();
            skipSpaces();
            if (pos >= (int)s.size() || s[pos] != ')') throw runtime_error("Invalid expression");
            pos++;
            return val;
        }

        if (pos < (int)s.size() && (isdigit((unsigned char)s[pos]) || s[pos] == '.')) {
            int start = pos;
            while (pos < (int)s.size() && (isdigit((unsigned char)s[pos]) || s[pos] == '.')) pos++;
            return stod(s.substr(start, pos - start));
        }

        throw runtime_error("Invalid expression");
    }

public:
    double evaluate(const string& expr) {
        s = expr;
        pos = 0;
        double ans = parseE();
        skipSpaces();
        if (pos != (int)s.size()) throw runtime_error("Invalid expression");
        return ans;
    }
};

int main() {
    cout << "Enter arithmetic expression: ";
    string expr;
    getline(cin, expr);

    Parser parser;
    try {
        double ans = parser.evaluate(expr);
        if (ans == (long long)ans) cout << (long long)ans << "\n";
        else cout << ans << "\n";
    } catch (...) {
        cout << "Invalid expression\n";
    }

    return 0;
}
