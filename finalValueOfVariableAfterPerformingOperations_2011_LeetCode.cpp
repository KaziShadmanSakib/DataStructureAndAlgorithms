#include<bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int count = 0;

    int n = operations.size();

    for(int i=0;i<n;i++){

        if(operations[i] == "--X" || operations[i] == "X--"){

            count = count - 1;
        }
        if(operations[i] == "++X" || operations[i] == "X++"){

            count = count + 1;
        }
    }

    return count;
}

int main()
{

    int n;
    cin>> n;
    vector<string> op;

    for(int i=0;i<n;i++){

        string sOp;
        cin>> sOp;
        op.push_back(sOp);
    }

    cout<< finalValueAfterOperations(op);

    return 0;
}