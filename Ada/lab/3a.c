#include<stdio.h>
int min(int a,int b)
{
    return((a<b)?a:b);
}
void floyds(int D[][10],int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        printf("\nD(%d)\n",(k+1));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
                printf("%d\t",D[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int n,i,j,D[10][10];
    printf("\nEnter the size of Weight Matrix:");
    scanf("%d",&n);
    printf("\nEnter the Weight Matrix:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&D[i][j]);
        }
    }
    floyds(D,n);
}