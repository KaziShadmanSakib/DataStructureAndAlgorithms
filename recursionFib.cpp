#include<bits/stdc++.h>
using namespace std;
int recFib(int x){
	if(x<2){
		return x;
	}
	return recFib(x-1) + recFib(x-2);
}
int main()
{
	int x,res;
	scanf("%d",&x);
	res = recFib(x);
	printf("%d\n",res);
	return 0;
}