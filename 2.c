/*
 * Finite Automata String Validator
 * 
 * This program validates strings against rules defined by a finite automata.
 * 
 * Input Format:
 * - Number of input symbols
 * - Input symbols (space-separated)
 * - Number of states
 * - Initial/start state
 * - Number of accepting states
 * - Accepting states (space-separated)
 * - Transition table entries (format: "from_state to symbol -> to_state")
 * - Input string to validate
 * 
 * Output:
 * - "Valid string" if the string is accepted by the automata
 * - "Invalid string" otherwise
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 26
#define MAX_STRING_LENGTH 1000

// Structure to represent a Finite Automata
typedef struct {
    int numStates;              // Total number of states
    int numSymbols;             // Number of input symbols
    char symbols[MAX_SYMBOLS];  // Array of input symbols
    int startState;             // Starting state
    int numAcceptStates;        // Number of accepting states
    int acceptStates[MAX_STATES]; // Array of accepting states
    int transitionTable[MAX_STATES][MAX_SYMBOLS]; // Transition function
} FiniteAutomata;

/**
 * Get the index of a symbol in the symbols array
 * Returns -1 if symbol is not found
 */
int getSymbolIndex(FiniteAutomata *fa, char symbol) {
    for (int i = 0; i < fa->numSymbols; i++) {
        if (fa->symbols[i] == symbol) {
            return i;
        }
    }
    return -1;
}

/**
 * Check if a given state is an accepting state
 */
bool isAcceptState(FiniteAutomata *fa, int state) {
    for (int i = 0; i < fa->numAcceptStates; i++) {
        if (fa->acceptStates[i] == state) {
            return true;
        }
    }
    return false;
}

/**
 * Validate a string using the finite automata
 * Process each character and follow transitions
 * Return true if the final state is an accepting state
 */
bool validateString(FiniteAutomata *fa, char *inputString) {
    int currentState = fa->startState;
    int len = strlen(inputString);
    
    // Process each character in the input string
    for (int i = 0; i < len; i++) {
        char currentChar = inputString[i];
        int symbolIndex = getSymbolIndex(fa, currentChar);
        
        // If symbol is not in the alphabet, reject the string
        if (symbolIndex == -1) {
            return false;
        }
        
        // Get the next state from the transition table
        int nextState = fa->transitionTable[currentState][symbolIndex];
        
        // If no valid transition exists, reject the string
        if (nextState == -1) {
            return false;
        }
        
        currentState = nextState;
    }
    
    // Accept if final state is an accepting state
    return isAcceptState(fa, currentState);
}

int main() {
    FiniteAutomata fa;
    
    // Initialize transition table with -1 (representing no transition)
    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < MAX_SYMBOLS; j++) {
            fa.transitionTable[i][j] = -1;
        }
    }
    
    // Input: Number of symbols in the alphabet
    printf("Number of input symbols : ");
    scanf("%d", &fa.numSymbols);
    
    // Input: The symbols themselves
    printf("Input symbols : ");
    for (int i = 0; i < fa.numSymbols; i++) {
        scanf(" %c", &fa.symbols[i]);
    }
    
    // Input: Total number of states
    printf("Enter number of states : ");
    scanf("%d", &fa.numStates);
    
    // Input: The starting/initial state
    printf("Initial state : ");
    scanf("%d", &fa.startState);
    
    // Input: Number of accepting/final states
    printf("Number of accepting states : ");
    scanf("%d", &fa.numAcceptStates);
    
    // Input: The accepting states
    printf("Accepting states : ");
    for (int i = 0; i < fa.numAcceptStates; i++) {
        scanf("%d", &fa.acceptStates[i]);
    }
    
    // Input: Transition table
    printf("Transition table :\n");
    
    // Read all transitions (state x symbol combinations)
    int totalTransitions = fa.numStates * fa.numSymbols;
    
    for (int i = 0; i < totalTransitions; i++) {
        int fromState, toState;
        char symbol;
        
        // Format: "1 to a -> 2"
        scanf("%d to %c -> %d", &fromState, &symbol, &toState);
        
        // Store the transition in the table
        int symbolIndex = getSymbolIndex(&fa, symbol);
        if (symbolIndex != -1) {
            fa.transitionTable[fromState][symbolIndex] = toState;
        }
    }
    
    // Input: String to be validated
    char inputString[MAX_STRING_LENGTH];
    printf("\nInput string : ");
    scanf("%s", inputString);
    
    // Validate the string and display result
    if (validateString(&fa, inputString)) {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }
    
    return 0;
}
