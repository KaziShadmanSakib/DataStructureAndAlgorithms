#include<bits/stdc++.h>
using namespace std;

long long dp[55];

long long tileGrid(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	if(dp[n] == -1){
		dp[n] = tileGrid(n-1) + tileGrid(n-3) + tileGrid(n-2) + tileGrid(n-3) + tileGrid(n-3) + tileGrid(n-3);
	}
	return dp[n];
}

int main()
{
	int n;
	cin>> n;
	memset(dp,-1,sizeof(dp));
	long long res = tileGrid(n);
	cout<< res << endl;
	return 0;
}