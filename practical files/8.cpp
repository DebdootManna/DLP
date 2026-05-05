#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isTerminal(char c) {
    return c == 'a' || c == 'b' || c == 'c' || c == '(' || c == ')' || c == '$';
}

// Grammar:
// S  -> T S'
// S' -> T S' | eps
// T  -> ( S ) | a | b | c
bool parseLL1(const string& str) {
    string input = str + "$";
    stack<char> st;
    st.push('$');
    st.push('S');

    int i = 0;
    while (!st.empty()) {
        char top = st.top();
        char look = input[i];

        if (top == '$' && look == '$') return true;

        if (isTerminal(top)) {
            if (top == look) {
                st.pop();
                i++;
            } else {
                return false;
            }
            continue;
        }

        st.pop();

        if (top == 'S') {
            if (look == 'a' || look == 'b' || look == 'c' || look == '(') {
                st.push('P'); // P means S'
                st.push('T');
            } else return false;
        } else if (top == 'P') {
            if (look == 'a' || look == 'b' || look == 'c' || look == '(') {
                st.push('P');
                st.push('T');
            } else if (look == ')' || look == '$') {
                // epsilon
            } else return false;
        } else if (top == 'T') {
            if (look == 'a' || look == 'b' || look == 'c') {
                st.push(look);
            } else if (look == '(') {
                st.push(')');
                st.push('S');
                st.push('(');
            } else return false;
        } else {
            return false;
        }
    }

    return false;
}

int main() {
    cout << "Enter string using a,b,c,(,): ";
    string s;
    getline(cin, s);

    string cleaned;
    for (char c : s) if (c != ' ') cleaned += c;

    if (parseLL1(cleaned)) cout << "Valid string\n";
    else cout << "Invalid string\n";

    return 0;
}
