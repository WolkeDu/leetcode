#pragma once 
#include <string>
#include <vector>
using namespace std;
class Solution {
	vector<vector<int> > ress;
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<string> > ans;
        if(n == 0) return ans;
		vector<int> path; path.clear(); ans.clear();
		dfs(-1,-1,path,n);
		vector<string> res; res.clear();
		FOR(i,0,ress.size()){
			FOR(j,0,n){
				vector<char> s(n,'.'); s[ress[i][j]] = 'Q';
				res.push_back(string(s.begin(),s.end()));
			}
			ans.push_back(res);res.clear();
		}
		return ans;
    }
	void dfs(int idx, int level, vector<int> path, int n){
		if(idx < 0) {idx++; level++;}
		//path.push_back(idx);
		if( level == n ) {
			 ress.push_back(path);
			return;
		}
		FOR(i,0,n){
			if(isValid(i,path,n)){
				path.push_back(i);
				dfs(i,level+1,path,n);
				path.pop_back();
			}
		}
	}
	bool isValid(int idx, vector<int> path,int n){
		int level = path.size() - 1, offset = 1;
		bool flag = true;
		FOD(i,level,-1){
			if( path[i] == idx || (idx>=offset && path[i] == (idx-offset)) || ((idx+offset) < n && path[i] == (idx + offset)) )
				flag = false;
			offset++;
		}
		return flag;
	}
};