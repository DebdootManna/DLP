%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int has_lower = 0, has_upper = 0, has_digit = 0, has_special = 0;
char password[100];
int pwd_len = 0;
%}

%%
[a-z]       { password[pwd_len++] = yytext[0]; has_lower = 1; }
[A-Z]       { password[pwd_len++] = yytext[0]; has_upper = 1; }
[0-9]       { password[pwd_len++] = yytext[0]; has_digit = 1; }
[*,;#$@]    { password[pwd_len++] = yytext[0]; has_special = 1; }
\n          { password[pwd_len] = '\0'; return 0; }
.           { password[pwd_len++] = yytext[0]; }
%%

int yywrap() {
    return 1;
}

int main() {
    // printf("Enter password:\n");
    yylex();
    
    int valid = 1;
    
    // Check length (9 to 15 characters)
    if (pwd_len < 9 || pwd_len > 15) {
        valid = 0;
    }
    
    // Check minimum count for each category
    if (!has_lower || !has_upper || !has_digit || !has_special) {
        valid = 0;
    }
    
    if (valid) {
        printf("Valid password\n");
    } else {
        printf("Invalid password\n");
    }
    
    return 0;
}
