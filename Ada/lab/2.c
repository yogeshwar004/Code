#include<stdio.h>
int uniqueness(int  a[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[i]==a[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    printf("Enter the number of array elements:");
    int n,a[10];
    scanf("%d",&n);
    printf("\nEnter the array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=uniqueness(a,n);
    if(ans==1)
    {
        printf("\narray is unique");
    }
    else
        printf("\narray is not unique");
    return 0;
}