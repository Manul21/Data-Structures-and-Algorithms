#include<bits/stdc++.h>

using namespace std;

class Node{
    public :
    int val,height;
    public :
    Node *left,*right;
    Node(int x){
        val=x;
        height=1;
        left=NULL;
        right=NULL;
    }
    Node(int x,int h){
        val=x;
        height=h;
        left=NULL;
        right=NULL;
    }
};

int max(int a, int b)
{
    return (a > b)? a : b;
}

int getHeight(Node* root){
    if(root==NULL)
        return 0;
    return root->height;
}

int getBalanceFactor(Node *root){
    if(root==NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node *leftRotate(Node *root){
    Node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root->height= max(getHeight(root->right),getHeight(root->left)) +1;
    temp->height= max(getHeight(temp->right),getHeight(temp->left)) +1;
    return temp;
}

Node *rightRotate(Node *root){
    Node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root->height= max(getHeight(root->right),getHeight(root->left)) +1;
    temp->height= max(getHeight(temp->right),getHeight(temp->left)) +1;
    return temp;
}

Node *insert(Node *root,int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key<root->val){
        root->left = insert(root->left,key);
    }
    else if(key>root->val){
        root->right = insert(root->right,key);
    }
    else 
        return root;
        
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && key < root->left->val)
        return rightRotate(root);
        
    if (balance < -1 && key > root->right->val)
        return leftRotate(root);

    if (balance > 1 && key > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance< -1 && key < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void InOrder(Node *root){
    if(root==NULL){
        return;
    }    
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);
}


void PreOrder(Node *root){
    if(root==NULL){
        return;
    }    
    cout<<root->val<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}


void PostOrder(Node *root){
    if(root==NULL){
        return;
    }    
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
}

void LevelOrder(Node *root){
    queue<Node*> temp;
    if(root!=NULL){
        temp.push(root);
        temp.push(NULL);
    }
    while(!temp.empty()){
        Node *v=temp.front();
        temp.pop();
        if(temp.empty())break;
        if(v==NULL){
            cout<<endl;
            temp.push(NULL);
            continue;
        }
        cout<<v->val<<" ";
        if(v->left!=NULL)temp.push(v->left);
        if(v->right!=NULL)temp.push(v->right);
    }
    return;
}

Node *create(Node *root){
    int key;
    cout<<"Enter data value :- ";
    cin>>key;
    if(key==-1){
        return root;
    }
    root=insert(root,key);
    return create(root);
}

void display(Node *root){
    cout<<"\nInOrder Traversal :- ";
    InOrder(root);
    cout<<endl;
    cout<<"PreOrder Traversal :- ";
    PreOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal :- ";
    PostOrder(root);
    cout<<endl;
    cout<<"\nLevelOrder Traversal :- \n";
    LevelOrder(root);
    cout<<endl;
}

string search(Node *root, int key){
    if(root==NULL)return "False";
    if(root->val==key)return "True";
    if(root->val < key)return search(root->right,key);
    return search(root->left,key);
}
int main(){
    Node *root;
    int op;
    do{
        int key;
        printf("\nEnter 1...To_Create\n2...To_Display\n3..To_Insert\n4...Search\n0...To_Exit\n");
        cin>>op;
        switch(op){
            case 1:
                root=create(NULL);
                break;
            case 2:
                display(root);
                break;    
            case 3:
                cout<<"\nEnter value to be inserted :- ";
                cin>>key;
                root=insert(root,key);
                break;
            case 4:
                cout<<"\nEnter value to be Serched :- ";
                cin>>key;
                cout<<"\nSearch result :- " <<search(root,key)<<endl;
                break;
            case 0:
                cout<<"-------THANKS------\n\n";
                break;
            default :
                cout<<"Enter valid Input\n\n";        
        }
    }while(op);
    return 0;
}