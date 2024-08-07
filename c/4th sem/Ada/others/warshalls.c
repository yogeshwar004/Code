#include<stdio.h>
#include<stdlib.h>
void warshalls(int n,int **D)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        printf("\n\nD(%d)=\n",k+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                D[i][j]=D[i][j]||(D[i][k]&&D[k][j]);
                printf("%d \t",D[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int n,i,j;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the D matrix:\n");
    int **D=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        D[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&D[i][j]);
        }
    }
    warshalls(n,D);
}