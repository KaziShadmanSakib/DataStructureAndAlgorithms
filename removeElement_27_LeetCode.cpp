class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, res;
        for (int i=0;i<nums.size();i++){
            if(nums[i] == val){
                nums[i] = NULL;
                k++;
            }
        }
       
        sort(nums.begin(), nums.end(), greater<int>());
        
        /*for (int i=0;i<nums.size();i++){
            printf("%d ", nums[i]);
        }*/
        
        res = nums.size() - k;
        return res;
    }
};