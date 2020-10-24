#include<bits/stdc++.h>
using namespace std;
int combination(int n,int k){
	int res;
	if(k==1){
		return n;
	}
	else if(n==k){
		return 1;
	}
	else{
		res = combination(n-1,k) + combination(n-1,k-1);
		return res;
	}
}
int main()
{
	int n,k,res;
	cin>>n;
	cin>>k;
	res = combination(n,k);
	cout<<res<<endl;
	return 0;
}