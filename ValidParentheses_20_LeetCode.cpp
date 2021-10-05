#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool isValid(string s) {
    
    int size = s.size();

    stack<char> sk;

    for(int i=0;i<size;i++){

        if(s[i] == '(' || s[i] == '{' || s[i] == '['){

            sk.push(s[i]);
        }

        if(s[i] == ')'){
            if(sk.empty()){
                return false;
            }
            char temp = sk.top();
            sk.pop();
            if(temp != '('){
                return false;
            }
        }

        if(s[i] == '}'){
            if(sk.empty()){
                return false;
            }
            char temp = sk.top();
            sk.pop();
            if(temp != '{'){
                return false;
            }
        }

        if(s[i] == ']'){
            if(sk.empty()){
                return false;
            }
            char temp = sk.top();
            sk.pop();
            if(temp!= '['){
                return false;
            }
        }

    }

    if(!sk.empty()){
        return false;
    }

    return true;

}


int main()

{
    
    string s;
    cin>> s;

    cout<< isValid(s) << endl;

    return 0;
}