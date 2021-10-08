#include<bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();

    for(int i=0;i<n;i++){

        ans.push_back(nums[nums[i]]);

    }

    return ans;
}

int main()
{

    int n;
    cin>> n;
    vector<int> nums;

    for(int i=0;i<n;i++){

        int val;
        cin>> val;
        nums.push_back(val);
    }

    vector<int> ans = buildArray(nums);

    for(int i=0;i<ans.size();i++){
        cout<< ans[i] << " ";
    }

    cout<< endl;

    return 0;
}