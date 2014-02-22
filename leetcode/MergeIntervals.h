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
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(intervals.empty()) return intervals;
       vector<Interval> res;
	   res.clear();
	   Interval cur;
	   QS(intervals,0,intervals.size()-1); // sort the intervals
	   // find the min and max index
	   int start = intervals[0].start,end = intervals[0].end;
	   for(int i = 0;i<intervals.size();i++){
		   if( end < intervals[i].end)
			   end = intervals[i].end;
	   }
	   int range = end - start +1,count = 0;
	   int* au = new int[range]; //auxiliary array
	   memset(au,0,range*sizeof(int));
	   for(int i =0;i<intervals.size();i++)
	   {
		  int cur_i_s = intervals[i].start - start; //idx
		  int cur_i_e = intervals[i].end - start;
		// search each intervals
		   if(au[cur_i_s] != 0 ){
				// coverage exists
			   int i_s =  res[count-1].start - start;
			   int i_e =  res[count-1].end - start;
			   if (cur_i_e > i_e){
				   set_val(au, i_e+1,cur_i_e,count);
				   res[count-1].end = intervals[i].end;
			   }
		   
		   }
		   else{
			   res.push_back(intervals[i]); // push new interval
			   count++;
			   set_val(au,cur_i_s,cur_i_e,count);
		   }
		//   for(int t = 0;t<range;t++)
		//	   cout<<*(au+t)<<" ";
		  // cout<<endl;
	   }
	   return res;
	}
	void QS(vector<Interval> &intervals, int lf, int rt){
	if(lf>=rt) return;
	int i = lf;
	int j = rt+1;
	int key = intervals[lf].start;
	while(1){
		while(intervals[++i].start <= key)
			if(i == rt) break;
		while(intervals[--j].start > key)
			if(j == lf) break;
		if(i>=j) break;
		swap(intervals,i,j);
	
	}
	swap(intervals,lf,j);
	QS(intervals,lf,j-1);
	QS(intervals,j+1,rt);
	}
	void swap(vector<Interval> &intervals,int i, int j){
		Interval tmp = intervals[i];
		intervals[i] = intervals[j];
		intervals[j] = tmp;	
	}
	void set_val(int* au,int start,int end, int val){
		for(int i = start;i <= end; i++){
		*(au+i) = val;
		}
	}

};