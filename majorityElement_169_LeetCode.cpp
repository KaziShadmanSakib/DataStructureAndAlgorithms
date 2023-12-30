class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> majorityMap;
        map <int, int> :: iterator itr;
        
        for(int i=0;i<nums.size();i++){
            majorityMap.insert({nums[i], 0});
        }
        
        for(int i=0;i<nums.size();i++){
            if(auto search = majorityMap.find(nums[i]); search!=majorityMap.end()){
                search->second++;
            }
        }
        
        int maxID= -100000;
        int maxCount = -100000;
        for(itr= majorityMap.begin();itr!=majorityMap.end();itr++){
            if(maxCount < (*itr).second){
                maxID = (*itr).first;
                maxCount= (*itr).second;
            }
        }
        
        return maxID;
    }
};