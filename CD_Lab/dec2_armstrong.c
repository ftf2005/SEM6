#include "stdio.h"
#include "math.h"
int main()
{
	int n,r,z,x,y,sum=0,count=0;
	printf("enter the value for the number:");
	scanf("%d",&n);
	x=y=n;
	while(x!=0)
	{
		r=x%10;
		count++;
		x=x/10;
	}
	
	while(y!=0)
	{
		z=y%10;
		sum += pow(z, count);
		y=y/10;
	}
	if(sum==n)
	{
		printf("its a armstrong number");
	}
	else
	{
		printf("its not a armstrong number");
	}
//	printf("%d\n",sum);
//	printf("%d\n",count);
}
