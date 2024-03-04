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
    struct sparse b[];
    printf("\nEnter the order of matrix:");
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&ele);
            if(ele!=0)
            {
                s[pos].row=i;
                s[pos].col=j;
                s[pos].val=ele;
                pos++;
            }
        }
    }
    s[o].val=pos-1;
    s[0].row=m;
    s[0].col=n;
    print(s[]);
    transpose(s[],b[]);
    print(b[]);
}
void print(struct sparse a[])
{
    int i,j,pos=1;
    for(i=0;i<a[0].row;i++)
    {
        for(j=0;j<a[0].col;j++)
        {
            if(a[pos].row==i&&a[pos].col==j)
            {
                printf("\n%d",a[pos].val);
                pos++;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
    
}
void search(struct sparse a[])
{
    int key=0,i;
    printf("\nEnter key value:");
    scanf("%d",&key);
    for(i=1;i<=a[0].val;i++)
    {
        if(a[i].val==key)
        {
            printf("\n%d%d",a[i].row,a[i].col);
        }
    }
    printf("\nKey not found");
}
void transpose(struct sparse a[],struct sparse b[])
{
    int pos=1,i,j;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    for(i=0;i<a[0].col;i++)
    {
        for(j=1;j<=a[0].val;j++)
        {
            if(a[j].col==i)
            {
                b[pos].col=a[j].row;
                b[pos].row=a[j].col;
                b[pos].val=a[j].val;
                pos++;
            }
        }
    }
    printf("\nTranspose",print(b[]));
}
void main()
{
    read();
}