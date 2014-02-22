#pragma once
#include <vector>
#include <algorithm>
#include <set>;
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(n<=1) return 0;
        int step = 0;
        vector<int> vec,indices;
        int max = n-1,cur_max = 0,next_max = 0; // flag
        vec.push_back(A[0]); indices.push_back(0);
        while(!vec.empty()){
          step++;next_max = cur_max;
             FOR(i,0,vec.size()){ //i is the index of vector vec
				 int idx = vec[i] + indices[i];
				 if (idx >= max)
					 return step;
				 if(idx > next_max)
					 next_max = idx;
			 }
			 vec.clear();indices.clear();
			 FOR(i,cur_max+1,next_max+1){ // i is the index of array A
				vec.push_back(A[i]);indices.push_back(i);
			 }
      }
      return -1;
    }
};