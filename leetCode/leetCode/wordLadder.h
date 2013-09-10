// Notice that unordered_set is a hash table which is fast to find and insert, so the algorithm should not try to iterate through it
#pragma once
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		queue<string> que,que_bk;
		
		unordered_set<string> visited;
		int count = 1;
		que.push(start);
		while(!que.empty() && dict.size()>0){
			while(!que.empty()){
				string cur = que.front();
				que.pop();
				for(int i = 0;i<cur.size();++i){
					for(int j ='a'; j<='z';j++){
						if(j == cur[i]) continue;
						string tmp = cur;
						tmp[i] = j;
						if(tmp == end) 
							return count+1;
						if(dict.count(tmp) && !visited.count(tmp)){
							que_bk.push(tmp);
							visited.insert(tmp);
						}
					}
				}
			}
			count++;
			swap(que,que_bk);
		}
        return 0;  
    }

};