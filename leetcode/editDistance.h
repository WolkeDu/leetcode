#pragma once 
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
template<class T>  T fmax(T& a, T& b ){if(a >= b) return a; return b;} // return the bigger value
template<class T>  T fmin(T& a, T& b ){if(a <= b) return a; return b;} // return the bigger value
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = word1.size(), n = word2.size();
		vector<vector<int> > bd(m+1,vector<int>(n+1,0));
		FOR(i,0,m+1) bd[i][0] = i;
		FOR(i,0,n+1) bd[0][i] = i;
		FOR(i,1,m+1){
			FOR(j,1,n+1){
				int idx1 = i-1, idx2 = j-1;
				int del = bd[i-1][j] + 1;
				int ins = bd[i][j-1] + 1;
				int substt = bd[i-1][j-1] + ((word1[i-1] == word2[j-1])?0:1);
				int min = m + n; 
				min = fmin(del,ins); min = fmin(min,substt);
				bd[i][j] = min;
			}
		}
		return bd[m][n];
    }
};