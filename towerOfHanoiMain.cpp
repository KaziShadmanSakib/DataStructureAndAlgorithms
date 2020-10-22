#include<bits/stdc++.h>
using namespace std;
int towerOfHanoi(int n){
	int y;
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	else{
		y = 2 * towerOfHanoi(n-1);
		return y+1;
	}
}
int main()
{
	int n,res;
	cin>>n;
	res = towerOfHanoi(n);
	cout<<res<<endl;
	return 0;
}