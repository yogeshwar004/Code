#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char sym)
{
    stack[++top]=sym;
}
char pop()
{
    return (stack[top--]);
}
int prec(char sym)
{
    switch(sym)
    {
        case '$':
        case '^':
            return 4;
        case '%':
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
        case ')':
            return 1;
    }
    return 0;
}
void convertip(char *infix,char *postfix)
{
    char symbol;
    int i,j=0;
    push('#');
    for (i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':
                push(symbol);
                break;
            case ')':
                while(stack[top]!='(')
                    postfix[j++]=pop();
                pop();
                break;
            case '$':
            case '^':
            case '%':
            case '*':
            case '/':
            case '+':
            case '-':
                while(prec(symbol)<=prec(stack[top]))
                    postfix[j++]=pop();
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
        }
    }
    while(stack[top]!='#')
        postfix[j++]=pop();
    postfix[j++]='\0';
}
int main()
{
    char infix[30],postfix[30];
    printf("Enter the exxpression:");
    gets(infix);
    convertip(infix,postfix);
    printf("The expression after evaluating from infix to postfix:%s",postfix);
    return 0;
}