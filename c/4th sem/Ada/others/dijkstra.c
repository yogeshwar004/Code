#include<stdio.h>
#include<stdlib.h>
void dijkstra(int n,int s,int **cost)
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
            if(visited[i]==0&&min>dist[i])
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1;
        for(v=0;v<n;v++)
        {
            if(cost[u][v]!=999&&dist[v]>(dist[u]+cost[u][v])&&visited[v]==0)
            {
                dist[v]=dist[u]+cost[u][v];
            }
        }
    }
    printf("\nThe shortest path");
    for(i=0;i<n;i++)
    {
        printf("\n%d to %d is %d",s,i,dist[i]);
    }
}

int main()
{
    int n,s,i,j;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the starting nodes:");
    scanf("%d",&s);
    printf("\nEnter the cost matrix:\n");
    int **cost=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        cost[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    dijkstra(n,s,cost);
}