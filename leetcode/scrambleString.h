#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
	    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
			if(s1.size() == 0 || s1.size() != s2.size()) return false;
			if(s1 == s2) return true;
			int n = s1.size(); 
			FOR(i,0,n-1){
				string str11 = s1.substr(0,i+1);
				string str12 = s1.substr(i+1);

				string str21 = s2.substr(0,i+1);
				string str22 = s2.substr(i+1);
				if(isEqual(str11,str21)){
					if(isScramble(str11,str21) && isScramble(str12,str22))
						return true;
				}
//				string str11 = s1.substr(0,i+1);
//				string str12 = s1.substr(i+1);
				 str21 = s2.substr(n-1-i);
				 str22 = s2.substr(0,n-1-i);
				if(isEqual(str11,str21)){
					if(isScramble(str11,str21) && isScramble(str12,str22))
						return true;
				}
			}
			return false;
    } 
		bool isEqual(string s1, string s2){
			sort(s1.begin(),s1.end());
			sort(s2.begin(),s2.end());
			FOR(i,0,s1.size())
				if(s1[i] != s2[i])
					return false;
			return true;
		}
};