class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int previVal = -1000;
        int array[10000];
        int size = 0;
        for(int i=0;i<nums.size();i++){
            if(previVal != nums[i]){
                previVal = nums[i];
                array[size++] = nums[i];
                printf("%d ", nums[i]);
            }
            else{
                continue;
            }
        }
        
        nums.clear();
        for(int i=0;i<size;i++){
            nums.push_back(array[i]);
        }
        
        return nums.size();
    }
};