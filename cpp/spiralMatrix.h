#pragma once
#include <vector>
#include <algorithm>
#include <set>;
using namespace std;
class Solution {
public:
	#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case
		vector<int> res;
		if(matrix.size() == 0) return res;
		res.clear();
		int m = matrix.size(), n = matrix[0].size();
		int range = ((m<n?m:n) - 1)/2;// note: the range must be considered carefully
		FOR(k,0,range+1){ 
			if(k == n/2 ){
				FOR(i,k,m-k)
					res.push_back(matrix[i][k]);
				break;
			}
			else if(k == m/2){
				FOR(i,k,n-k)
					res.push_back(matrix[k][i]);
				break;
			}
			FOR(i,k,n-1-k){ //up
				res.push_back(matrix[k][i]);
			}
			FOR(i,k,m-1-k){//right
				res.push_back(matrix[i][n-1-k]);
			}
			FOR(i,k,n-1-k){//down
				res.push_back(matrix[m-1-k][n-1-i]);
			}
			FOR(i,k,m-1-k){//left
				res.push_back(matrix[m-1-i][k]);
			}
		}
		return res;
    }
};