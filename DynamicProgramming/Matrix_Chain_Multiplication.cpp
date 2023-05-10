#include<bits/stdc++.h>

using namespace std;

void printParenthesis(int i, int j, int n, int* bracket,char& name)
{
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "( ";
 
    printParenthesis(i, *((bracket + i * n) + j), n,bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,bracket, name);
    cout << " )";
}

int matrixChainMultiplication(int n, int arr[])
{
    int a[n][n],bracket[n][n];
    for(int i=1;i<n;++i){
        a[i][i]=0;
    }
    for(int k=2;k<n;++k){
        for(int i=1;i<n-k+2;++i){
            int j=i+k-1;
            a[i][j]=INT_MAX;
            for(int x=i;x<j;++x){
                int t=a[i][x]+a[x+1][j]+arr[i-1]*arr[x]*arr[j];
                if(t<a[i][j]){
                    a[i][j]=t;
                    bracket[i][j]=x;
                }
            }
        }
    }
    char name='A';
    printParenthesis(1, n - 1, n, (int*)bracket, name);
    return a[1][n-1];
}

int main(){
    int n;
    cout<<"Enter number of Matrix :- ";
    cin>>n;
    ++n;
    int a[n];
    cout<<"\nEnter order matrix :- ";//In array format
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    cout<<endl;
    cout<<"\nMinimum number of operations to be performed = "<<matrixChainMultiplication(n,a)<<endl;
    return 0;
}
