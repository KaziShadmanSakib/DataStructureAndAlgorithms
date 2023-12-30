class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        string currentWord;
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                currentWord+=s[i];
            }
            else if(!currentWord.empty()){
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        
        if(!currentWord.empty()){
            words.push_back(currentWord);
        }
        
        return words.back().size();
    }
};