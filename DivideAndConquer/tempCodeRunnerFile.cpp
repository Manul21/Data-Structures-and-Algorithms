#include <iostream>

using namespace std;

void merge(int *a,int l, int mid,int h){
    int b[h-l+1];
    int j=l,k=mid+1;
    for(int i=0;i<h-l+1;i++){
        if(j<=mid && k<=h){
            if(a[j]<a[k]){
                b[i]=a[j++];
            }
            else{
                b[i]=a[k++];
            }
        }
        else if(j<=mid){
            b[i]=a[j++];
        }
        else{
            b[i]=a[k++];
        }
    }
    for(int i=0,j=l;i<h-l+1;i++,j++){
        a[j]=b[i];
    }
    return;
}

void mergeSort(int *a,int l,int h){
    if(h>l){
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter size of Array :- ";
    cin>>n;
    int a[n];
    cout<<"Enter Array elements \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
