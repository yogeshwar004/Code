#include<stdio.h>
#include<stdlib.h>
#define max 5
int a[max],count=0;
void display()
{
    int i;
    printf("\nHash table contents ");
    printf("\nIndex\tData");
    for(i=0;i<max;i++)
        printf("\n%d\t%d",i,a[i]);
}
void linear_probe(int index,int num)
{
    int i;
    if(count==max)
    {
        printf("\nHash Table is full");
        return;
    }
    else if(a[index]==-1)
    {
        a[index]=num;
        count++;
    }
    else
    {
        printf("\nCollision detected");
        printf("\nCollision resolved through linear probe");
        for(i=index+1;i<max;i++)
        {
            if(a[i]==-1)
            {
                a[i]=num;
                count++;
                return;
            }
        }
        for(i=0;i<index;i++)
        {
            if(a[i]==-1)
            {
                a[i]=num;
                count++;
                return;
            }
        }
    }
}
int main()
{
    int num,index,input,i;
    for(i=0;i<max;i++)
        a[i]=-1;
    do
    {
        printf("\nEnter the number:");
        scanf("%d",&num);
        index=num%max;
        linear_probe(index,num);
        display();
        printf("\nEnter 1 to continue:");
        scanf("%d",&input);
    }while(input==1);
    return 0;
}