#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[1005][1005];
string string1,string2;

int AGTC(int n, int m){
	if(n<0 || m<0){
		return 0;
	}
	if(dp[n][m]==-1){
		if(n==0){
			dp[n][m] = m;
		}
		else if(m==0){
			dp[n][m] = n;
		}
		else if(string1[n-1] == string2[m-1]){
			dp[n][m] = AGTC(n-1,m-1);
		}
		else{
			dp[n][m] = 1 + min(AGTC(n,m-1),min(AGTC(n-1,m),AGTC(n-1,m-1)));
		}
	}
	return dp[n][m];
}

int main()
{
	while(scanf("%d",&n) != EOF){
		cin>> string1;
		cin>> m >> string2;
		memset(dp,-1,sizeof(dp));
		int res = AGTC(n,m);
		cout<< res << endl;
	}
	return 0;
}