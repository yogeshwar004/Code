#include<stdio.h>
#include<lpc214x.h>
int main()
{
    unsigned long array[]={0x55555555,0x44444444,0x33333333,0x22222222,0x11111111};
    unsigned long temp,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    }
    while(1);
    return 0;
}