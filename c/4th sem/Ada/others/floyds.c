#include<stdio.h>
#include<stdlib.h>
int minimum(int a,int b)
{
    return((a<b)?a:b);
}
void floyds(int n,int **cost)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        printf("D(%d)",k+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cost[i][j]=minimum(cost[i][j],cost[i][k]+cost[k][j]);
                printf("%d\t",cost[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int n,i,j;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    int **cost=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        cost[i]=(int*)malloc(n*sizeof(int)); 
    }
    printf("\nEnter the cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    floyds(n,cost);
}