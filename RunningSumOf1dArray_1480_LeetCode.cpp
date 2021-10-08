#include<bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> runningSum;
    int n = nums.size();

    int count = 0;

    for(int i=0;i<n;i++){
        count = count + nums[i];
        runningSum.push_back(count);

    }

    return runningSum;
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

    vector<int> ans = runningSum(nums);

    for(int i=0;i<ans.size();i++){

        cout<< ans[i] << " ";
    }
    
    cout<< endl;
    return 0;
}