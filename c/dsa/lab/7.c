#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int sem;
    char usn[11],name[20],branch[20],phone[11];
    struct SLL *next;
};
typedef struct SLL node;
node *start=NULL;
node* getnode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the student details, usn, name, branch, sem, phno:");
    scanf("%s",newnode->usn);
    scanf("%s",newnode->name);
    scanf("%s",newnode->branch);
    scanf("%d",&newnode->sem);
    scanf("%s",newnode->phone);
    newnode->next=NULL;
    return newnode;
}
void insertbegin()
{
    node *newnode=getnode();
    if(start==NULL)
    {
        start=newnode;
        return;
    }
    newnode->next=start;
    start=newnode;
}
void insertend()
{
    node *newnode=getnode(),*temp;
    if(start==NULL)
    {
        start=newnode;
        return;
    }
    temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
}
void deletebegin()
{
    node *temp=start;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    start=temp->next;
    printf("Deleted node is %s",temp->usn);
    free(temp);
}
void deleteend()
{
    node *temp,*prev;
    if(start==NULL)
    {
        printf("\nlist is empty");
        return;
    }
    temp=start;
    prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    printf("\nDeleted node is %s",temp->usn);
    if(prev!=NULL)
        prev->next=NULL;
    else
        start=NULL;
    free(temp);
}
void display()
{
    node *temp=start;
    int count=0;
    if(start==NULL)
    {
        printf("\nlist is empty");
        return;
    }
    printf("\nList elements are:");
    while(temp!=NULL)
    {
        printf("\nUSN: %s, Name: %s, Branch: %s, Sem: %d, phone: %s",temp->usn,temp->name,temp->branch,temp->sem,temp->phone);
        temp=temp->next;
        count++;
    }
    printf("\nCount=%d",count);
}
int main()
{
    int choice,n,i;
    while(1)
    {
        printf("\n***** Singly Linked List Operations *****");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete from Beginning");
        printf("\n4. Delete from End");
        printf("\n5. Display and Count");
        printf("\n6. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the number of students to insert at the beginning:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                    insertbegin();
                break;
            case 2:
                printf("\nEnter the number of students to insert at the end:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                    insertend();
                break;
            case 3:
                deletebegin();
                break;
            case 4:
                deleteend();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid Choice");
                break;
        }
    }
}