#include<bits/stdc++.h>

using namespace std;

int knapsack(int W, int wt[], int p[], int n) 
{ 
    int a[n+1][W+1],keep[n+1][W+1];
    for(int i=0;i<=W;i++){
        a[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        keep[i][0]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(wt[i]<=j && (p[i] + a[i][j-wt[i]]>a[i][j])){
                keep[i+1][j]=1;
                a[i+1][j]=p[i]+a[i][j-wt[i]];
            }
            else{
                keep[i+1][j]=0;
                a[i+1][j]=a[i][j];
            }
        }
    }
    int k=W;
    vector<int> v;
    for(int i=n;i>0 && k>0;--i){
        if(keep[i][k]==1){
            v.push_back(i);
            k-=wt[i-1];
        }
    }
    cout<<"No of objects picked :- "<<v.size()<<"\nList of picked objects :- ";
    for(int i=v.size()-1;i>=0;--i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return a[n][W];
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
    int k=knapsack(W,wt,p,n);
    cout<<"The maximum profit generated = "<<k<<endl;
    return 0;
}