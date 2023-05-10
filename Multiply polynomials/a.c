#include<stdio.h>
#include<stdlib.h>

struct Node{
    int constant;
    int exponent;
    struct Node *next;
};

struct Node* CreatList(struct Node* head,int a,int b){
    struct Node *ptr,*node;
    if(a==0){
        return head;
    }
    node=(struct Node*)malloc(sizeof(struct Node));
    node->constant=a;
    node->exponent=b;
    node->next=NULL;
    if(head==NULL){
        return node;
    }
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=node;
    return head;
}

void Display(struct Node *head){
    struct Node *ptr;
    if(head==NULL){
        return;
    }
    ptr=head;
    while(ptr!=NULL){
        printf("%dx^%d",ptr->constant,ptr->exponent);
        ptr=ptr->next;
        if(ptr!=NULL)
            printf(" + ");
    }
}

struct Node* Multiply(struct Node *head1,struct Node *head2){
    struct Node *ptr1,*ptr2;
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    return NULL;
}
int main(){
    struct Node *poly1,*poly2,*result;
    int cons=0,exp=0,check;
    poly1=NULL;
    poly2=NULL;
    result=NULL;
    printf("Enter first polynomial \n");
    do{
        printf("Enter constant :- ");
        scanf("%d",&cons);
        printf("Enter exponent :- ");
        scanf("%d",&exp);
        poly1=CreatList(poly1,cons,exp);
        printf("1...To Continue \n0...To exit\n:- ");
        scanf("%d",&check);
    }while(check!=0);
    printf("Enter second polynomial \n");
    do{
        printf("Enter constant :- ");
        scanf("%d",&cons);
        printf("Enter exponent :- ");
        scanf("%d",&exp);
        poly2=CreatList(poly2,cons,exp);
        printf("1...To Continue \n0...To exit\n:- ");
        scanf("%d",&check);
    }while(check!=0);
    result=Multiply(poly1,poly2);
    Display(result);
    return 0;
}