/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int data;
    struct ListNode *head;
};
typedef struct SLL node;
node *start=NULL;
node* getnode()
{
    node *newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    newnode->head=NULL;
    return newnode;
}
void removeNthFromEnd()
{
    int n1,n;
    node *newnode,*temp,*prev;
    printf("Enter the number of Nodes:");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        newnode=getnode();
        if(start==NULL)
        {
            start=newnode;
        }
        else
        {
            newnode->data=start;
            start=newnode;
        }
    }
    temp=start;
    if(start=NULL)
        printf("List is empty");
    else
    {
        printf("Enter the Key Element location:");
        scanf("%d",&n);

        while(temp!=NULL)
        {
            for(int i=n;i>=0;i++)
            {
                prev=temp;
                temp=temp->head;
            }
        }
        if(temp==NULL)
            printf("Key not found");
        else
        {
            prev->head=temp->head;
            printf("The node is deleted ,i.e...,%d",temp->data);
        }
    }
}
int main()
{
    removeNthFromEnd();
    
}