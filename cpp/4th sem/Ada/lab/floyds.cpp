#include<iostream>
using namespace std;
int min(int a,int b)
{
	return ((a<b)?a:b);
}
void floyds(int **cost,int n)
{
	for(int k=0;k<n;k++)
	{
		cout << "D(" << (k+1) << ")=" << endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
				cout << cost[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}
int main()
{
	int n=0;
	cout << endl <<"Enter the weights of the matrix:";
	cin >> n;
	cout << endl <<"Enter the weight matrix:" << endl;
	int **cost=new int*[n];
	for (int i = 0; i < n; i++)
	{
		cost[i]=new int[n];
	}
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
		
	}
	floyds(cost,n);
	for (int i = 0; i < n; i++)
	{
		delete[] cost[i];
	}
	
	delete[] cost;
}