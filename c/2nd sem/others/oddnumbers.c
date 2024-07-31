#include<stdio.h>
void main()
{
	int i,n,sum=0;
	printf("Enter the value of n:");
	scanf("%d",&n);
	for(i=0;i<=n;i=i+2)
	{
	sum=sum+i;
}
	printf("Result=",sum);
}
