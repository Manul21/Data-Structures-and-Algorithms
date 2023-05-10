#include<bits/stdc++.h>

using namespace std;

#define INF 10000

void printSolution(vector<vector<int>> &dist,int v){
    cout<<"The following matrix shows the shortest distances between every pair of vertices \n";
    for (int i=0;i<v;i++) {
        for (int j=0;j<v;j++) {
            if (dist[i][j] == INF)
                cout<<"N.P"<<"\t";
            else
                cout<<dist[i][j]<<"\t";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>> &graph,int v){
    vector<vector<int>> dist(v,vector<int> (v));
    int i, j, k;

    for (i=0;i<v; i++){
        for (j=0;j<v;j++){
            dist[i][j] = graph[i][j];
        }
    }
    for (k=0;k<v;k++) {
        for (i=0;i<v;i++) {
            for (j=0;j<v;j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist,v);
}

int main(){
    int v,edge,e,s,w;
    cout<<"Enter Number of  vertices :- ";
    cin>>v;
    vector<vector<int>> graph(v,vector<int> (v,INF));
    for(int i=0;i<v;i++){
        graph[i][i]=0;
    }
    cout<<"Enter Number of Edges :- ";
    cin>>edge;
    for(int i=0;i<edge;i++){
        cout<<"Enter edge start , end and weight :- ";
        cin>>s>>e>>w;
        graph[s][e]=w;
    }
    floydWarshall(graph,v);   
    return 0;
}