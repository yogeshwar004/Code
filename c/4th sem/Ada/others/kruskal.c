#include<stdio.h>
#include<stdlib.h>
void kruskals(int n,int **cost)
{
    int i,par[n],ec=0,min=0,j,a,b,u,v,totalcost;
    for(i=0;i<n;i++)
        par[i]=-1;
    while(ec<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(min>cost[i][j])
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        while(par[u]!=-1)
            u=par[u];
        while(par[v]!=-1)
            v=par[v];
        if(u!=v)
        {
            printf("\nEdge from vertex %d to %d is %d",a,b,min);
            ec++;
            par[b]=a;
            totalcost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMincost=%d\n",totalcost);
}
int main()
{
    int n,i,j;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    int **cost=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        cost[i]=(int*)malloc(n*sizeof(int));
    printf("\nEnter the cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    kruskals(n,cost);
}