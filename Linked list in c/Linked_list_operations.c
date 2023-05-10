/* CS-1832
Linked List Operations - Program in C
Sandeep Raghuwanshi
•
31 Aug

LinkedListComplete.c
Text
Class comments

Linked List Operations - Program in C */

//This program demonstrates the implementation of linked list with complete set of operations

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
//Function to create a node of linked list
struct Node* CreateNode(int val)
{
  struct Node* temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = val;
  temp->next = NULL;
  return(temp);
}
//Function to create new list
struct Node * CreateList(struct Node* head)
{
  int item, cont=1;

  struct Node *temp, *ptr;

  while(cont != 0)
  {
    printf("\nEnter data to insert: ");
      scanf("%d", &item);
    temp = CreateNode(item);

    if(head == NULL)
      {
        temp->next = NULL;
        head = temp;
      }
    else
      {
        ptr = head;
        while(ptr->next != NULL)
              ptr= ptr->next;
        ptr->next = temp;
        temp->next = NULL;
      }
    printf("\nCONTINUE:   YES-1/NO-0:  ");
      scanf("%d", &cont);
  }
  return(head);
}

//Function to delete existing linked List

struct Node* DeleteList(struct Node* head)
{
  head = NULL;
  return(head);
}

//Function to display linked list.

struct Node* DisplayList(struct Node* head)
{
  struct Node* ptr;
  ptr = head;
  if(ptr == NULL)
    printf("\n List is Empty\n");
  else
    {
      while(ptr != NULL)
        {
          printf("  %d  ", ptr->data);
          ptr= ptr->next;
        }
    }
    return(head);
}

//Function to insert new element at begning

struct Node * InsertFirst(struct Node * head)
{
  if(head == NULL)
    {
      printf("\n=====ERROR MESSAGE=====\n");
      printf("\nList is Empty First Create lsit\n");
      return(head);
    }
  else
    {
      struct Node * temp, *ptr;
      int item;
      printf("\nEnter data to insert: ");
        scanf("%d", &item);
      temp = CreateNode(item);
      ptr = head;
      head = temp;
      temp->next = ptr;
    }
  return(head);
}

//Function to insert a new item in between of List

struct Node * InsertMid(struct Node * head)
{
  if(head == NULL)
    {
      printf("\n=====ERROR MESSAGE=====\n");
      printf("\nList is Empty First Create lsit\n");
      return(head);
    }
  else
    {
      struct Node * temp, *ptr, *shift;
      int item, pos, count = 1;
      printf("\nEnter the position to insert: ");
        scanf("%d", &pos);
      printf("\nEnter data to insert: ");
        scanf("%d", &item);
      temp = CreateNode(item);
      shift = head;
      while(count<pos)
      {
        shift = shift->next;
        count++;
      }
      ptr = shift->next;
      shift->next = temp;
      temp->next = ptr;
    }
  return(head);
}
//Function to insert element at last of list
struct Node * InsertLast(struct Node * head)
{
  if(head == NULL)
    {
      printf("\n=====ERROR MESSAGE=====\n");
      printf("\nList is Empty First Create lsit\n");
      return(head);
    }
  else
    {
      struct Node * temp, *ptr;
      int item;

      printf("\nEnter data to insert: ");
        scanf("%d", &item);
      temp = CreateNode(item);
      ptr = head;
      while(ptr->next!= NULL)
      {
        ptr = ptr->next;

      }
      ptr->next = temp;
      temp->next = NULL;
    }
  return(head);
}

//Function to delete first node of List
struct Node* DeleteFirst(struct Node* head)
{
  if(head==NULL)
    {
      printf("\nList is Empty\n");
      return(head);
    }
  else
    return(head->next);
}

//Function to delete in between  node of List
struct Node* DeleteMid(struct Node* head)
{
  if(head==NULL)
    {
      printf("\nList is Empty\n");
      return(head);
    }
  else
    {
      struct Node* ptr;
      int pos, count = 1;
      printf("\nEnter the node to be deleted after: ");
        scanf("%d", &pos);
      ptr = head;
      while(count<pos)
        {
          ptr = ptr->next;
          count++;
        }
      ptr->next = ptr->next->next;
    }
    return(head);
}

//Function to delete last  node of List
struct Node* DeleteLast(struct Node* head)
{
  if(head == NULL)
    {
      printf("\nList is Empty\n");
      return(head);
    }
  else
    {
      struct Node* ptr;
      ptr = head;
      while(ptr->next->next != NULL)
        ptr = ptr->next;
      ptr->next = NULL;
    }
    return(head);
}

//Function to Update value at any node in linked list

struct Node* UpdateValue(struct Node *head)
{
  int old,new;
  struct Node *ptr;
  ptr=head;
  printf("Enter no. to be updated :- ");
  scanf("%d",&old);
  printf("Enter new no. :- ");
  scanf("%d",&new);
  while(ptr!=NULL){
    if(ptr->data==old){
      ptr->data=new;
      break;
    }
    ptr=ptr->next;
  }
  if(ptr->data!=new){
    printf("%d is not present in the list\n",old);
  }
  return head;
}


//Function to Search the position of any element in the list

struct Node* SearchElementIndex(struct Node* head)
{
  int num,i=1,check=0;
  struct Node *ptr;
  ptr=head;
  printf("Enter no. to be Searched :- ");
  scanf("%d",&num);
  while(ptr!=NULL){
    if(ptr->data==num){
      check=1;
      break;
    }
    i++;
    ptr=ptr->next;
  }
  if(!check){
    printf("%d is not present in the list\n",num);
  }
  else
    printf("%d is at %d position in the list\n",num,i);
  return head;
}


int main()
{
  struct Node* head;
  int ch;
  head = NULL;
  do{
    printf("\nEnter your choice:  \n");
    printf("\n1...CreateList\n2...DeleteList\n3...InsertFirst\n4...InsertMid\n5...InsertLast\n6...DeleteFirst\n7...DeleteMid\n8...DeleteLast\n9...DisplayList\n10...UpdateValue\n11...SearchElementIndex\n0...Exit\n");
      scanf("%d", &ch);

    switch(ch)
      {
        case 1:
              head = CreateList(head);
              break;
        case 2:
              head = DeleteList(head);
              break;
        case 3:
              head = InsertFirst(head);
              break;
        case 4:
              head = InsertMid(head);
              break;
        case 5:
              head = InsertLast(head);
              break;
        case 6:
              head = DeleteFirst(head);
              break;
        case 7:
              head = DeleteMid(head);
              break;
        case 8:
              head = DeleteLast(head);
              break;
        case 9:
              head = DisplayList(head);
              break;
        case 10:
              head = UpdateValue(head);
              break;
        case 11:
              head = SearchElementIndex(head);
              break;
      }
  }while(ch!=0);
  return 0;
}
// LinkedListComplete.c
// Displaying LinkedListComplete.c