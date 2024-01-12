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
    printf("Enter the student details\n");
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
    node *newnode;
    newnode=getnode();
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
    node *newnode,*temp;
    newnode=getnode();
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
    node *temp;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=start;
    start=temp->next;
    printf("Deleted usn is %s",temp->usn);
    free(temp);
}
void display()
{
    int count=0;
    node *temp=start;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    printf("The List element is");
    while(temp!=NULL)
    {
        printf("name \tusn\t\tbranch\tphno\tsem");
        printf("%s\t%s\t%s\t%s\t%d",temp->name,temp->usn,temp->branch,temp->phone,temp->sem);
        temp=temp->next;
        count++;
    }
    printf("count=%d",count);
}
void deleteend()
{
    node *temp=start,*prev;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    if(start->next==NULL)
    {
        printf("Deleted usn is %s",temp->usn);
        start=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        printf("Deleted usn is %s",temp->usn);
        free(temp);
    }
}

int main()
{
    int choice,i,n;
    while(1)
    {
        printf("Enter your choice\n");
        printf("1 for insertbegin\n2 for insertend\n3 for deletebegin\n4 for deleteend\n5 for display\n6 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number of students\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                insertbegin();
            }
            break;

            case 2: insertend();
            break;

            case 3: deletebegin();
            break;

            case 4: deleteend();
            break;

            case 5: display();
            break;

            case 6: exit(0);

            default: printf("invalid choice\n");

        }
        
    }
}