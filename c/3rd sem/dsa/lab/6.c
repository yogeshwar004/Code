/*#include<stdio.h>
#include<stdlib.h>
#define max 5
char q[max];
int front=0,count=0,rear=-1;
void enqueue()
{
    char ele;
    if(count==max)
        printf("\nError: Stack OVerflow");
    else
    {
        printf("\nEnter the element to be inserted:");
        scanf("%c",&ele);
        rear=(rear+1)%max;
        q[rear]=ele;
        count++;
        printf("%s",q[rear]);
    }
}
void dequeue()
{
    if(count==0)
        printf("\nQueue Underflow");
    else
    {
        printf("\nDeleted element is %s",q[front]);
        front=(front+1)%max;
        count--;
    }
}
int main()
{
    enqueue();
    enqueue();
    dequeue();
}*/
#include<stdio.h>
#include<stdlib.h>