#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		int l = s1.size(),m = s2.size(),n = s3.size();
		if(l+m != n) return false;
		vector<vector<bool> > tab1(l+1,vector<bool>(m+1,false)),tab2(l+1,vector<bool>(m+1,false)); // l plus 1, index start from 1
		tab1[0][0] = true; tab2[0][0] = true;
		FOR(k,1,n+1){
			for(int i=0;i<=k && i< l+1;++i){
				for(int j = 0; j<=k && j<m+1;++j){
					if(i==0 && j==0) continue;
					if(i >0 && j > 0 && s1[i-1] == s2[j-1]){
						if(s1[i-1] == s3[k-1]) tab2[i][j] = tab1[i-1][j] || tab1[i][j-1];
					}
					else if(i>0 && s1[i-1] == s3[k-1])
						tab2[i][j] = tab1[i-1][j];
					else if(j>0 && s2[j-1] == s3[k-1])
						tab2[i][j]= tab1[i][j-1];
				}
			}
			tab1 = tab2;
			tab2.resize(l+1,vector<bool>(m+1,false));
			tab2[0][0] = true;
		}
		return tab1[l][m];
    }
};