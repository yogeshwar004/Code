#include<stdio.h>
void main()
{
	int i,j,m,n,k,a[10][10],b[10][10],c[10][10];
	printf("Enter the number of rows and column:");
	scanf("%d%d",&m,&n);
	printf("The order of matrix is:%d X %d\n",m,n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter number of the matrix of row %d and column %d:\n",i,j);
			scanf("%d",&a[i][j]);
		}
    }
    for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter number of the matrix of row %d and column %d:\n",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	printf("The marix after multipilcation:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
		    printf("%d",&c[i][j]);
		}
	}
}  
	
