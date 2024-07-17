#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static int count=0;
void Merge(int b[],int c[],int a[],int p,int q)
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        count++;
        if(b[i]<=c[j])
            a[k++]=b[i++];
        else
            a[k++]=c[j++];
    }
    while(i<p)
        a[k++]=b[i++];
    while(j<q)
        a[k++]=c[j++];
}
void MergeSort(int a[],float n)
{
    int *b,*c,i=0,j=0;
    if(n>1)
    {
        int p=floor(n/2);
        int q=ceil(n/2);
        b=(int*)malloc(p*sizeof(int));
        c=(int*)malloc(q*sizeof(int));
        for(int i=0;i<p;i++)
            b[i]=a[i];
        for(int i=p;i<n;i++)
            c[j++]=a[i];
        MergeSort(b,p);
        MergeSort(c,q);
        Merge(b,c,a,p,q);
    }
}
int main()
{
    int n;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%1001;
        printf("\n%d",a[i]);
    }
    MergeSort(a,n);
    printf("\nAfter Sorting Are");
    for(int i=0;i<n;i++)
        printf("\n%d",a[i]);
    printf("\nBasic Operation Count=%d",count);
    free(a);
}