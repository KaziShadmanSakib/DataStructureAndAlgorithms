#include<bits/stdc++.h>
using namespace std;

#define MAX 105

string a,b;
long long sizeOfA, sizeOfB;
long long dp[MAX][MAX];

int LCSub(int sizeOfA, int sizeOfB){
	long long res = 0;
	for(int i=0;i<=sizeOfA;i++){
		for(int j=0;j<=sizeOfB;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				res = max(res, dp[i][j]);
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	return res;
}

int main()
{
	cin>> a >> b;
	sizeOfA = a.length();
	sizeOfB = b.length();
	long long res = LCSub(sizeOfA, sizeOfB);
	cout<< res << endl;
	return 0;
}