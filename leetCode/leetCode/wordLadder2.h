// Notice that unordered_set is a hash table which is fast to find and insert, so the algorithm should not try to iterate through it
#pragma once
#include <string>
#include<algorithm>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	#define WHITE 0
	#define BLACK 2
	vector<vector<string> > ress;
	vector<string> dict_v;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		dict.insert(start); dict.insert(end);
		vector<int> que,que_bk;
		vector<string> res;
		vector<vector<int> > adjlist;
		unordered_map<string, int> dict_map;
		unordered_map<int,unordered_set<int> > edgeTo;// store the path from node to node
		vector<int> color_map; // store the color of each nodes in dict
		bool done = false;
		res.clear(); ress.clear(); que.clear();que_bk.clear();dict_v.clear(); dict_map.clear();edgeTo.clear(); color_map.clear();
		adjlist.clear();
		adjlist.resize(dict.size());
		for(unordered_set<string>::iterator iter = dict.begin();iter!=dict.end();iter++){
			dict_map[*iter] = dict_v.size();
			dict_v.push_back(*iter);
			color_map.push_back(0);
		}
		for(int i = 0;i<dict_v.size();++i){
			string cur = dict_v[i];
			for(int j = 0; j<cur.size();j++){
				for(char c = 'a'; c<='z';c++){
					if(cur[j] == c) continue;
					cur[j] = c;
					if(dict_map.count(cur))
						adjlist[i].push_back(dict_map[cur]);
					cur[j] = dict_v[i][j];
				}
			}
		}
		vector<int> adj = adjlist[dict_map[start]];
		color_map[dict_map[start]] = BLACK;
		for(int i = 0;i<adj.size();i++){
			que.push_back(adj[i]);
			color_map[adj[i]] = BLACK;
			edgeTo[adj[i]].insert(dict_map[start]);
		}	
		while(!que.empty()){
			int k = 0, sz = que.size(); 
			while( k < sz ){
				int cur = que[k++];
				adj = adjlist[cur];
				for(int i = 0; i<adj.size();++i){
					
					if(dict_v[adj[i]] == end){ 
						done = true;							 
					}
					if(color_map[adj[i]] != BLACK){
						que_bk.push_back(adj[i]);
						edgeTo[adj[i]].insert(cur);
					}
				}					
			}
			if(done) break;
			for(int i = 0;i<que_bk.size();i++)
				color_map[que_bk[i]] = BLACK;
			que = que_bk;
			que_bk.clear();
		}
		find_path(edgeTo, dict_map[end], dict_map[start], res);
		for(int i = 0;i<ress.size();i++){
			vector<string> tmp1(ress[i].rbegin(),ress[i].rend());
			ress[i] = tmp1;
		}
       		 return ress;
    }
	void find_path(unordered_map<int, unordered_set<int> >& edgeTo, int curidx, int startidx, vector<string>& res){
		res.push_back(dict_v[curidx]);
	    if(curidx == startidx){
		    ress.push_back(res);
			res.pop_back();
		    return;
	    }
		unordered_set<int> pre = edgeTo[curidx];
		auto iter = pre.begin();
		for(auto iter = pre.begin(); iter!=pre.end();iter++){
		    find_path(edgeTo, *iter, startidx, res);
	    }
		res.pop_back();
    }
};
