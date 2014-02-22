#pragma once
#include <vector>
#include <algorithm>
#include <set>;
using namespace std;
class Solution {
public:
	set<vector<int> > ans;
	#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case
		vector<vector<int> > ress;
        if(num.size() == 0) return ress;
		vector<int> res;
		ress.clear();ans.clear(); res.clear();
		sort(num.begin(),num.end());
		dfs(0,-1,target,res,num);
		set<vector<int> >::iterator it = ans.begin();
		FOR(i,0,ans.size())
		{
			ress.push_back(*it);
			it++;
		}
		return ress;
    }
	bool dfs(int sum, int idx, int& target,vector<int> res, vector<int>& num){
		if(idx == num.size()) return -1;
		bool flag = false;
		vector<int> tmp = res;
		int next = idx+1;
		FOR(i,next,num.size()){

			sum += num[i];
			res.push_back(num[i]);
			if(sum == target){
				ans.insert(res);
				return true;
			}
			else if(sum > target) return false;
			else{
				flag = dfs(sum,i,target,res,num);
			}
			sum -= num[i];
			res.pop_back();
		}
	};
};