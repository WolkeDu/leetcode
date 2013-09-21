//dp
#pragma once 
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m = obstacleGrid.size(),n = obstacleGrid[0].size();
		if( m == 0 || n == 0 || obstacleGrid[0][0] == 1) return 0;
		vector<vector<int> > bd(m, vector<int>(n,0));
		bd[0][0] = 1; //start
		FOR(i,0,m){
			FOR(j,0,n){
				if(obstacleGrid[i][j] == 1 || (i == 0 && j == 0)) continue;
				if(j>0) bd[i][j] += bd[i][j-1];
				if(i>0) bd[i][j] += bd[i-1][j];
			}
		}
		return bd[m-1][n-1];
    }
};