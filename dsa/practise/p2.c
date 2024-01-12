#include<stdio.h>
void main()
{
    /*float n=10.0;
    void *ptr=&n;
    printf("Value of %d\n",*(int*)ptr);*/
    int *ptr,a[5],i;
    ptr=a;
    printf("Enter array Elements:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",ptr+i);
        /* code */
    }
    ptr=a;
    printf("Array:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t",*(ptr+i));
        /* code */
    }
}