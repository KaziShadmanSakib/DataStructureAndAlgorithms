#include<bits/stdc++.h>
using namespace std;

long long dp[50];

long long flag(long long n){
	dp[0] = 1;
	dp[1] = dp[2] = 2;
	for(int i=3;i<=45;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main()
{
	long long n;
	cin>> n;
	long long res = flag(n);
	cout<< res << endl;
	return 0;
}