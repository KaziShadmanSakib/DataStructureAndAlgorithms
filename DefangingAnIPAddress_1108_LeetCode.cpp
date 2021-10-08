#include<bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) {
    string newAdd = "";

    for(int i=0;i<address.size();i++){

        if(address[i] == '.'){

            newAdd = newAdd + "[.]";

        }

        else{

            newAdd = newAdd + address[i];

        }

    }
    return newAdd;
}

int main()
{

    string address;
    cin>> address;

    cout<< defangIPaddr(address) << endl; 
    return 0;
}