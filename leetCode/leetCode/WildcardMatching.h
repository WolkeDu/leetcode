#include <vector>
using namespace std;
class Solution {
public:
	#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
    bool isMatch(const char *s, const char *p) {
    	if(*p == '\0') return *s == '\0';
		int i = 0,wid = 0, np = 0;
		const char* tmp = s;
		while(*tmp++ != '\0') wid++;
		tmp = p; while(*tmp != '\0'){if(*tmp != '*') np++; tmp++;}
		if(np > wid) return false;
		bool flag = 1;
		wid++;// use 1 to wid to represent the characters in s
		vector<vector<bool> > table(2, vector<bool>(wid,false));
		table[0][0] = true;
		while(*(p) != '\0'){
			if(*p != '*' && *p != '?'){
				//i++;
				FOR(k,1,wid){
					table[flag][k] = table[!flag][k-1] && (*p == *(s+k-1));
				}
				table[flag][0] = false;
			}
			else if(*p == '?'){	
				FOR(k,1,wid){
					table[flag][k] = table[!flag][k-1];
				}
				table[flag][0] = false;
			}
			else{// *p == '*'
				while(*p == '*') p++;p--;
				table[flag][0] = table[!flag][0];
				int  t = 0;
				FOR(k,t,wid){
					if(table[!flag][k]) break;
					else table[flag][k] = false;
					t++;
				}
				FOR(k,t,wid){
					table[flag][k] = true;
				}
			}
			p++; flag = !flag;
		}
		return table[!flag][wid-1];
    }
};
