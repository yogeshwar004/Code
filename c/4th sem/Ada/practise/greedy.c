#include<stdio.h>
#include<stdlib.h>
void Greedy_Knapsack(int n,int m,float p[],float w[])
{
    float profit=0,max,x;
    int i,j,k,count=0;
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
            profit+=p[k];
            m=m-w[k];
            p[k]=0;
        }
        else
            break;
    }
    printf("\nDiscrete Fractional knapsack with profit %f",profit);
    x=m/w[k];
    printf("\nItems %d with fraction %f is selected",k,x);
    profit+=p[k]*x;
    printf("\nContinuous Fractional knapsack with profit %f",profit);

}
int main()
{
    int n,m,i;
    printf("\nEnter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the knapsack capacity:");
    scanf("%d",&m);
    printf("\nEnter the weights of %d items:",n);
    float *w=(float*)malloc(n*sizeof(float));
    for(i=0;i<n;i++)
    {
        scanf("%f",&w[i]);
    }
    printf("\nEnter the profits of %d items:",n);
    float *p=(float*)malloc(n*sizeof(float));
    for(i=0;i<n;i++)
    {
        scanf("%f",&p[i]);
    }
    Greedy_Knapsack(n,m,p,w);
    free(p);
    free(w);
}