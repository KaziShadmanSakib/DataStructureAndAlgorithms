class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        bool ans = true;
        for(int i=0;i<t.size();i++){
            if(t[i] != s[j]){
                continue;
            }
            else{
                j++;
            }
        }
        cout<< j;
        if(j == s.size()){
            return true;
        }
        else{
            false;
        }
        return 0;
    }
};