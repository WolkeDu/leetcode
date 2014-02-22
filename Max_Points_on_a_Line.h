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
    int epsilon = 1000000;
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0) return 0;
        map<int,int> m0;
        int flag_max,flag_dup;
        vector<int> maxp(points.size()-1,0);
        for(int i = 0; i<points.size()-1; ++i){
            m0.clear(); flag_max= 0; flag_dup = 0;
            for(int j = i+1; j < points.size(); ++j){
                int deltax = points[i].x - points[j].x; 
                int deltay = points[i].y - points[j].y;
                if(deltax == 0){ 
                    if(deltay == 0){ 
                        flag_dup++; continue;
                    }
                    flag_max++; continue;
                }
                int gradient = epsilon*deltay/deltax;
                 m0[gradient]++;
            }
            map<int,int>::iterator it = m0.begin();
            for(;it!=m0.end();++it){
                maxp[i] = maxp[i] >= it->second?maxp[i]:it->second;
            }
            maxp[i] = maxp[i] > flag_max?maxp[i]:flag_max;
            maxp[i] += flag_dup;
        }
        int tmp_m = 0;
        for(int i = 0; i<maxp.size();++i){
            tmp_m = tmp_m > maxp[i]?tmp_m:maxp[i];
        }
        return tmp_m+1;
    }
};
