#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool isValid(string s) {
    stack <char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
            continue;
        }
        if(st.empty()){
            return false;
        }
        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            char brac = st.top();
            st.pop();
            if(s[i]== ')' && brac != '('){
                return false;
            }
            if(s[i]== '}' && brac != '{'){
                return false;
            }
            if(s[i]== ']' && brac != '['){
                return false;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    else{
        return true;
    }
}


int main()

{
    
    string s;
    cin>> s;

    cout<< isValid(s) << endl;

    return 0;
}