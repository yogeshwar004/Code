#include<stdio.h>
#include<stdlib.h>
struct sll
{
    int sem;
    char usn[11],name[20],branch[20],phone[11];
    struct sll* next;
};
typedef struct sll node;
node* getnode