class Solution {
public:
    bool isPalindrome(string s) {
        string rebaseString = "";
        bool ans = true;
        for(char c : s){
            if(isalnum(c)){
                rebaseString += tolower(c);   
            }
        }
        cout<< rebaseString << endl;
        for(int i=0;i<rebaseString.size()/2;i++){
            int j = rebaseString.size() -1 - i;
            if(rebaseString[i] != rebaseString[j]){
                ans = false;
                break;
            }
            
        }
        
        return ans;
    }
};