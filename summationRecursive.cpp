#include<bits/stdc++.h>
using namespace std;
int summation(int a[],int n){
	if(n==0){
		return 0;
	}
	int last = a[n-1];
	int restSum = summation(a,n-1);
	return last + restSum;
}
int main()
{
	int n,a[10000],res;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	res = summation(a,n);
	cout<<res<<endl;
	return 0;
}