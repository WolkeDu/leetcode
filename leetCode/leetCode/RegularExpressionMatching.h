// note that x* is a whole part
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		bool ans = findMatch(s,0,p,0);
        return ans;
    }
	bool findMatch(const char*& s, int m, const char*& p, int n){
		if(p[n] == '\0') return s[m] == '\0';
		if(p[n+1] != '*')
			return ((s[m] == p[n])|| (p[n] == '.' && s[m] != '\0')) && findMatch(s, m + 1, p, n + 1);
		while((s[m] == p[n]) || (p[n] == '.' && s[m]!='\0')){
			if(findMatch(s,m , p, n + 2)) 	return true;
			m++;
		}
		return findMatch(s,m,p,n+2);
	};
};