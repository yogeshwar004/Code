#include<stdio.h>
void main()
{
	char n[30];
	int units,bill;
	printf("\nEnter the name of the user and units consumed  by the user:\n");
	scanf("%c %d",n,units);
	if(units<200)
		bill=units*.80;
	else if(units>200 && units<300)
	    bill=200*0.80+(units-200)*0.90+100;
	else
	    bill=200*0.80+100*0.90+(units-300)*1.00+100;
	if(bill>400)
	    bill=bill*0.15+bill;
	printf("%s has to pay %d",n,bill);
}
