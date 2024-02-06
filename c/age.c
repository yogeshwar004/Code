#include<stdio.h>
void main()
{
	int age,cy,yob;
	printf("Enter the Current Year and Year of Birth:\n");
	scanf("%d%d",&cy,&yob);
	age=cy-yob;
	printf("The Age is:%d\n",age);
	if(age>18)
	printf("You can Vote\n");
	else
	printf("You can't Vote\n");
}
