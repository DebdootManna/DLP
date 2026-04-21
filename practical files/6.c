#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Grammar:
// S  -> ( L ) | a
// L  -> S L'
// L' -> , S L' | epsilon

const char *input;
int pos;
int error;

void parse_S();
void parse_L();
void parse_Lprime();

char current() {
    return input[pos];
}

void consume(char expected) {
    if (input[pos] == expected) {
        pos++;
    } else {
        error = 1;
    }
}

// S -> ( L ) | a
void parse_S() {
    if (error) return;
    if (current() == '(') {
        consume('(');
        parse_L();
        if (!error) consume(')');
    } else if (current() == 'a') {
        consume('a');
    } else {
        error = 1;
    }
}

// L -> S L'
void parse_L() {
    if (error) return;
    parse_S();
    parse_Lprime();
}

// L' -> , S L' | epsilon
void parse_Lprime() {
    if (error) return;
    if (current() == ',') {
        consume(',');
        parse_S();
        parse_Lprime();
    }
    // else epsilon - do nothing
}

int main() {
    char buf[1000];
    printf("Enter string: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        printf("Invalid string\n");
        return 0;
    }
    // Remove newline
    int len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') buf[--len] = '\0';

    // Remove spaces
    char cleaned[1000];
    int ci = 0;
    for (int i = 0; i < len; i++) {
        if (buf[i] != ' ') cleaned[ci++] = buf[i];
    }
    cleaned[ci] = '\0';

    input = cleaned;
    pos = 0;
    error = 0;

    parse_S();

    if (!error && input[pos] == '\0') {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }

    return 0;
}
