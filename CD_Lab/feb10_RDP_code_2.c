#include <stdio.h>


int i = 0, t = 1;
char str[20];

void E();
void EPRIME();
void T();
void TPRIME();
void F();
void FPRIME();
void error();

int main()
{
    printf("The given grammar is:\n");
      printf("\nE -> E+T | T");
    printf("\nT -> TF | F");
    printf("\nF -> F* | a | b");  
    printf("\nEnter the string to be parsed: ");
    scanf("%s", str);

    E();

    if (t != 1 || str[i] != '\0') {
        printf("\nGiven string is not accepted\n");
    } else {
        printf("\nThe given string is accepted\n");
    }

    return 0;
}

void E()
{
    T();
    EPRIME();
}

void EPRIME()
{
    if (str[i] == '+') {
        i++;
        T();
        EPRIME();
    }
}

void T()
{
    F();
    TPRIME();
}

void TPRIME()
{
    if (str[i] == 'a' || str[i] == 'b' || str[i] == '(') {
        F();
        TPRIME();
    }
}

void F()
{
    if (str[i] == 'a' || str[i] == 'b') {
        i++;
        FPRIME();
    } else {
        error();
    }
}

void FPRIME()
{
    while (str[i] == '*') {
        i++;
    }
}

void error()
{
    t = -1;
}
