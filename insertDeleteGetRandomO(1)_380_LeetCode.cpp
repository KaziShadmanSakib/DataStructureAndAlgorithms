class RandomizedSet {
public:
    vector<int> randomSet;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool ans = true;
        auto search = find(randomSet.begin(),randomSet.end(), val);
        if(search != randomSet.end()){
            ans = false;
        }
        else{
            randomSet.push_back(val);
        }
        return ans;
    }
    
    bool remove(int val) {
        bool ans = false;
        auto search = find(randomSet.begin(),randomSet.end(), val);
        if(search != randomSet.end()){
            randomSet.erase(std::remove(randomSet.begin(), randomSet.end(), val), randomSet.end());
            ans = true;
        }
        else{
            ans = false;
        }
        return ans;
        
    }
    
    int getRandom() {
        int randomVal = rand() % randomSet.size();
        return randomSet[randomVal];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */