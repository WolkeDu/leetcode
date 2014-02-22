//note the memory cost of final ans can be huge.So A global ans variable is not feasible. 
#pragma once
#include <vector>
#include <algorithm>
#include <unordered_set>;
using namespace std;
class Solution {
public:
	#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> >ans;
		sort(candidates.begin(),candidates.end());
		vector<int> res;
        if( candidates.size() == 0 )return ans; // check input
		ans = dfs(target,candidates);
		return ans;
    }
	 vector<vector<int> > dfs(int val, vector<int> & candidates){
		 vector<vector<int> >res;
		for(int i = 0;i < candidates.size() && candidates[i]<=val;i++){
			if( val == candidates[i]){
					vector<int> k; k.push_back(candidates[i]);
					res.push_back(k);
			}
			else if( val > candidates[i]){
				vector<int> newcand(candidates.begin() + i, candidates.end()); 
				vector<vector<int> > ret = dfs(val - candidates[i],newcand); // recursion
				FOR(j,0,ret.size()){ // combine low level results with current level.
					ret[j].insert(ret[j].begin(),candidates[i]);
					res.push_back(ret[j]);
				}
			}
		}
		return res;
	}
};