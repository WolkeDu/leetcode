#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
class Solution{
    public:
    struct cmp{
        bool operator()(Point p1, Point p2){
            return p1.x < p2.x;
        }
    }cmpobj;
    int maxPoints(vector<Point> &points) {
        sort(points.begin(),points.end(),cmpobj);
//        for(int i = 0; i<points.size(); ++i){
//           cout<< points[i].x<<" "<<points[i].y<<endl; 
        map<double,int> m0;
        m0[NAN] = 0;
        for(int i = 0; i<points.size()-1; ++i){
            for(int j = i; j < points.size(); ++i){
               int deltax = points[i].x - points[j].x; 
               int deltay = points[i].y - points[j].y;
               if(deltax == 0){ m0[NAN]++; continue;}
               double gradient = deltay/deltax;

            }
        }
        return 0;
    }
};
