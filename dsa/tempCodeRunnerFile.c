#include<stdio.h>
#include<stdlib.h>
typedef struct sparse
{
    int row;
    int col;
    int val;
}s[10];
void read()
{
    int m,n,ele,i,j,pos=1;
    struct sparse 