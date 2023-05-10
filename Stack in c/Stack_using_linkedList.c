#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* push(struct Node *head){
    struct Node *node;
    int val;
    node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to push :- ");
    scanf("%d",&val);
    node->data=val;
    node->next=head;
    return node;
}

struct Node* pop(struct Node *head){
    if(head==NULL){
        printf("Stack is Empty\n");
        return NULL;
    }
    printf("%d is poped\n",head->data);
    return head->next;
}

void display(struct Node *head){
    if(head==NULL){
        printf("Stack is Empty\n");
    }
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    struct Node *head;
    int a;
    head=NULL;
    do{
        printf("\nEnter \n1...To Push\n2...To Pop\n3...To Display\n0...To Exit\n");
        scanf("%d",&a);
        switch(a){
            case 1:
                head=push(head);
                break;
            case 2:
                head=pop(head);
                break;
            case 3:
                display(head);
                break;
            case 0:
                printf(".....THANKS FOR USING OUR PROGRAM.....\n");
                break;
            default:
                printf("Enter valid input\n");                    
        }
    }while(a);
    return 0;
}
