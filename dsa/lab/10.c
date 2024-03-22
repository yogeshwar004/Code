#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;
node* insert(node *root,int key)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=key;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    return root;
}
void inorder(node *root)
{
    
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void search(node *root,int key)
{
    if(root==NULL)
    {
        printf("\nKey not found");
        return;
    }
    if(root->data==key)
    {
        printf("\nKey found");
        return;
    }
    if(key<root->data)
        search(root->left,key);
    else
        search(root->right,key);
}
int main()
{
    int i,n,key,choice;
    node *root=NULL;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
    for(i=0;i<n;i++)
    {
        printf("\n");
        scanf("%d",&key);
        root=insert(root,key);
    }
    while(1)
    {
        printf("\nEnter your choice : ");
        printf("\n1. Inorder\n2. Preorder\n3. Postorder\n4. Search\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\n Inorder is \n");    
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("\n Preorder is \n");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("\n Postorder is \n");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("\n Enter the key to be searched : ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}