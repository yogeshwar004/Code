#include<stdio.h>
#include<stdlib.h>
typedef struct DLL
{
    int ssn,sal;
    char name[20],dept[20],desg[20],phno[11];
    struct DLL *prev,*next;
}node;
node *start=NULL;
node* getnode()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter SSN, Name, Department, Designation, Salary, Phone number");
    scanf("%d%s%s%s%d%s",&newnode->ssn,newnode->name,newnode->dept,newnode->desg,&newnode->sal,newnode->phno);
    newnode->prev=NULL;
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
    start->prev=newnode;
    start=newnode;
}
void insertend()
{
    node *newnode=getnode(),*temp=start;
    if(start==NULL)
    {
        start=newnode;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
}
void deletebegin()
{
    node *temp=start;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
        printf("\nDeleted node is \n%d\t%s\t%s\t%s\t%d\t%s",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
        start->prev=NULL;
        start=temp->next;
        free(temp);
}
void deleteend()
{
    node *temp=start;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    if(start->next==NULL)
    {
        printf("\nDeleted node is \n%d\t%s\t%s\t%s\t%d\t%s",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
        start=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        (temp->prev)->next=NULL;
        printf("\nDeleted node is \n%d\t%s\t%s\t%s\t%d\t%s",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
        free(temp);
    }
}
void display()
{
    node *temp=start;
    int count=0;
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nList elements are");
    while(temp!=NULL)
    {
        printf("\n%d\t%s\t%s\t%s\t%d\t%s",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
        temp=temp->next;
        count++;
    }
    printf("\nNo.of Employees=%d",count);
}
int main()
{
    int choice,n,i;
    while(1)
    {
        printf("\n***** Double Linked List Operations *****");
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