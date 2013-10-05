#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size() == 0) return 0;
		if(height.size() == 1) return height[0];
		vector<int> val,indices;
		val.clear();indices.clear();
		int maxArea = INT_MIN;
		val.push_back(height[0]);indices.push_back(0);
		FOR(i,1,height.size()){
			int lastidx = -1;
			while(!val.empty() && val.back() > height[i]){
				lastidx = indices.back();
				int Area = val.back() * (i - lastidx);
				if(Area > maxArea) maxArea = Area;
				val.pop_back();indices.pop_back();
			}
			if(!val.empty() && val.back() == height[i]) continue;
			else{
				val.push_back(height[i]); 
				if(lastidx != -1)
					indices.push_back(lastidx);
				else indices.push_back(i);
			}
		}
		int idx  = height.size();
		while(!val.empty()){
				int Area = val.back() * (idx - indices.back());
				if(Area > maxArea) maxArea = Area;
				val.pop_back();indices.pop_back();				
		}
		return maxArea;
    }
};