#include<bits/stdc++.h>
using namespace std;

#define MAX 105

int a[MAX], b[MAX];
long long dp[MAX];

long long LCIS(int sizeOfA, int sizeofB){
	for(int i=0;i<sizeOfA;i++){
		long long currentLength = 0;
		for(int j=0;j<sizeofB;j++){
			if(a[i] == b[j]){
				dp[j] = max(currentLength + 1, dp[j]);
			}
			if(a[i] > b[j]){
				currentLength = max(currentLength, dp[j]);
			}
		}
	}
	return *max_element(dp, dp+MAX);
}

int main()
{
	int sizeOfArray1, sizeOfArray2;
	cin>> sizeOfArray1 >> sizeOfArray2;
	for(int i=0;i<sizeOfArray1;i++){
		cin>> a[i];
	}
	for(int i=0;i<sizeOfArray2;i++){
		cin>> b[i];
	}
	memset(dp,0,sizeof(dp));
	long long res = LCIS(sizeOfArray1, sizeOfArray2);
	cout<< res << endl;
	return 0;
}