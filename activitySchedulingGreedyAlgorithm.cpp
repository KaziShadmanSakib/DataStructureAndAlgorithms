#include<bits/stdc++.h>
using namespace std;

const int MAX_ACT = (int) 10e5+5;

int startTime[MAX_ACT];
int finishTime[MAX_ACT];
int ans[MAX_ACT];
int maxN=0;

bool compare(int a,int b){
  return a > b;
}

/*In the funtion input(),
  When an activity is started, the array startTime records the starting time of that particular time as 1 (As 1 activity has been started in that moment).
  When an activity is finished, the array finishTime records the finishing time of that particular time as -1 (As 1 activity has been finished in that moment)*/
/*maxN holds the last activity finishing time*/

void input(int n){
  memset(startTime,0,sizeof(startTime));
  memset(finishTime,0,sizeof(finishTime));
  for(int i=0;i<n;i++){
    int s,f;
    cin>>s>>f;
    maxN = max(maxN,f);
    startTime[s] = 1;
    finishTime[f] = -1;
  }
} 

/*The ans array keeps track of how many activities are being held in a particular moment (by using cumulative sum)*/
/*The max number of activities overlapping in a particular moment is the min number of Classrooms required to hold all the activities*/
/*That's why I sorted the ans array in decreasing order to find out the max overlapping activity number*/
/*Thus ans[0] holds our required minNumOfClassroom*/

void minNumOfClassroom(int n){
  int cnt = 0;
  for(int i=0;i<=maxN;i++){
    cnt = cnt + finishTime[i] + startTime[i];
    ans[i] = cnt;
  }
  sort(ans,ans+maxN,compare);
}

int main()
{
  int n;
  cin>>n;
  input(n);
  minNumOfClassroom(n);
  cout<< ans[0] << endl;
  return 0;
}