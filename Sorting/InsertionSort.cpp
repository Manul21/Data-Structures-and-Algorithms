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
    int temp,j;
    for(int i=1;i<n;i++){
        temp=a[i];
        for(j=i-1;j>=0;j--){
            if(a[j]>temp){
                a[j+1]=a[j];
            }
            else{
                break;
            }
        }
        a[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

