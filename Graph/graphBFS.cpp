#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<int> a[],int n){
    vector<int> v;
    bool b[n]={0};
    for(int i=1;i<n;i++){
        if(!b[i]){
            queue<int> q;
            q.push(i);
            b[i]=1;
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                v.push_back(temp);
                for(auto it:a[temp]){
                    if(!b[it]){
                        q.push(it);
                        b[it]=1;
                    }
                }
            }
        }
    }
    return v;
}

int main(){
    int n,m;
    cout<<"Enter the number of nodes and edges :- ";
    cin>>n>>m;
    n++;
    vector<int> graph[n];
    cout<<"Enter the start and end of every edge\n";
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> v;
    v=bfs(graph,n);
    for(auto i:v){
        cout<<i<<" ";
    }   
    cout<<endl;
}