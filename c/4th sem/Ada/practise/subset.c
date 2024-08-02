#include<stdio.h>
int w[10],x[10],d;
static int count=0;
void sum_of_subset(int s,int k,int rem)
{
    int i=0;
    x[k]=1;
    if(s+w[k]==d)
    {
        printf("\nSubset=%d\n",++count);
        for(i=0;i<=k;i++)
        {
            printf("%d\t",w[i]);
        }
        printf("\n");
    }
    else if(s+w[k]<d)
    {
        sum_of_subset(s+w[k],k+1,rem-w[k]);
    }
    if((s+rem-w[k]>=d)&&(s+w[k+1]<=d))
    {
        x[k]=0;
        sum_of_subset(s,k+1,rem-w[k]);
    }
}
int main()
{
    int n,i,sum;
    printf("\nEnter the number of items:");
    scanf("%d",&n);
    printf("\nEnter the elements in increasing order:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    printf("\nEnter the d:");
    scanf("%d",&d);
    if((w[0]>d)||(sum<d))
    {
        printf("\nNo Subset Possible");
    }
    else
    {
        sum_of_subset(0,0,sum);
        if(count==0)
        {
            printf("\nNo Subset Possible");
        }
    }
}