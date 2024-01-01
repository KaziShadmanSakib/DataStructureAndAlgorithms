class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string currentWord;
        vector<string> words;
        bool res = true;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                currentWord+=s[i];
            }
            else{
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        if(!currentWord.empty()){
            words.push_back(currentWord);
        }
        
        if(pattern.size()!=words.size()){
            return false;
        }
       
        map<char,string> wordPattern1;
        map<string, char> wordPattern2;
        for(int i=0;i<pattern.size();i++){
            if(wordPattern1.find(pattern[i]) != wordPattern1.end()){
                if(wordPattern1[pattern[i]] != words[i]){
                    res = false;
                    break;
                }
            }
            else{
                
                wordPattern1[pattern[i]] = words[i];
            }
        }
        
        for(int i=0;i<words.size();i++){
            if(wordPattern2.find(words[i])!=wordPattern2.end()){
                if(wordPattern2[words[i]] != pattern[i]){
                    res = false;
                    break;
                }
            }
            else{
                wordPattern2[words[i]] = pattern[i];
            }
        }
        
        return res;
    }
};