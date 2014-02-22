#include <vector>
#include <map>
using namespace std;
  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
vector<double> cosvec = precomp(0);
vector<double> sinvec = precomp(1);
int maxp=0;
for(int i = 0; i<180; ++i){
    map<int,int> m0;
    for(int j = 0;j<points.size();++j){
       int rho = roundx(points[j].x*sinvec[i] + points[j].y*cosvec[i]);
       m0[rho]++; 
    }
    map<int,int>::iterator it;
    for(it = m0.begin();it!=m0.end();it++){
        maxp = maxp > it->second?maxp:it->second; 
    }
}
    return maxp;
    }
 vector<double> precomp(bool flag){
    vector<double> ans;
    for(int i = 0; i<180;++i){
        if(flag)
            ans.push_back(sin(double(i)*3.141592654/180));
        else
            ans.push_back(cos(double(i)*3.141592654/180));
    }
    return ans;
}
int roundx(double x){
    return floor(x+0.5);
}
};

