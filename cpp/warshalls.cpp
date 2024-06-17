#include<stdio.h>
void warshalls(int r[][10],int n)
{ int i,j,k;
	for(k=0;k<n;k++)
	{ 
		printf("\n r(%d)=\n",(k+1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				r[i][j]=r[i][j]||(r[i][k]&&r[k][j]);
				printf("%d\t",r[i][j]);
			}
			printf("\n");
		}
	}
}
int main()
{
	int i,j,n,r[10][10];
	printf("\n enter the size of adjacency matrix:");
	scanf("%d",&n);
	printf("\n enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&r[i][j]);
		}
	}
	warshalls(r,n);
}
