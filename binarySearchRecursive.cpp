#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[],int first,int last,int key){
	int mid = (first+last)/2;
	if(first>last){
		return 0;
	}
	else if(key==a[mid]){
		return 1;
	}
	else if(key<a[mid]){
		return binarySearch(a,first,mid-1,key);
	}
	else{
		return binarySearch(a,mid+1,last,key);
	}
}
int main()
{
	int n,a[10000],k,res;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>k;
	sort(a,a+n);
	res = binarySearch(a,0,n-1,k);
	if(res == 1){
		cout<<"Found"<<endl;
	}
	else{
		cout<<"Not Found"<<endl;
	}
	return 0;
}