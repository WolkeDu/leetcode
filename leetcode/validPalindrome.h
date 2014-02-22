#pragma once
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s == "") return true;
		int sz = s.size();
		if(sz == 1) return true;
		int i = 0, j = sz-1;
		while(1){
			while(s[i] < '0' || s[i]>'z' || (s[i] > 'Z' && s[i] < 'a') || (s[i] > '9' && s[i] < 'A')){
				++i;
				if(i==sz) return true;
			}
			while(s[j] < '0' || s[j]>'z' || (s[j] > 'Z' && s[j] < 'a') || (s[j] > '9' && s[j] < 'A')){
				--j;
				if(j == 0) return true;
			}
			if(i>j) return true;
			if(s[i] >= 'a') s[i] = s[i] - 32; // 'a' - 'A' = 32
			if(s[j] >= 'a') s[j] = s[j] - 32; // 'a' - 'A' = 32
			if(s[i] != s[j]){
				return false;
			}
			++i;--j;
		
		}
    }
};