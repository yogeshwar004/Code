#include<stdio.h>
void kruskals(int n,int cost[][10])
{
    int i,par[n],ec=0,min,j,a,b,u,v,mincost=0;
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
            par[b]=a;
            ec++;
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMincost=%d\n",mincost);
}
int main()
{
    int n,i,j,cost[10][10];
    printf("\nEnter the  number of ver0tices:");
    scanf("%d",&n);
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