#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    return ((a>b)?a:b);
}
void DPKnapsack(int n,int m,int p[],int w[])
{
    int v[n+1][m+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                v[i][j]=0;
            }
            else if(j<w[i])
            {
                v[i][j]=v[i-1][j];
            }
            else
            {
                v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
            }
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    printf("\nOptimal profit=%d\n",v[n][m]);
    while(m!=0)
    {
        if(v[n][m]!=v[n-1][m])
        {
            printf("%d\t",n);
            m=m-w[n];
        }
        n--;
    }
}
int main()
{
    int n,m,i;
    printf("\nEnter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the weights of %d items:\n",n);
    int *w=(int*)malloc(n*sizeof(int));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("\nEnter the profits of %d items:\n",n);
    int *p=(int*)malloc(n*sizeof(int));
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("\nEnter the Knapsack Weight:");
    scanf("%d",&m);
    DPKnapsack(n,m,p,w);
    free(p);
    free(w);
    return 0;
}