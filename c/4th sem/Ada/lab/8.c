#include<stdio.h>
int x[10],w[10],d;
static int count=0;
void sum_of_subsets(int s,int k,int rem)
{
    int i;
    x[k]=1;
    if(s+w[k]==d)
    {
        printf("\nSubset=%d\n",++count);
        for(i=0;i<=k;i++)
        {
            if(x[i]==1)
            {
                printf("%d\t",w[i]);
            }
        }
        printf("\n");
    }
    else if(s+w[k]<d)
    {
        sum_of_subsets(s+w[k],k+1,rem-w[k]);
    }
    if((s+rem-w[k]>=d)&&(s+w[k+1])<=d)
    {
        x[k]=0;
        sum_of_subsets(s,k+1,rem-w[k]);
    }
}
int main()
{
    int sum=0,n,i;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements in increasing order:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum=sum+w[i];
    }
    printf("\nEnter the d:");
    scanf("%d",&d);
    if((sum<d)||(d<w[0]))
        printf("\nNo subset possible");
    else
    {
        sum_of_subsets(0,0,sum);
        if(count==0)
            printf("\nNo subset possible");
    }
}