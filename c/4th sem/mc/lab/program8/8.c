#include<stdio.h>
#include<lpc214x.h>
int main()
{
    unsigned int i=0;
    unsigned char num=5;
    unsigned long fact=1;
    for(i=1;i<=num;i++)
    {
        fact*=i;
    }
    PINSEL0=fact;
    return 0;
}