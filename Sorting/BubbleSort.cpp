#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cout<<"Enter size of array :- ";
    cin>>n;
    int a[n];
    cout<<"Enter Array Elements\n\n:- ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(a[j]<a[j-1]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

