#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[20],n;
void create()
{
    int i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void display()
{
    int i;
    printf("Array elements:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void insert()
{
    int pos,ele,i;
    printf("Enter the position and element:");
    scanf("%d%d",&pos,&ele);
    if(pos<1||pos>n)
    {
        printf("Invalid Input");
        exit(0);//or break
    }
    for(i=n-1;i>=pos-1;i--)
        a[i+1]=a[i];
    a[pos-1]=ele;
    n++;
    printf("Operation of insertion is Successful");
}
void deletion()
{
    int pos,i;
    printf("Enter the Position:\n");
    scanf("%d",&pos);
    if(pos<1||pos>n)
    {
        printf("Invalid Input");
        exit(0);// (or) return
    }
    for(i=pos;i<=n-1;i++)
        a[i-1]=a[i];
    n--;
    printf("Operation of deletion is Successful");

}
int main()
{
    int choice;
    while(1)
    {
        printf("\nEnter 1 for create\n2 for display\n3 for insert\n4 for delete\n5 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                deletion();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Input");
        }
    }
}