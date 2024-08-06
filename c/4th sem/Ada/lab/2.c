#include<stdio.h>
void prims(int n,int s,int cost[][10])
{
    int i,j,a,b,min,totalcost=0,ecounter=0;
    int tvertex[10]={0};
    tvertex[s]=1;
    while(ecounter<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(tvertex[i]==1)
            {
                for(j=0;j<n;j++)
                {
                    if(tvertex[j]==0&&cost[i][j]<min)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        printf("\nEdge from vertex %d to %d is %d",a,b,min);
        tvertex[b]=1;
        totalcost+=min;
        ecounter++;
    }
    printf("\nMincost=%d",totalcost);
}
int main()
{
    printf("\nEnter the number of nodes:");
    int n;
    scanf("%d",&n);
    int cost[10][10],s;
    printf("\nEnter the cost matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    printf("\nEnter the source or starting nodes:");
    scanf("%d",&s);
    prims(n,s,cost);
}