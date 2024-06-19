/*#include<stdio.h>
#include<stdlib.h>
void greedy_knapsack(int n,int m,float p[],float w[])
{
    float profit=0,max,x;
    int i,j,k,count;
    for(count=0;count<n;count++)
    {
        max=0;
        for(i=0;i<n;i++)
        {
            if(p[i]/w[i]>max)
            {
                k=i;
                max=p[i]/w[i];
            }
        }
        if(w[k]<=m)
        {
            printf("\nItem %d with fraction 1 is selected",k);
            profit=profit+p[k];
            m=m-w[k];
            p[k]=0;
        }
        else
            break;
    }
    printf("\nDiscrete knapsack profit=%f\n",profit);
    x=m/w[k];
    printf("\nItems %d with fraction %f",k,x);
    profit+=p[k]*x;
    printf("\nContinuous knapsack profit=%f\n",profit);
}
int main()
{
    printf("\nEnter the number of items:");
    int n;
    scanf("%d",&n);
    printf("\nEnter the knapsack weight:");
    int m;
    scanf("%d",&m);
    float *p=(float*)malloc(n*sizeof(float));
    float *q=(float*)malloc(n*sizeof(float));
    printf("\nEnter the Weights:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    printf("\nEnter the Profits:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    greedy_knapsack(n,m,p,q);
    free(p);
    free(q);
}*/
#include<stdio.h>
#include<stdlib.h>
void greedy_knapsack(int n,int m,float p[],float w[])
{
    float profit=0,max,x;
    int k;
    for(int count=0;count<n;count++)
    {
        max=0;
        for(int i=0;i<n;i++)
        {
            if(p[i]/w[i]>max)
            {
                k=i;
                max=p[i]/w[i];
            }
        }
        if(w[k]<=m)
        {
            printf("\nItem %d with fraction 1 is selected",k);
            profit+=p[k];
            m=m-w[k];
            p[k]=0;
        }
        else
            break;
    }
    printf("\nDiscrete knapsack profit=%f\n",profit);
    x=m/w[k];
    printf("\nItems %d with fraction %f",k,x);
    profit+=p[k]*x;
    printf("\nContinuous knapsack profit=%f\n",profit);
}
int main()
{
    printf("\nEnter the number of items:");
    int n;
    scanf("%d",&n);
    printf("\nEnter the knapsack weight:");
    int m;
    scanf("%d",&m);
    float *p=(float*)malloc(n*sizeof(float));
    float *w=(float*)malloc(n*sizeof(float));
    printf("\nEnter the Weights:");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&w[i]);
    }
    printf("\nEnter the Profits:");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&p[i]);
    }
    //float p[7]={10,5,15,7,6,18,3};float q[7]={2,3,5,7,1,4,1};
    greedy_knapsack(n,m,p,w);
    free(p);
    free(w);
}