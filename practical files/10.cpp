#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <cctype>

// Recursive descent parser implementing the SDD grammar:
// L -> E n
// E -> E + T | E - T | T
// T -> T * F | T / F | F
// F -> G ^ F | G        (right-associative exponentiation)
// G -> ( E ) | digit/number

class Parser {
    std::string input;
    size_t pos;

    void skipSpaces() {
        while (pos < input.size() && input[pos] == ' ')
            pos++;
    }

    // G -> ( E ) | number
    double parseG() {
        skipSpaces();
        if (pos >= input.size())
            throw std::runtime_error("Invalid expression");

        if (input[pos] == '(') {
            pos++; // consume '('
            double val = parseE();
            skipSpaces();
            if (pos >= input.size() || input[pos] != ')')
                throw std::runtime_error("Invalid expression");
            pos++; // consume ')'
            return val;
        }

        // Parse number (integer or decimal)
        if (isdigit(input[pos]) || input[pos] == '.') {
            size_t start = pos;
            while (pos < input.size() && (isdigit(input[pos]) || input[pos] == '.'))
                pos++;
            std::string numStr = input.substr(start, pos - start);
            return std::stod(numStr);
        }

        throw std::runtime_error("Invalid expression");
    }

    // F -> G ^ F | G  (right-associative)
    double parseF() {
        double base = parseG();
        skipSpaces();
        if (pos < input.size() && input[pos] == '^') {
            pos++; // consume '^'
            double exp = parseF(); // right-recursive for right-associativity
            return std::pow(base, exp);
        }
        return base;
    }

    // T -> T * F | T / F | F  (left-associative, iterative)
    double parseT() {
        double val = parseF();
        skipSpaces();
        while (pos < input.size() && (input[pos] == '*' || input[pos] == '/')) {
            char op = input[pos++];
            double right = parseF();
            if (op == '*')
                val *= right;
            else {
                if (right == 0) throw std::runtime_error("Invalid expression");
                val /= right;
            }
            skipSpaces();
        }
        return val;
    }

    // E -> E + T | E - T | T  (left-associative, iterative)
    double parseE() {
        double val = parseT();
        skipSpaces();
        while (pos < input.size() && (input[pos] == '+' || input[pos] == '-')) {
            char op = input[pos++];
            double right = parseT();
            if (op == '+') val += right;
            else           val -= right;
            skipSpaces();
        }
        return val;
    }

public:
    double evaluate(const std::string& expr) {
        input = expr;
        pos = 0;
        double result = parseE();
        skipSpaces();
        if (pos != input.size())
            throw std::runtime_error("Invalid expression");
        return result;
    }
};

int main() {
    std::string expr;
    std::cout << "Enter arithmetic expression: ";
    std::getline(std::cin, expr);

    Parser parser;
    try {
        double result = parser.evaluate(expr);
        // Print as integer if result is whole number
        if (result == (long long)result)
            std::cout << (long long)result << std::endl;
        else
            std::cout << result << std::endl;
    } catch (const std::exception&) {
        std::cout << "Invalid expression" << std::endl;
    }

    return 0;
}
