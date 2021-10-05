#include<bits/stdc++.h>
using namespace std;

vector<int> twoSums(vector<int>& nums, int target){

	vector<int> ans;

	for(int i=0;i<nums.size()-1;i++){

		for(int j=i+1;j<nums.size();j++){

			if(nums[i] + nums[j] == target){

				ans.push_back(i);
				ans.push_back(j);
				break;

			}

		}

	}

	return ans;

}

int main()
{
	int n,target;
	cin>> n;
	vector<int> nums;

	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		nums.push_back(num);

	}
	cin>> target;

	vector<int> ans;

	ans = twoSums(nums,target);

	for(int i=0;i<ans.size();i++){

		cout<< ans[i] << " ";

	}

	cout<< endl;

	return 0;

}