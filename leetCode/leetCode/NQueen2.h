#pragma once 
#include <string>
#include <vector>
using namespace std;
class Solution {
	int count;
	int terminal;
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    int totalNQueens(int n) {
		if(n == 0) return 0;
		count = 0;
		terminal = (1<<n) - 1; // 1...1--1 x n, maximum possible 1
		vector<vector<int> > bd(n,vector<int>(n,-1));
		dfs(0,0,0);
		return count;
    }
	void dfs(int row, int ld, int rd){
		if(row == terminal){
			count++; return;
		}
		int pos =terminal & (~(row | rd | ld)); // 1's length in pos must within the range in terminal
		while(pos!=0){
			int p = pos & (-pos); // the last 1 in pos
			pos = pos ^ p;// eliminate the last 1
			dfs(row|p,(ld|p)<<1,(rd|p)>>1);
		}	
	}
};
