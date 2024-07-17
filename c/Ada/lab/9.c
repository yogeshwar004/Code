#include<stdio.h>
#include<stdlib.h>
int count=0;
void SelectionSort(int a[],int n)
{
    int i,j,pos,temp;
    for(i=0;i<=n-2;i++)
    {
        pos=i;
        for(j=i+1;j<=n-1;j++)
        {
            count++;
            if(a[j]<a[pos])
                pos=j;
        }
        if(i!=pos)
        {
            temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
        }
    }
}
int main()
{
    int *a,n,i;
    printf("\nEnter the value of n\n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1001;
        printf("%d\t",a[i]);
    }
    SelectionSort(a,n);
    printf("\nSorted Elements are\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nBasic Operation Count=%d\n",count);
    free(a);
}