%{
#include <stdio.h>
%}

%%
[Cc][Hh][Aa][Rr][Uu][Ss][Aa][Tt]    { printf("university"); }
.                                     { printf("%c", yytext[0]); }
\n                                    { printf("\n"); return 0; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text containing 'charusat':\n");
    yylex();
    return 0;
}
