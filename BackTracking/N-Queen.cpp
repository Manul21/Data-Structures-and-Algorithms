#include <bits/stdc++.h>

using namespace std;

bool isSafe(int *a,int row,int col,int n){
    for(int i=row-1;i>=0;i--){
        if(*((a+n*i) + col)==1)
            return false;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(*((a+n*i) + j)==1)
            return false;
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(*((a+n*i) + j)==1)
            return false;
    }
    return true;
}
bool Nqueen(int *a,int row,int n){
    if(row==n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(a,row,i,n)){
            *((a+n*row) + i)=1;
            if(Nqueen(a,row+1,n))
               return true; 
            *((a+n*row) + i)=0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter no. of Queens :- ";
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    Nqueen((int*)a,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j])
            cout<<"Q";
            else
            cout<<".";
        }
        cout<<endl;
    }
    return 0;
}
