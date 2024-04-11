#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a,b,res;
	char op;
	printf("\nEnter a simple arithmetic expression:\n");
	scanf("%d%c%d",&a,&op,&b);
	switch(op)
	{
		case '+':
			res=a+b;
			break;
		case '-':
			res=a-b;
			break;
		case '*':
			res=a*b;
			break;
		case '/':
			if(b!=0)
			   res=a/b;
			else
			   printf("Zero Error\n");
			   break;
		default:
			printf("Invalid Input\n");
			exit(0);
}
	printf("\n %d%c%d=%d",a,op,b,res);		

}
