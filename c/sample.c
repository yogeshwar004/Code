#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Enter the value of a and b:");
	scanf("%d%d",&a,&b);
	c=(a<b)?a:b;
	printf("The smaller number is:%d",c);
}
