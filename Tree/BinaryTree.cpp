#include <bits/stdc++.h>

using namespace std;

class BinaryTree{
    public:
        BinaryTree *left,*right;
    public:
        int data;
    BinaryTree(int a){
        this->data=a;
        this->left=NULL;
        this->right=NULL;
    }
    BinaryTree(int a,BinaryTree *left,BinaryTree *right){
        this->data=a;
        this->left=left;
        this->right=right;
    }
};

BinaryTree* create(BinaryTree *root){
    cout<<"Enter Data value :- ";
    int val;
    cin>>val;
    if(val==-1){
        return NULL;
    }
    BinaryTree *node=new BinaryTree(val);
    cout<<"For left of "<<val<<endl;
    node->left=create(node);
    cout<<"For right of "<<val<<endl;
    node->right=create(node);
    return node;
}

void InOrder(BinaryTree *root){
    if(root==NULL){
        return;
    }    
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}


void PreOrder(BinaryTree *root){
    if(root==NULL){
        return;
    }    
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}


void PostOrder(BinaryTree *root){
    if(root==NULL){
        return;
    }    
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

void LevelOrder(BinaryTree *root){
    queue<BinaryTree*> temp;
    if(root!=NULL){
        temp.push(root);
        temp.push(NULL);
    }
    while(!temp.empty()){
        BinaryTree *val=temp.front();
        temp.pop();
        if(temp.empty())break;
        if(val==NULL){
            cout<<endl;
            temp.push(NULL);
            continue;
        }
        cout<<val->data<<" ";
        if(val->left!=NULL)temp.push(val->left);
        if(val->right!=NULL)temp.push(val->right);
    }
    return;
}

int main()
{
    BinaryTree *root=NULL;
    root=create(root);
    InOrder(root);
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    LevelOrder(root);
    cout<<endl;
    return 0;
}
