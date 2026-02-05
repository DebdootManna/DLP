%{
#include <stdio.h>
#include <string.h>

int line_count = 1;
%}

/* Regular Expression Definitions */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
STRING      \"([^"\n]|\\\")*\"
CHAR        \'([^'\n]|\\'|\\n|\\t|\\0)\'

%%

    /* C Keywords */
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" {
    printf("Keyword: %s\n", yytext);
}

    /* Identifiers */
{IDENTIFIER} {
    printf("Identifier: %s\n", yytext);
}

    /* Constants */
{INTEGER} {
    printf("Constant: %s\n", yytext);
}

{FLOAT} {
    printf("Constant: %s\n", yytext);
}

    /* Strings */
{STRING} {
    printf("String: %s\n", yytext);
}

    /* Character Constants */
{CHAR} {
    printf("String: %s\n", yytext);
}

    /* Operators */
"++"|"--"|"+"|"-"|"*"|"/"|"%"|"="|"=="|"!="|"<"|">"|"<="|">="|"&&"|"||"|"!"|"&"|"|"|"^"|"~"|"<<"|">>"|"+="|"-="|"*="|"/="|"%="|"&="|"|="|"^="|"<<="|">>="|"->"|"."|"?"|":" {
    printf("Operator: %s\n", yytext);
}

    /* Punctuation */
"("|")"|"{"|"}"|"["|"]"|";"|","|"#" {
    printf("Punctuation: %s\n", yytext);
}

    /* Single-line Comments */
"//".*\n {
    line_count++;
}

    /* Multi-line Comments */
"/*"([^*]|\*+[^*/])*\*+"/" {
    int i;
    for(i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') line_count++;
    }
}

    /* White Spaces and Newlines */
[ \t]+ { /* Ignore whitespace */ }

\n {
    line_count++;
}

    /* Any other character (error) */
. {
    printf("Lexical Error: Unrecognized character '%s' at line %d\n", yytext, line_count);
}

%%

int yywrap() {
    return 1;
}

int main(int argc, char **argv) {
    FILE *fp;
    
    if(argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    fp = fopen(argv[1], "r");
    if(!fp) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    
    printf("TOKENS\n");
    yyin = fp;
    yylex();
    fclose(fp);
    
    return 0;
}
