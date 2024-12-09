#include "stdio.h"
#define size 10
int main()
{
	int a[size],i;
	printf("enter the string in only 0's and 1's\n");
	printf("enter the data:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<size-2;i++)
	{
		if(a[i]==1 && a[i+1]==0 && a[i+2]==1)
		{
			printf("it contains 101 substring");
			
		}
		else
		{
			printf("not  contains");
		}
	}
	return 0;
}
