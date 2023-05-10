#include<bits/stdc++.h>

using namespace std;

vector<float> knapsack(int W, int wt[], int p[], int n) {
    priority_queue<pair<float,int>> heap;
    vector<float> x(n,0);
    for(int i=0;i<n;i++){
        heap.push(make_pair(((float)p[i]/(float)wt[i]),i));
    }
    while(W>0){
        int i=heap.top().second;
        heap.pop();
        if(wt[i]<=W){
            x[i]=1;
            W-=wt[i];
        }
        else{
            x[i]=(float)W/(float)wt[i];
            W=0;
        }
    }
    return x;
}

int main(){
    int n,W;
    cout<<"Enter number of objects :- ";
    cin>>n;
    cout<<"\nEnter capacity of Knapsack :- ";
    cin>>W;
    int wt[n],p[n];
    cout<<"\nEnter weight of every object :- ";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"\nEnter profit for every object :- ";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<float> k=knapsack(W,wt,p,n);
    cout<<"\nList of elements :- ";
    for(int i=0;i<n;++i){
        cout<<k[i]<<" ";
    }
    cout<<"\n\n";
    return 0;
}