// Declaration Section
%{
#include <stdio.h>
%}

// Rules Section
%%
[0-9]+            { printf("Integer\n"); }
[0-9]+\.[0-9]+    { printf("Float\n"); }
[^\n]+            { printf("Invalid\n"); }
\n                { /* Ignore newlines */ }

%%

// Auxiliary Functions
int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter String:\n");
    yylex();
    return 0;
}
