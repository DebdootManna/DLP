%{
#include <stdio.h>
%}

%%
[0-9]+      { printf("%s\n", yytext); }
.           { /* Ignore non-digit characters */ }
\n          { return 0; }
%%

int yywrap() {
    return 1;
}

int main() {
    // printf("Enter a string (mix of text and numbers):\n");
    yylex();
    return 0;
}
