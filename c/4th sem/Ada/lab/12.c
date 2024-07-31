#include<stdio.h>
#include<math.h>
int place(int x[],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if((x[i]==x[k])||(abs(x[i]-x[k])==abs(i-k)))
            return 0;
    }
    return 1;
}
int nQueens(int n)
{
    int x[10],k,count=0,i,j;
    k=1;
    x[k]=0;
    while (k!=0)
    {
        x[k]++;
        while (x[k]<=n&&place(x,k)==0)
        {
            x[k]++;
        }
        if(x[k]<=n)
        {
            if(k==n)
            {
                printf("\nSolution=%d\n",++count);
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        printf("%c ",((x[i]==j)?'Q':'X'));
                    }
                    printf("\n");
                }
            }
            else
            {
                k++;
                x[k]=0;
            }
        }
        else
        {
            k--;
        }
    }
    return count;
}
int main()
{
    int n,res;
    printf("\nEnter the number of chessboards:");
    scanf("%d",&n);
    res=nQueens(n);
    if(res==0)
        printf("\nNo solution");
    else
    {
        printf("\nNumber of solutions=%d\n",res);
    }
}