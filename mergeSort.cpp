#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = a[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = a[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int l,int r){
    int mid = (l+r)/2;
    if(l<r){
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int n,a[100];
    cin>>n;
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