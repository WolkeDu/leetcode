#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() <= 1) return s;
		string ans = "";
        int n = s.size(), start = 0, end = 0;
        vector<vector<bool> > map(n,vector<bool>(n,false));
        bool flag;
        for(int i = 0; i < n; ++i){
            map[i][i] = true;
        }
        for(int i = 0;i<n-1;++i){
            if(s[i] == s[i+1]){
                map[i][i+1] = true;
                start = i; end = i + 1;
            }
        }
        int k=0;
        for(k=2;k<n;k++){
            for(int i=0;i<n-k;i++){
				if(s[i] == s[i+k]){
					if(map[i+1][i+k-1]==1){
						map[i][i+k] = 1;
						flag = true;
						start = i; end = i+k;
					}
				}
            }
            if(flag == false) break;
            flag = true;
        }
        ans = s.substr(start,end - start + 1);
        return ans;
    }
};