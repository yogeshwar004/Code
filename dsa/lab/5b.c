#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX_SIZE 20
int stack[MAX_SIZE];
int top=-1;
void push(int operand)
{
    if(top==MAX_SIZE-1)
    {
        printf("\nError: Stack Overflow");
        exit(1);
    }
    stack[++top]=operand;
}
int pop()
{
    if(top==-1)
    {
        printf("\nError: Stack Underflow");
        exit(1);
    }
    return(stack[top--]);
}
int evaluate(char postfix[])
{
    int i,operand,op1,op2;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            operand=postfix[i]-'0';
            push(operand);
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(postfix[i])
            {
                case '+':
                    push(op1+op2);
                    break;
                case '-':
                    push(op1-op2);
                    break;
                case '*':
                    push(op1*op2);
                    break;
                case '/':
                    if(op2!=0)
                        push(op1/op2);
                    else
                    {
                        printf("\nZeroDivisionError: Invalid Denominator");
                        exit(1);
                    }
                    break;
                case '%':
                    if(op2!=0)
                        push(op1%op2);
                    else
                    {
                        printf("\nZeroDivisionError: Invalid Denominnator");
                        exit(1);
                    }
                    break;
                case '^':
                    push(pow(op1,op2));
                    break;
                default:
                    printf("\nError: Invalid Operation");
                    exit(1);
            }
        }
    }
    return pop();
}
int main()
{
    char postfix[30];
    printf("\nEnter Postfix Expression:");
    gets(postfix);
    postfix[strcspn(postfix,"\n")]='\0';
    float result=evaluate(postfix);
    printf("\nResult=%f",result);
    return 0;
}