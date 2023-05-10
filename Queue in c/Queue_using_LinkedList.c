#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* queue(struct Node *tail){
    struct Node *node,*temp;
    int val;
    node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to be queued :- ");
    scanf("%d",&val);
    if(tail==NULL){
        tail=node;
    }
    else{
        tail->next=node;
    }
    node->data=val;
    node->next=NULL;
    return node;
}

struct Node* dequeue(struct Node *head){
    if(head==NULL){
        printf("Queue is Empty\n");
        return NULL;
    }
    return head->next;
}

void display(struct Node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    struct Node *head,*tail;
    int a;
    head=NULL;
    tail=NULL;
    do{
        printf("\nEnter \n1...To Queue\n2...To Dequeue\n3...To Display\n0...To Exit\n");
        scanf("%d",&a);
        switch(a){
            case 1:
                tail=queue(tail);
                if(head==NULL)
                    head=tail;
                    break;
            case 2:
                head=dequeue(head);
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
