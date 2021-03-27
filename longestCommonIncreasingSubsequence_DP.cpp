#include<bits/stdc++.h>
using namespace std;

#define MAX 105

int a[MAX], b[MAX];
long long dp[MAX];
long long parent[MAX];
vector<long long> ans;

void LCIS(int sizeOfA, int sizeOfB){
	for(int i=0;i<sizeOfA;i++){
		long long currentLength = 0, previ = -1;
		for(int j=0;j<sizeOfB;j++){
			if(a[i] == b[j]){
				dp[j] = max(currentLength + 1, dp[j]);
				parent[j] = previ;			
			}
			if(a[i] > b[j]){
				currentLength = max(currentLength, dp[j]);
				previ = j;
			}
		}
	}
	long long result = 0, longestId = -1;
	for(int i=0;i<MAX;i++){
		if(dp[i] > result){
			result = dp[i];
			longestId = i;
		}
	}
	for(int i=0;longestId!=-1;i++){
		ans.push_back(b[longestId]);
		longestId = parent[longestId];
	}
	reverse(ans.begin(), ans.end());
}

int main()
{
	int sizeOfA, sizeOfB;
	cin>> sizeOfA >> sizeOfB;
	for(int i=0;i<sizeOfA;i++){
		cin>> a[i];
	}
	for(int i=0;i<sizeOfB;i++){
		cin>> b[i];
	}
	memset(dp,0,sizeof(dp));
	LCIS(sizeOfA, sizeOfB);
	for(int i=0;i<ans.size();i++){
		cout<< ans[i];
		if(i == ans.size()-1){
			cout<< endl;
		}
		else{
			cout<< " ";
		}
	}
	return 0;
}