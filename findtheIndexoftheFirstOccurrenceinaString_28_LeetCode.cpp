class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        
        for(int i=0;i<haystack.size();i++){
            for(int j = 0;j<needle.size();j++){
                if(haystack[i+j] == needle[j]){
                    if(j == needle.size()-1){    
                        index = i;
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(index!=-1){
                return index;
            }
        }
        return index;
    }
};