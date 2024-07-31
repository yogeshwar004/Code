#include<stdio.h>
void main()
{
	int i,j,n,temp,a[i];
	printf("Welcome to Bubble Sort\n");
	printf("Enter the size of the Array:\n");
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element of an array:",i+1);
		scanf("%d\n",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	for(i=0;i<n;i++)
	    for(j=0;j<n-i;j++)
	        if(a[j]>a[j+1])
	        {
	        	temp=a[i];
				a[i]=a[j+1];
				a[j+1]=temp;			
			}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
