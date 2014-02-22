#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Solution {
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = board.size();
		vector<vector<int> > cords;
		vector<int> cord;
		cords.clear(); cord.clear();
		FOR(i,0,n){
			FOR(j,0,n){
				if(board[i][j] == '.'){
					cord.push_back(i); cord.push_back(j);
					cords.push_back(cord); cord.clear();
				}
			}
		}
		bool ans = dfs(0,cords,board);
    }
	bool dfs(int level, vector<vector<int> >& cords, vector<vector<char> >& board){
		if(level == cords.size()) 
			return true;
		int x = cords[level][0],y = cords[level][1];
		for(char c = '1'; c <= '9'; ++c){
			if(isValid(x,y,c,board)){
				board[x][y] = c;
				if(dfs(level+1, cords, board))
					return true;
				else 
					board[x][y] = '.';
			}
		}
		return false;
	}
	bool isValid(int x, int y, char val, vector<vector<char> >& board){
		// x,y in range [0,n-1]
		int n = board.size();
		FOR(i,0,n){
			if(board[x][i] == val)
				return false;
		}
		FOR(i,0,n){
			if(board[i][y] == val)
				return false;
		}
		int base_x = x/3, base_y = y/3;
		FOR(i,0,3){
			FOR(j,0,3){
				if(board[base_x*3 + i][base_y*3 + j] == val)
					return false;
			}
		}
		return true;
	}
};
