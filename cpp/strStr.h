#include <vector>
using namespace std;
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
		vector<int> next;
		next.clear();
		char* res;
		get_nextval(needle, next);
		int i = 0,j = 0;
		while( haystack[i] != '\0' && needle[j] != '\0'){
			if(j == -1 || haystack[i] == needle[j]){
				i++;j++;
			}
			else
				j = next[j];
		}
		if(needle[j] == '\0')
			 return &haystack[i-j];
		else
			return NULL;
   };

   void get_nextval(const char *T,  vector<int>& next)
  {
	int j = 0, k = -1;
	next.push_back(-1);
	while ( T[j] != '\0' ) 
	{ 
		if( k == -1 || T[j] == T[k] ) 
		{  
			++j; ++k; 
			if(T[j] != T[k])
				next.push_back(k);
      		else
				next.push_back(next[k]);
		}//if 
		else
		{ 
			k = next[k];
		} 
	}
	next.pop_back();
 }

};