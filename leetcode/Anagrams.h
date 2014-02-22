#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> res;
		if(strs.size() == 0) return res;
		unordered_map<string,int> map;
		map.clear(); res.clear();
		for( int i = 0; i<strs.size();i++){
			string st = strs[i];
			sort(st.begin(),st.end());
			if(!map.count(st)) map[st] = i;
			else{
				if(map[st] >= 0)
					res.push_back(strs[map[st]]);
				res.push_back(strs[i]);
				map[st] = -1;
			}
		}
		return res;
    }
};