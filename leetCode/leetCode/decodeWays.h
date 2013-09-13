// First tried dfs, time limit exceeded. Then consider dynamic programming. Just like the climbing stairs problem, but we need to consider if the subset is acceptable.
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	//vector<vector<char> > ress;
	int count;
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s == "") return 0;
		unordered_map<string,char> map;
		vector<char> res;
		int i = 0; count = 0; map.clear();res.clear();
		string s0="";
		for(char c = 'A'; c<='I';c++){
			char tmp = ++i + '0';
			s0 = s0 + tmp;
			map[s0] = c;
			s0 = "";
		}
		i = 0;
		for( char c = 'J'; c<= 'S'; c++){
			char tmp = i++ + '0';
			s0 = "1";
			s0 += tmp;
			map[s0] = c;
			s0.clear();
		}
		i = 0;
		for( char c = 'T';c<='Z';c++){
			char tmp = i++ + '0';
			s0 = "2";
			s0 = s0 + tmp;
			map[s0] = c; 
		}
		/*                  core code             */
		int* val = new int[s.size()];
		memset(val,0,sizeof(int)*s.size());
		if(delta(0-1,1,s,map))
			val[0] = 1;
		if(delta(1-1,1,s,map))
			val[1] = val[1] + val[0];
		if(delta(1-2,2,s,map))
			val[1] = val[1] + 1;
		for(int i = 2; i<s.size();i++){
			if(delta(i-1,1,s,map))
				val[i] += val[i-1];
			if(delta(i-2,2,s,map))
				val[i] += val[i-2];
		}
		count = val[s.size()-1];
		return count;
    }
	bool delta(int idx, int step, string& str, unordered_map<string, char>& map){
		if(map.count(str.substr(idx+1,step)))
			return true;
		else return false;
	}
};