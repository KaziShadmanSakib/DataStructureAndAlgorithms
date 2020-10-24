#include<bits/stdc++.h>
using namespace std;
int factorialItter(int x){
	int flag = 1, count;
	for(count=2;count<=x;count++){
		flag = flag * count;
	}
	return flag;
}
int main()
{
	int x,res;
	cin>>x;
	res = factorialItter(x);
	cout<<res<<endl;
	return 0;
}