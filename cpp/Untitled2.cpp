#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sieve(int n)
{
	int p,a[n+1],j,i;
	for(p=2;p<=n;p++)
	 {
	 a[p]=p;//ERROR
	for(p=0;p<=floor(sqrt(n));p++)
	{
	if(a[p]!=0) 
	{
		j=p*p;
		while(j<=n)
		{
			a[j]=0;
			j=j+p;
		}
	}
}
}
/*printf("prime no are");
i=0;
printf("prime numbers are\n");
for(p=2;p<=n;p++)
{
	if(a[p]!=0)
	{
		printf("%d",&a[p]);
	}
}}*///ERROR
int main()
{
	printf("enter the no of prime numbers to be generated");
	int n;
	scanf("%d",&n);
	sieve(n);
}


