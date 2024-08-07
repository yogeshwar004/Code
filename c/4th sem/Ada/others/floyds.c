#include<stdio.h>
#include<stdlib.h>
int minimum(int a,int b)
{
    return((a<b)?a:b);
}
void floyds(int n,int **R)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        printf("\nR(%d)=\n",k+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                R[i][j]=minimum(R[i][j],R[i][k]+R[k][j]);
                printf("%d\t",R[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int n,i,j;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    int **R=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        R[i]=(int*)malloc(n*sizeof(int)); 
    }
    printf("\nEnter the R matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
    floyds(n,R);
}