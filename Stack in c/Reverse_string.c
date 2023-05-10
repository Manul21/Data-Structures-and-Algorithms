#include <stdio.h>
#include <stdlib.h>

struct Node{
    char ch;
    struct Node *next;
};

struct Node* push(struct Node *head , char val){
    struct Node *node;
    node=(struct Node*)malloc(sizeof(struct Node));
    node->ch=val;
    node->next=head;
    return node;
}

void display(struct Node *head){
    if(head==NULL){
        return ;
    }
    while(head!=NULL){
        printf("%c",head->ch);
        head=head->next;
    }
}


int main(){
    struct Node *head;
    char c;
    head=NULL;
    printf("Enter string\n");
    while(scanf("%c",&c)){
        if(c=='\n')
            break;
        head=push(head,c);
    }
    display(head);
    return 0;
}
