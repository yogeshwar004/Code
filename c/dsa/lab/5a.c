#include<stdio.h>
int count=0;
void towerofhonai(int n,char s,char t,char d)
{
    if(n==1)
    {
        printf("\nMove from %c to %c",s,d);
        count++;
    }
    else
    {
        towerofhonai(n-1,s,d,t);
        printf("\nMove from %c to %c",s,d);
        count++;
        towerofhonai(n-1,t,s,d);
    }
}
int main()
{
    int n;
    printf("\nEnter number of disks:");
    scanf("%d",&n);
    towerofhonai(n,'S','T','D');
    return 0;
}