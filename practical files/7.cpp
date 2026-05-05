#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

map<string, vector<vector<string>>> grammar;
map<string, set<string>> firstSet, followSet;
set<string> nonTerminals = {"S", "A", "B", "C", "D"};

bool isNonTerminal(const string& s) {
    return nonTerminals.count(s) > 0;
}

set<string> firstOfSequence(const vector<string>& seq) {
    set<string> result;
    bool allEps = true;

    for (const string& symbol : seq) {
        if (!isNonTerminal(symbol)) {
            result.insert(symbol);
            allEps = false;
            break;
        }

        for (const string& x : firstSet[symbol]) if (x != "eps") result.insert(x);

        if (!firstSet[symbol].count("eps")) {
            allEps = false;
            break;
        }
    }

    if (allEps) result.insert("eps");
    return result;
}

void computeFirst() {
    bool changed = true;
    while (changed) {
        changed = false;
        for (const string& nt : nonTerminals) {
            for (const auto& prod : grammar[nt]) {
                set<string> temp = firstOfSequence(prod);
                for (const string& x : temp) {
                    if (!firstSet[nt].count(x)) {
                        firstSet[nt].insert(x);
                        changed = true;
                    }
                }
            }
        }
    }
}

void computeFollow() {
    followSet["S"].insert("$");

    bool changed = true;
    while (changed) {
        changed = false;

        for (const string& A : nonTerminals) {
            for (const auto& prod : grammar[A]) {
                for (int i = 0; i < (int)prod.size(); i++) {
                    string B = prod[i];
                    if (!isNonTerminal(B)) continue;

                    vector<string> beta(prod.begin() + i + 1, prod.end());
                    set<string> firstBeta = beta.empty() ? set<string>{"eps"} : firstOfSequence(beta);

                    for (const string& x : firstBeta) {
                        if (x != "eps" && !followSet[B].count(x)) {
                            followSet[B].insert(x);
                            changed = true;
                        }
                    }

                    if (firstBeta.count("eps")) {
                        for (const string& x : followSet[A]) {
                            if (!followSet[B].count(x)) {
                                followSet[B].insert(x);
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void printSet(const string& name, const string& nt, const set<string>& s) {
    cout << name << "(" << nt << ") = { ";
    bool first = true;
    for (const string& x : s) {
        if (!first) cout << ", ";
        cout << (x == "eps" ? "e" : x);
        first = false;
    }
    cout << " }\n";
}

int main() {
    grammar["S"] = {{"A", "B", "C"}, {"D"}};
    grammar["A"] = {{"a"}, {"eps"}};
    grammar["B"] = {{"b"}, {"eps"}};
    grammar["C"] = {{"(", "S", ")"}, {"c"}};
    grammar["D"] = {{"A", "C"}};

    computeFirst();
    computeFollow();

    cout << "=== FIRST Sets ===\n";
    for (string nt : {"S", "A", "B", "C", "D"}) printSet("First", nt, firstSet[nt]);

    cout << "\n=== FOLLOW Sets ===\n";
    for (string nt : {"S", "A", "B", "C", "D"}) printSet("Follow", nt, followSet[nt]);

    return 0;
}
