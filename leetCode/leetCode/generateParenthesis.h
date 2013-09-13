#pragma once
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	unordered_set<string> ress;
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ress.clear();
        int level = 2*n;
		string res = "";
		int count = 0;
		dfs(level,1,res + '(');
		vector<string> result(ress.begin(),ress.end());
		return result;
    }
	void dfs(int n, int flag, string res){
		if(res.size() == n){
			if( flag == 0 ){
				ress.insert(res);
			}
			return;
		}
		if(flag < 0 ) return;
		dfs(n,flag+1,res+'(');
		dfs(n,flag-1,res+')');
	}
};