#include<stdio.h>
#include<lpc214x.h>
int main()
{
    char value='k';
    if(value>='a'&&value<='z')
    {
        PINSEL0=value;
    }
    else if(value>='A'&&value<='Z')
    {
        PINSEL0=value;
    }
    else
    {
        PINSEL0=value;
    }
    return 0;
}