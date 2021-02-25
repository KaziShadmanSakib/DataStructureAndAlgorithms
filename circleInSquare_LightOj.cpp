#include<bits/stdc++.h>
using namespace std;

#define pi 2*acos(0.0)

int main()
{
  int testCase,i=0;
  cin>> testCase;
  while(testCase--){
    double r,diameter,areaOfCircle,areaOfSquare;
    cin>> r;
    diameter = 2 * r;
    areaOfSquare = diameter * diameter;
    areaOfCircle = pi * (r*r);
    double areaofShadedArea;
    areaofShadedArea = areaOfSquare - areaOfCircle;
    printf("Case %d: %.2lf\n",++i,areaofShadedArea);
  }
  return 0;
}