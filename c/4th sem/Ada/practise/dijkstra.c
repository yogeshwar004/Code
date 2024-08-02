#include<stdio.h>
void dijkstra(int s,int n,int cost[][10])
{
    int i,dist[n],visited[n],count,min,u,v;
    for(i=0;i<n;i++)
    {
        dist[i]=cost[s][i];
        visited[i]=0;
    }
    dist[s]=0;
    visited[s]=1;
    for(count=0;count<n-1;count++)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0&&dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        } 
    }
    visited[u]=1;
    for(v=0;v<n;v++)
    {
        if(visited[v]==0&&cost[u][v]!=999&&dist[v]>(dist[u]+cost[u][v]))
        {
            dist[v]=dist[u]+cost[u][v];
        }
    }
    for(v=0;v<n;v++)
    {
        printf("\nEdge from vertex %d to %d is %d",s,v,dist[v]);
    }
}
int main()
{
    int i,j,n,s,cost[10][10];
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }   
    }
    printf("\nEnter the starting nodes:");
    scanf("%d",&s);
    dijkstra(s,n,cost);
}