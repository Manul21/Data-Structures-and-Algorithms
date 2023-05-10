#include<bits/stdc++.h>

using namespace std;
 
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[],int n,int i)
{
    int max=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && a[l]>a[max])
        max=l;
 
    if(r<n && a[r]>a[max])
        max=r;
 
    if (max!=i) {
        swap(a+i,a+max);
        heapify(a,n,max);
    }
}
 
void heapSort(int a[],int n)
{
    for(int i=n/2;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
 
int main()
{
    int n;
    cout<<"Enter size of Array :- ";
    cin>>n;
    int a[n];
    cout<<"Enter Array elments\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n"; 
    return 0;
}