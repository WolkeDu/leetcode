#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include "Solution.h"
using namespace std;
int main(){
//Point pt(-1,1),pt2(0,0),pt3(1,-1);
//vector<Point> pts;
//pts.push_back(pt);pts.push_back(pt2);pts.push_back(pt3);
string strs[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
vector<string> strsvec(strs,strs+13);
Solution demo;
cout<<demo.evalRPN(strsvec)<<endl; 
//template<class T>
//int ans = demo.maxPoints(pts);
//cout<<ans<<endl;
//return 0;
}
