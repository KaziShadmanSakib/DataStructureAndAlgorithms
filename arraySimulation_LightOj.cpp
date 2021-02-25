#include<bits/stdc++.h>
using namespace std;

vector<int> arra;

void operations1(int num,int n){
  for(int i=0;i<n;i++){
    arra[i] = arra[i] + num;
  }
}

void operations2(int num,int n){
  for(int i=0;i<n;i++){
    arra[i] = arra[i] * num;
  }
}

void operations3(int num,int n){
  for(int i=0;i<n;i++){
    arra[i] = arra[i] / num;
  }
}

void operations4(int y,int z){
  swap(arra[y],arra[z]);
}

void input(int n,int op){
  for(int i=0;i<n;i++){
    int number;
    cin>> number;
    arra.push_back(number);
  }
  while(op--){
    string opCode;
    cin>> opCode;
    if(opCode == "S"){
      int D;
      cin>> D;
      operations1(D,n);
    }
    if(opCode == "M"){
      int D;
      cin>> D;
      operations2(D,n);
    }
    if(opCode == "D"){
      int K;
      cin>> K;
      operations3(K,n);
    }
    if(opCode == "P"){
      int Y,Z;
      cin>>Y>>Z;
      operations4(Y,Z);
    }
    if(opCode == "R"){
      reverse(arra.begin(),arra.end());
    }
  }
}

int main()
{
  int testCase, i=0;
  cin>> testCase;
  while(testCase--){
    arra.clear();
    int n,op;
    cin>>n>>op;
    input(n,op);
    cout<< "Case " << ++i << ":" << endl;
    for(int i=0;i<n;i++){
      cout<< arra[i];
      i==n-1 ? cout<< endl : cout<< " ";
    }
  }
  return 0;
}