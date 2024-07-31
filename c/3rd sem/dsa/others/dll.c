/*8. Develop a menu driven Program in C for the following operations on Doubly
Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept,
Designation, Sal, PhNo a. Create a DLL of N Employees Data by using end
insertion. b. Display the status of DLL and count the number of nodes in it c.
Perform Insertion and Deletion at End of DLL d. Perform Insertion and Deletion
at Front of DLL e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct DLL {
  int ssn;
  char name[20];
  char dept[20];
  char desg[20];
  int sal;
  char phno[11];
  struct DLL *prev, *next;
} node;

node* start = NULL;

node* getNode() {
  node* newnode;
  newnode = (node*)malloc(sizeof(node));
  printf("Enter SSN, Name, Department, Designation, Salary, Phone number\n");
  scanf("%d%s%s%s%d%s", &newnode->ssn, newnode->name, newnode->dept,
        newnode->desg, &newnode->sal, newnode->phno);
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}
void insertbegin() {
  node* newnode;
  newnode = getNode();
  if (start == NULL)
    start = newnode;
  else {
    newnode->next = start;
    start->prev = newnode;
    start = newnode;
  }
}
void insertend() {
  node *newnode, *temp = start;
  newnode = getNode();
  if (start == NULL) {
    start = newnode;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newnode;
  newnode->prev = temp;
}
void deletebegin() {
  node* temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("Deleted node is\n%d\t%s\t%s\t%s\t%d\t%s\n", temp->ssn, temp->name,
         temp->dept, temp->desg, temp->sal, temp->phno);
  start->prev = NULL;
  start = temp->next;
  free(temp);
}
void deleteend() {
  node* temp = start;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }
  if (start->next == NULL) {
    printf("Deleted node is\n%d\t%s\t%s\t%s\t%d\t%s\n", temp->ssn, temp->name,
           temp->dept, temp->desg, temp->sal, temp->phno);

    start = NULL;
    free(temp);
  } else {
    while (temp->next != NULL)
      temp = temp->next;
    (temp->prev)->next = NULL;
    printf("Deleted node is\n%d\t%s\t%s\t%s\t%d\t%s\n", temp->ssn, temp->name,
           temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
  }
}

void display() {
  node* temp = start;
  int count = 0;
  if (start == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("List elements are\n");
  while (temp != NULL) {
    printf("\n%d\t%s\t%s\t%d\t%s\n ", temp->ssn, temp->name, temp->desg,
           temp->sal, temp->phno);

    temp = temp->next;
    count++;
  }
  printf("No of employees=%d\n\n", count);
}

int main() {
  int choice, n, i;
  while (1) {
    printf("\n**** Doubly Linked List ****\n");
    printf(
        "\n 1.Insert at End \n 2.Insert at Beginning \n 3.Delete from "
        "Beginning \n 4.Delete from End \n 5.Display and count \n 6.Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the no of employees\n");
        scanf("%d", &n);
        for (i = 0; i < n; i++)
          insertend();
        break;
      case 2:
        insertbegin();
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
        break;
      default:
        printf("Invalid choice\n");
    }
  }
}