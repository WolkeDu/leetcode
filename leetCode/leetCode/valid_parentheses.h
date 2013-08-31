#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty()) return true;
        int len = s.length();
        vector<char> st;
        st.push_back(s[0]);
        for(int i = 1;i<len;i++)
        {
			if(s[i] == ')' && st.back() == '(')
				st.pop_back();
			else if(s[i] == '}' && st.back() == '{') 
				st.pop_back();
			else if(s[i] == ']' && st.back() == '[')
                st.pop_back();
            else             
                st.push_back(s[i]);
            
        }
        if(st.empty()) return true;
        else return false;
    }
};