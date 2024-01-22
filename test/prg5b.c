#include<stdio.h>
int count=0;
void towerofhonai(int n,char s,char t,char d)
{
    if(n==1)
    {
        printf("Move from %c to %c\n",s,d);
        count++;
    }
    else
    {  
        towerofhonai(n-1,s,d,t);
        printf("Move from %c to %c\n",s,d);
        count++;
        towerofhonai(n-1,t,s,d);
    }
}
int main()
{
    int n;
    printf("Enter number of disks:\n");
    scanf("%d",&n);
    towerofhonai(n,'s','t','D');
    printf("Number of Honar: %d\n",count);
    return 0;
}