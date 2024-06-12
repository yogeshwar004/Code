#include<stdio.h>
int indegree[10],cost[10][10],n;
void calculate()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        indegree[i]=0;
        for(j=0;j<n;j++)
            indegree[i]=indegree[i]+cost[j][i];
    }
}
void sourceremoval()
{
    int removed[10]={0},count,i,j,k;
    printf("\nTopological Order \n");
    for(count=0;count<n;count++)
    {
        calculate();
        for(i=0;i<n;i++)
        {
            if(removed[i]==0&&indegree[i]==0)
                break;
        }
        if(i==n)
        {
            printf("\nGraph is Cyclic so no solution");
            return;
        }
        printf("%d\t",i);
        removed[i]=1;
        for(k=0;k<n;k++)
            cost[i][k]=0;   
    }    
}
int main()
{
    printf("\nEnter the number of Vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    sourceremoval();
}