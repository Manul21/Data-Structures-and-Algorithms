#include<bits/stdc++.h>

using namespace std; 
 
struct Job 
{ 
    int id;
    int dead;  
    int profit; 
}; 



bool compare(Job &a,Job &b){
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job a[], int n) 
{
    sort(a,a+n,compare);
    int m=0,p=0,dmax=0;
    for(int i=0;i<n;++i){
        if(a[i].dead>dmax){
            dmax=a[i].dead;
        }
    }
    vector<int> sol(dmax+1,0);
    for(int i=0;i<n;++i){
        int k=dmax<a[i].dead?dmax:a[i].dead;
        while(k>0){
            if(sol[k]==0){
                sol[k]=a[i].id;
                p+=a[i].profit;
                break;
            }
            --k;
        }
    }
    for(int i=1;i<=dmax;++i){
        if(sol[i]!=0)++m;
    }
    return sol;
}

int main() 
{ 
    int n;
    cout<<"Enter no. of jobs :- ";
    cin>>n;
    Job a[n];
    cout<<"Enter job no. ,deadline and profit for jobs respectively for n jobs \n";
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[i].id=x;
        a[i].dead=y;
        a[i].profit=z;
    }
    vector<int> ans = JobScheduling(a, n);
    cout<<"Jobs in sequence should be done :- ";
    for(int i=1;i<ans.size();++i){
        if(ans[i])
        cout<<ans[i]<<" ";
    }
    cout<<"\n\n";
	return 0; 
}
