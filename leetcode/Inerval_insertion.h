#include <iostream>
#include <vector>
using namespace std;
//  Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
  };
  class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (intervals.empty()){
			intervals.push_back(newInterval);
			return intervals;
		}
		vector<Interval> res;
		bool done = false;
		int start = newInterval.start,end = newInterval.end;
		for(int i = 0;i<intervals.size();i++){
			if(newInterval.end < intervals[i].start){ // non-overlaped, left side
				if(!done){
					res.push_back(Interval(start,end));
					done = true;
				}
				res.push_back(intervals[i]);
			}
			else if(newInterval.start > intervals[i].end){ // non-overlapped, right side
				res.push_back(intervals[i]);
			}
			else{ // must be overlapped
				start = min(start,intervals[i].start);
				end = max(end,intervals[i].end);
			}
		}
		if(!done){
			res.push_back(Interval(start,end));
			done = true;
		}

return res;
    }
	int max(int x, int y){
		return x>y?x:y;
	}
	int min(int x, int y){
		return x<y?x:y;
	}
};