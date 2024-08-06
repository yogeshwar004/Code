#include<stdio.h>
#include<stdlib.h>
void prims(int n,int s,int **cost)
{
    int ecounter=0,min=0,i,j,a,b,mincost=0;
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
                    if(tvertex[j]==0&&min>cost[i][j])
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
        mincost+=min;
        ecounter++;
    }
    printf("\nMincost=%d\n",mincost);
}
int main()
{
    int n,i,j,s;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    int **cost=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        cost[i]=(int*)malloc(n*sizeof(int));
    }
   /*int** cost = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        cost[i] = (int*)malloc(n * sizeof(int));
    }*/
    printf("\nEnter the cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        scanf("%d",&cost[i][j]);
        }
    }
    printf("\nEnter the source nodes:");
    scanf("%d",&s);
    prims(n,s,cost);
}