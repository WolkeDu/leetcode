#pragma once
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
	vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
			ans.push_back("");
			return ans;
		}
		unordered_map<char,string > map;
		//vector<string> ans;
		map.clear(); ans.clear();
		char c = 'a';
		string s = "";
		FOR(i,2,7){
			FOR(j,0,3){	s += (c + j); }
			map['0'+i] = s; c = c + 3; s = "";
		}
		map['7'] = "pqrs"; map['8'] = "tuv"; map['9'] = "wxyz"; map['0'] = " ";
		dfs(digits,0,s,map);
		return ans;
    }
	void dfs(string& digits, int n, string s, unordered_map<char,string >& map){
		if(n == digits.size()){
			ans.push_back(s);
			return;
		}
		string p = map[digits[n]];
		FOR(i,0,p.size()){
			dfs(digits,n+1,s+p[i],map);
		}
	}
};