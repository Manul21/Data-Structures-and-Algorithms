#include <iostream>

using namespace std;

int partition(int *a,int l, int h){
    int pivot=l;
    int i=l,j=h;
    while(i<j)
    {    
        while(i<=h && a[i]<=a[pivot])i++;
        while(j>=l && a[j]>a[pivot])j--;
        int temp=a[j];
        if(i<j){
            a[j]=a[i];
            a[i]=temp;
        }
        else{
            a[j]=a[pivot];
            a[pivot]=temp;
        }
    }    
    return j;
}

void quickSort(int *a,int l,int h){
    if(l>h)
        return;
    int pivot=partition(a,l,h);
    quickSort(a,l,pivot-1);
    quickSort(a,pivot+1,h);
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
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

