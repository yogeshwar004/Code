#include<stdio.h>
void floyds(int n,int cost[][10])
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        printf("D(%d)",k+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                printf("%d\t",cost[i][j]);
            }
            printf("\n");
        }
    }
}
int min(int a,int b)
{
    return((a<b)?a:b);
}