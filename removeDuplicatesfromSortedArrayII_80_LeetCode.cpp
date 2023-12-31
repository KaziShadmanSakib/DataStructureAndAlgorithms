class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> removeDup;
        
        for(int i=0;i<nums.size();i++){
            removeDup.insert({nums[i], 0});
        }
        
        for(int i=0;i<nums.size();i++){
            if(auto search = removeDup.find(nums[i]); search != removeDup.end()){
                search->second++;
            }
        }
        
        nums.clear();
        map<int,int> :: iterator iter;
        for(iter = removeDup.begin();iter!=removeDup.end();iter++){
            int count = 2;
            if((*iter).second >=2){
                while(count != 0){
                    nums.push_back((*iter).first);
                    count--;
                }
            }
            else{
                nums.push_back((*iter).first);
            }
        }
        return nums.size();
    }
};