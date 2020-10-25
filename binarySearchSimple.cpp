#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[],int n,int k){
	int mid;
	int first = 0;
	int last = n-1;
	while(first<=last){
		mid = (first+last)/2;
		if(k<a[mid]){
			last = mid - 1;
		}
		else if(k>a[mid]){
			first = mid + 1;
		}
		else{
			return 1;
		}
	}
	return 0;
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
	res = binarySearch(a,n,k);
	if(res == 1){
		cout<<"Found"<<endl;
	}
	else{
		cout<<"Not Found"<<endl;
	}
	return 0;
}