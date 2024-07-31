#include<stdio.h>
#include<math.h>
void sieve(int n)
{
    int a[n+1],i,j;
    for(int p=2;p<=n;p++)
        a[p]=p;
    for(int p=2;p<=floor(sqrt(n));p++)
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
    i=0;
    printf("\nprime numbers are\n");
    for(int p=2;p<=n;p++)
    {
        if(a[p]!=0)
        {
            printf("%d\t",a[p]);
        }
    }
}
int main()
{
    printf("\nEnter the number of prime number to be generated:");
    int n;
    scanf("%d",&n);
    sieve(n);
}
