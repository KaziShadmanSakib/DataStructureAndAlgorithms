#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
string string1,string2;

int lcs(int n,int m){
	if(n<0 || m<0){
		return 0;
	}
	if(dp[n][m]==-1){
		if(n==0 || m==0){
			dp[n][m] = 0;
		}
		if(string1[n]==string2[m]){
			dp[n][m] = 1 + lcs(n-1,m-1);
		}
		else{
			dp[n][m] = max(lcs(n-1,m),lcs(n,m-1));
		}
	}
	return dp[n][m];
}

int main()
{
	while(getline(cin,string1)){
		getline(cin,string2);
		int n = string1.size();
		int m = string2.size();
		memset(dp,-1,sizeof(dp));
		int res = lcs(n-1,m-1);
		cout<< res << endl;
	}
	return 0;
}