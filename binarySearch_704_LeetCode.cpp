#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int high = nums.size()-1;
    int low = 0;
    int foundAt = -1;
    int mid;
    while(low<=high){
        mid = (high+low)/2;
        if(nums[mid] > target){
            high = mid - 1;
        }

        else if(nums[mid] < target){
            low = mid + 1;
        }

        else{
            return mid;
        }

    }

    return foundAt;
}

int main()
{
    int n,target;
    vector<int> nums;

    cin>> n;

    for(int i=0;i<n;i++){
        int number;
        cin>> number;
        nums.push_back(number);
    }

    cin>> target;

    cout<< search(nums,target) << endl;

    return 0;
}