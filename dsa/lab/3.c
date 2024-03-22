#include<stdio.h>
#include<stdlib.h>
int *stack,max,top=-1;
void push(int ele)
{
    if(top==max-1)
        printf("\nStack Overflow");
    else
        stack[++top]=ele;
}
int pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
        return(stack[top--]);
}
void display()
{
    if(top==-1)
        printf("\nStack is empty");
    else
    {
        printf("\nStack elements are\n");
        for(int i=top;i>=0;i--)
            printf("%d\t",stack[i]);
        printf("\n");
    }
}
void palindrome()
{
    int num,rem,ncopy;
    printf("\nEnter the value of num:");
    scanf("%d",&num);
    top=-1;
    ncopy=num;
    while(num!=0)
    {
        rem=num%10;
        push(rem);
        num=num/10;
    }
    while(ncopy!=0)
    {
        rem=ncopy%10;
        if(rem!=pop())
        {
            printf("\nGiven number is not a palindrome");
            top=-1;
            return;
        }
        ncopy=ncopy/10;
    }
    printf("\nIt is a palindrome");
}
int main()
{
    int choice,ele;
    printf("\nEnter the size of the stack:");
    scanf("%d",&max);
    stack=(int*)malloc(max*sizeof(int));
    while(1)
    {
        printf("\nEnter your choice");
        printf("\n1 for push\n2 for pop\n3 for display\n4 for palindrome\n5 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be pushed:");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                ele=pop();
                if(ele!=1)
                    printf("\nDeleted Element is %d",ele);
                break;
            case 3:
                display();
                break;
            case 4:
                palindrome();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice");
                break;
        }
    }
}
/*
int *stack,max=5,top=-1;
void palindrome()
{
    int num,rem,rev,ncopy;
    printf("\nEnter the value of num:");
    num=1221;
    ncopy=num;
    while(num!=0)
    {
        rem=num%10;
        push(rem);
        num=num/10;
    }
    while(ncopy!=0)
    {
        rem=ncopy%10;
        if(rem!=pop())
        {
            printf("\nGiven number is not a palindrome");
            top=-1;
            return;
        }
        ncopy=ncopy/10;
    }
    printf("\nIt is a palinndrome");
}
void push(int ele)
{
    if(top==max-1)
        printf("\nStack Overflow");
    else
        stack[++top]=ele;
}
int pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        return(stack[top--]);
    }
}
int main() {
  stack=(int*)malloc(max*sizeof(int));
palindrome();
}
*/