#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max_ 20
int q[max];
int rear=-1,front=0,count=0;
void enqueue()
{
    char ele;
    if(count==max)
        printf("Error: Queue Overflow\n");
    else
    {
        printf("Enterr the  element to be inserted:");
        scanf("%c",&ele);
        rear=(rear+1)%max;
        q[rear]=ele;
        count++;
    }
}
void dequeue()
{
    if(count==0)
    {
        printf("Queue Underflow\n");
    }
    else{
        printf("Deleeted element is %s\n",q[front]);
        front=(front+1)%max;
        count--;
    }
}
void display()
{
    int i,j;
    if(count==0){
        printf("Queue is empty");
    }
    else
    {
        i=front;
        for(j=0;j<count;j++)
        {
            printf("%s\n",q[i]);
            i=(i+1)%max;
        }
    }
}
int main()
{
    int choice,ele;
    while (1)
    {
        printf("\nEnter your choice\n");
        printf("\n1for\n")
        /* code */
    }
    
}
