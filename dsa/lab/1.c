#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;
struct calender
{
    char *name,*description;
    int day; 
};
typedef struct calender cal;
cal* create()
{
    return((cal*)malloc(7*sizeof(cal)));
}
void read(cal *d)
{
    int flag;
    for(i=0;i<7;i++)
    {
        d[i].day=-1;
        d[i].name=NULL;
        d[i].description=NULL;
    }
    do
    {
        printf("\nEnter Day Number:");
        scanf("%d",&i);
        if(i<0||i>6)
            printf("\nInvalid Day Number");
        else
        {
            printf("\nEnter Day Name, Day Description:");
            char temp[50];
            d[i].day=i;
            scanf("%s",temp);
            d[i].name=temp;
            scanf("%s",temp);
            d[i].description=temp;
        }
        printf("\nEnter 1 for more activities else 0:");
        scanf("%d",&flag);
    }while(flag!=0);
}
void display(cal *d)
{
    printf("\nDay Name\tDay Number\tDay Description");
    for(i=0;i<7;i++)
    {
        if(d[i].day!=-1)
            printf("\n%s\t\t%d\t\t%s",d[i].name,d[i].day,d[i].description);
    }          
}
void deallocate(cal *d)
{
    for(i=0;i<6;i++)
    {
        free(d[i].name);
        free(d[i].description);
    }
    free(d);
}
int main()
{
    cal *d=create();
    read(d);
    display(d);
    deallocate(d);
    return 0;
}