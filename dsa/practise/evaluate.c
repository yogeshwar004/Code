#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max_size 20
int stack[max_size];
int top=-1;
void push(int operand)
{
    if(top==max_size-1)
    {
        printf("\nError: Stack Overflow\n");
        exit(1);
    }
    stack[++top]=operand;
}
int pop()
{
    if(top==-1)
    {
        printf("\nError: Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
float evaluate(char *postfix)
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
                        printf("Error: ZeroDivisionError");
                        exit(1);
                    }
                    break;
                case '%':
                    if(op2!=0)
                        push(op1%op2);
                    else
                    {
                        printf("Error: ZeroDivisionError");
                        exit(1);
                    }
                    break;
                case '^':
                    push(pow(op1,op2));
                    break;
                default:
                    printf("Error: Invalid operation\n");
                    exit(1);
            }
        }
    }
    return (float)pop();
}
int main()
{
    char postfix[30];
    printf("Enter Postfix Expression:");
    fgets(postfix,30,stdin);
    postfix[strcspn(postfix,"\n")]='\0';
    float result;
    result=evaluate(postfix);
    printf("Result=%f\n",result);
    return 0;
}
