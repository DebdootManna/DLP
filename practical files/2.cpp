#include <iostream>
#include <vector>
#include <string>

using namespace std;

int symbolIndex(const vector<char>& symbols, char ch) {
    for (int i = 0; i < (int)symbols.size(); i++) {
        if (symbols[i] == ch) return i;
    }
    return -1;
}

bool isAcceptState(const vector<int>& acceptStates, int state) {
    for (int s : acceptStates) {
        if (s == state) return true;
    }
    return false;
}

int main() {
    int numSymbols;
    cout << "Number of input symbols : ";
    cin >> numSymbols;

    vector<char> symbols(numSymbols);
    cout << "Input symbols : ";
    for (int i = 0; i < numSymbols; i++) cin >> symbols[i];

    int numStates;
    cout << "Enter number of states : ";
    cin >> numStates;

    int startState;
    cout << "Initial state : ";
    cin >> startState;

    int numAccept;
    cout << "Number of accepting states : ";
    cin >> numAccept;

    vector<int> acceptStates(numAccept);
    cout << "Accepting states : ";
    for (int i = 0; i < numAccept; i++) cin >> acceptStates[i];

    vector<vector<int>> transition(numStates + 1, vector<int>(numSymbols, -1));
    cout << "Transition table :\n";
    for (int i = 0; i < numStates * numSymbols; i++) {
        int fromState, toState;
        char toWord[3], arrow[3], sym;
        cin >> fromState >> toWord >> sym >> arrow >> toState;
        int idx = symbolIndex(symbols, sym);
        if (idx != -1 && fromState >= 0 && fromState <= numStates) {
            transition[fromState][idx] = toState;
        }
    }

    string input;
    cout << "\nInput string : ";
    cin >> input;

    int current = startState;
    bool valid = true;

    for (char ch : input) {
        int idx = symbolIndex(symbols, ch);
        if (idx == -1 || current < 0 || current > numStates) {
            valid = false;
            break;
        }
        int next = transition[current][idx];
        if (next == -1) {
            valid = false;
            break;
        }
        current = next;
    }

    if (valid && isAcceptState(acceptStates, current)) cout << "Valid string\n";
    else cout << "Invalid string\n";

    return 0;
}
