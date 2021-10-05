#include<bits/stdc++.h>
using namespace std;

int romanToInteger(string s){
    int total = 0;
    int sSize = s.size();
    for(int i=0;i<sSize;i++){
        if(s[i] == 'I' && s[i+1] != 'V' && s[i+1] != 'X'){
            total = total + 1;
        }

        if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
            total = total-1;

        }

        if(s[i] == 'V'){
            total = total + 5;
        }

        if(s[i] == 'X' && s[i+1] != 'L' && s[i+1] != 'C'){
            total = total + 10;
        }

        if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
            total = total - 10;
        }

        if(s[i] == 'L'){
            total = total + 50;
        }

        if(s[i] == 'C' && s[i+1] != 'D' && s[i+1] != 'M'){
            total = total + 100;
        }

        if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
            total = total - 100;
        }

        if(s[i] == 'D'){
            total = total + 500;
        }

        if(s[i] == 'M'){
            total = total + 1000;
        }

    }

    return total;
}


int main()

{

    string s;
    cin>> s;

    cout<< romanToInteger(s) << endl;
    return 0;
}