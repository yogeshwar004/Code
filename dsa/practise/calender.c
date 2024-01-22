#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calender
{
    char *name, *description;
    int day;
};
typedef struct calender cal;

cal* create()
{
    return ((cal*)malloc(7 * sizeof(cal)));
}

void read(cal *d)
{
    int i, flag;
    char temp[50];
    for (i = 0; i < 7; i++)
    {
        d[i].name = NULL;
        d[i].day = -1;
        d[i].description = NULL;
    }
    do
    {
        printf("Enter the Day Number:\n");
        scanf("%d", &i);
        if (i < 0 || i > 6)
            printf("Invalid Day Number\n");
        else
        {
            d[i].day = i;
            printf("Enter Day Name, Description:\n");
            scanf("%s", temp);
            d[i].name = strdup(temp);
            scanf("%s", temp);
            d[i].description = strdup(temp);
        }
        printf("Enter 1 for more activities else 0:");
        scanf("%d", &flag);
    } while (flag != 0);
}

void display(cal *d)
{
    int i;
    printf("Day Name\tDay Number\tDay Description\n");
    for (i = 0; i < 7; i++)
    {
        if (d[i].day != -1)
            printf("%s\t\t%d\t\t%s\n", d[i].name, d[i].day, d[i].description);
    }
}

void deallocate(cal *d)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        free(d[i].name);
        free(d[i].description);
    }
    free(d);
}

int main()
{
    cal *d = create();
    read(d);
    display(d);
    deallocate(d);
    return 0;
}
