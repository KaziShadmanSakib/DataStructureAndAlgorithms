#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;

        for(int i=0;i<nums.size()-1;i++){

            for(int j=1;j<nums.size();j++){

                if(nums[i] == nums[j] && i<j){

                    ans += 1;

                }

            }

        }
        return ans;
    }
};