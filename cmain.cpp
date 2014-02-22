#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include "Max_Points_on_a_Line.h"
using namespace std;
int main(){
Point pt(0,0),pt2(1,0),pt3(0,0);
vector<Point> pts;
pts.push_back(pt);pts.push_back(pt2);pts.push_back(pt3);
Solution demo;
int ans = demo.maxPoints(pts);
cout<<ans<<endl;
return 0;
}
