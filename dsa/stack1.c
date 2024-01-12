#include<stdio.h>
#include<stdlib.h>
int *stack,max,top=-1;
void push(int ele)
{
    if(top==max-1)
        printf("Stack Overflow");
    else
        stack[++top]=ele;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Overflow");
        return -1;
    }
    else
        return(stack[top--]);
}
void display()
{
    int i;
    if(top==-1)
        printf("Stack is empty");
    else
    {
        printf("Stack elements are:\n");
        for
    }
}