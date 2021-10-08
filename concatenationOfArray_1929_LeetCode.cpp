#include<bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();

    for(int i=0;i<n;i++){

        ans.push_back(nums[i]);


    }

    int count = 0;
    for(int i=n;i<2*n;i++){
        ans.push_back(nums[count++]);
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

    vector<int> ans = getConcatenation(nums);

    for(int i=0;i<ans.size();i++){
        cout<< ans[i] << " ";
    }

    cout<< endl;

    return 0;
}