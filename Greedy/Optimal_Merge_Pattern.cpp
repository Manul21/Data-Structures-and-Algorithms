#include<bits/stdc++.h>

using namespace std;

int OMP(int n,priority_queue<int,vector<int>,greater<int>> file){
    int ans=0;
    vector<int> v;
    while(file.size()>1){
        int a,b;
        a=file.top();file.pop();
        b=file.top();file.pop();
        ans+=(a+b);
        file.push(a+b);
    }
    return ans;
}

int main(){
    int n;
    cout<<"\nEnter number of files :- ";
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> file;
    cout<<"\nEnter number of elements in each file :- ";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        file.push(temp);
    }
    cout<<"\nTotal number of operations required to merge the files :- "<<OMP(n,file);
    return 0;
}