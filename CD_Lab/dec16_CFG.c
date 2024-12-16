#include<stdio.h>
#include<conio.h>
#include<ctype.h>
struct str
{
	char st[2];
	char rule[20];
	
}g[15];

void main()
{
	int i,j,n;
//	clrscr();
	system("cls");
	printf("enter the number of production:");
	scanf("%d",&n);
	printf("enter the production:\n");
	for(i=0;i<n;i++)
	{
		printf("enter the non-ternimal:");
		scanf("%s",g[i].st);
		printf("enter the RHS production:");
		scanf("%s",g[i].rule);
		
	}
	printf("\nentered the production are:\n");
	for(i=0;i<n;i++)
	{
		printf("%c%c%c",g[i].st[0],'-','>');
		printf("%s\n",g[i].rule);
		printf("the starting symbols of production is:");
		printf("%c\n",g[i].st[0]);
	}
	printf("\nthe non-terminalsare:");
	for(i=0;i<n;i++)
	{
		printf("%c\n",g[i].st[0]);
	
	}
	printf("\nthe terminals are:");
	for(i=0;i<n;i++)
	{
		for(j=0;g[i].rule[j]!='\0';j++)
		{
			if(!isupper(g[i].rule[j])&&(g[i].rule[j]!='/'))
			{
				printf("\t%c",g[i].rule[j]);
			}
		}
	}
	getch();
}
