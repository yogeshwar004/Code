#include<stdio.h>
void main()
{
	char n[30];
	int units,bill;
	printf("Enter the name of the user:");
	scanf("%c",n);
	printf("Enter the user consumed:");
	scanf("%d",&units);
	if(units<200)
	{
		bill=units*0.80+100;
	}
	if(bill>400)
	{
		bill=bill*0.15+bill;
	}
	else if(units>200&&units<300)
	{
		bill=200*0.80+(units-200)*0.90+100;
	}
	else
	{
		bill=200*0.80+100*0.90+(units-300)*1.00+100;
	}
	printf("%s has to pay %d",n,bill);
}
