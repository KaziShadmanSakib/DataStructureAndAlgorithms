class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string currentWord;
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                currentWord += s[i];
            }
            else if(!currentWord.empty()){
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        if(!currentWord.empty()){
            words.push_back(currentWord);
        }
        
        reverse(words.begin(),words.end());
        
        string ans = "";
        for(int i=0;i<words.size();i++){
            if(i==words.size()-1){
                ans+= words[i];
            }
            else{
                ans+= words[i];
                ans+= ' ';
            }
        }
        return ans;
    }
};