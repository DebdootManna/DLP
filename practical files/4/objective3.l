%{
#include <stdio.h>
int char_count = 0;
int word_count = 0;
int line_count = 0;
%}

%%
\n              { char_count++; line_count++; }
[ \t]+          { char_count += yyleng; }
[^ \t\n]+       { word_count++; char_count += yyleng; }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }
    
    yyin = file;
    yylex();
    fclose(file);
    
    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Line : %d\n", line_count);
    
    return 0;
}
