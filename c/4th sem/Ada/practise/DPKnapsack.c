#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    return((a>b)?a:b);
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
    printf("\nOptimal Profit=%d",v[n][m]);
    printf("\nItem Selected\n");
    while(m!=0)
    {
        if(v[n][m]!=v[n-1][m])
        {
            printf("%d\t",n);
            m-=w[n];
        }
        n--;
    }
}
int main()
{
    int n,m,i;
    printf("\nEnter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the knapsack capacity:");
    scanf("%d",&m);
    printf("\nEnter the weights of %d items:",n);
    int *w=(int*)malloc((n+1)*sizeof(int));
    w[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("\nEnter the profits of %d items:",n);
    int *p=(int*)malloc((n+1)*sizeof(int));
    p[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    DPKnapsack(n,m,p,w);
    free(p);
    free(w);
}