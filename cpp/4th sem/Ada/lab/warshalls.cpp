#include<iostream>
using namespace std;
int warshalls(int **d,int n)
{
	for (int k = 0; k < n; k++)
	{
		cout << "R(" << (k+1) << ")=" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				d[i][j]=d[i][j]|| (d[i][k] && d[k][j]);
				cout << d[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	return n;
}
int main()
{
	cout << "Enter the number of nodes:";
	int n;
	cin >> n;
	int **d=new int*[n];
	for (int i = 0; i < n; i++)
	{
		d[i]=new int[n];
	}
	cout << "Enter the Matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> d[i][j];
		}
	}
	int r=warshalls(d,n);
	for (int i = 0; i < n; i++)
	{
		delete[] d[i];
	}
	delete[] d;
	
	return 0;
}