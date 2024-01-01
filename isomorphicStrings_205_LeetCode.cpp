class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapIsoS;
        map<char, char> mapIsoT;
        bool res = true;
        
        for(int i=0;i<s.size();i++){
            if(mapIsoS.find(s[i]) != mapIsoS.end()){
                if(mapIsoS[s[i]] != t[i]){
                    res = false;
                    break;
                }
            }
            
            else{
                mapIsoS[s[i]] = t[i];
            }    
            
        }
        
        for(int i=0;i<t.size();i++){
            if(mapIsoT.find(t[i]) != mapIsoT.end()){
                if(mapIsoT[t[i]] != s[i]){
                    res = false;
                    break;
                }
            }
            
            else{
                mapIsoT[t[i]] = s[i];
            }    
            
        }
        
        return res;
    }
};