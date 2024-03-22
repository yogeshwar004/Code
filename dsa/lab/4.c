#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char symbol)
{
    stack[++top]=symbol;
}
char pop()
{
    return(stack[top--]);
}
int prec(char sym)
{
    switch(sym)
    {
        case '$':
        case '^':
            return 4;
        case '%':
        case '/':
        case '*':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
        case ')':
        case '#':
            return 1;
    }
}
void convertip(char *infix,char *postfix)
{
    char sym;
    int i,j=0;
    push('#');
    for(i=0;i<strlen(infix);i++)
    {
        sym=infix[i];
        switch(sym)
        {
            case '(':
                push(sym);
                break;
            case ')':
                while(stack[top]!='(')
                    postfix[j++]=pop();
                pop();
                break;
            case '$':
            case '^':
            case '%':
            case '/':
            case '*':
            case '+':
            case '-':
                while(prec(sym)<=prec(stack[top]))
                    postfix[j++]=pop();
                push(sym);
                break;
            default:
                postfix[j++]=sym;
                break;
        }
    }
    while(stack[top]!='#')
        postfix[j++]=pop();
    postfix[j++]='\0';
}
void main()
{
    char infix[30],postfix[30];
    printf("\nEnter the expression:");
    gets(infix);
    convertip(infix,postfix);
    printf("\nThe expression after evaluating from infix to postfix:%s",postfix);
}