#pragma once
#include <vector>
#include <algorithm>
#include <set>;
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 1) return 0;
        int max = 0, idx = -1;
        for(int i = 0; i<n; ++i){
            if(max < A[i]){
                max = A[i];
                idx = i;
            }
        }
        int Area = 0;
		//from left to max
        vector<int> vals; vals.push_back(0);
        for(int i = 0; i<=idx; ++i){
            if(A[i] < vals[0]) vals.push_back(A[i]);
            else {
                Area += vals[0]*(vals.size()-1);
                for(int i=1; i<vals.size(); ++i)
                    Area -= vals[i];
                vals.clear(); vals.push_back(A[i]);
            }
        }
		//from right to max
        vals.clear();vals.push_back(0);
        for(int i = n -1; i>= idx; --i){
            if(A[i] < vals[0]) vals.push_back(A[i]);
            else {
                Area += vals[0]*(vals.size()-1);
                for(int i=1; i<vals.size(); ++i)
                    Area -= vals[i];
                vals.clear(); vals.push_back(A[i]);
            }           
        }
     return Area;   
    }
};