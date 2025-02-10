#include<stdio.h>
int i=0,t=1;
char str[20];
void E();
void EPRIME();
void T();
void TPRIME();
void F();
void error();
void main()
{
printf("the given grammer is:\n");
printf("\nE -> TE'");
printf("\nE' -> +TE'/$");
printf("\nT -> FT'");
printf("\nT' -> *FT'/$");
printf("\nF -> (E)/a");
printf("\nenter the string to be parrsed:");
scanf("%s",str);
E();
if(t!=1||str[i]!='\0')
{
printf("\ngiven string is not accepted");
}
else
{
printf("the given string is accepted");
}

}

void E() {
T();
EPRIME(); }
void EPRIME() {
if(str[i]=='+') {
i++;
T();
EPRIME(); }
else {
return; }}
void T() {
F();
TPRIME(); }
void TPRIME() {
if(str[i]=='*') {
i++;
F();
TPRIME(); }
else return; }
void F() {
if(str[i]=='a') {
i++; }
else if(str[i]=='(') {
i++;

E();
if(str[i]==')')
{
i++;
}
}
else
{error();}
}
void error()
{
t=-1;
}
