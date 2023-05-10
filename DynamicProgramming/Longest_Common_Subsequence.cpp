#include<bits/stdc++.h>

using namespace std;

int max(int a,int b){
    return a>b?a:b;
}
void longestCommonSub(string a,string b,int n,int m){
    int lcs[n+1][m+1];
    for(int i=0;i<=n;i++){
        lcs[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        lcs[0][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i-1]==b[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    string ans="";
    for(int j=m,i=n;j>=0 && i>=0;--i,--j){
        if(lcs[i][j]!=lcs[i-1][j-1]){
            ans+=a[i-1];
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"\nLongest common subsequence in the given string :- "<<ans<<endl;
    return;
}

int main(){
    string a,b;
    cout<<"\nEnter first string :- ";
    cin>>a;
    cout<<"\nEnter second string :- ";
    cin>>b;
    longestCommonSub(a,b,a.size(),b.size());
    return 0;
}