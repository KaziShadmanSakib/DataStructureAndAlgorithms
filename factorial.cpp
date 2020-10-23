#include<bits/stdc++.h>
using namespace std;
int factorial(int x){
	int multi;
	if(x<2){
		return 1;
	}
	else{
		multi = x * factorial(x-1);
		return multi;
	}
}
int main()
{
	int x,res;
	cin>>x;
	res = factorial(x);
	cout<<res<<endl;
	return 0;
}