#pragma once
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int sz = 7;
		string roman = "IVXLCDM";
		int val[] = {1,5,10,50,100,500,1000}; 
		//unordered_map<char,int> map;
		//for(int i = 0; i<7; i++)
		//	map[roman[i]] = val[i];
		int combo = 1,sum = 0, i = 0;
		char cur = s[0]; // start of a num
		while(s[i] != '\0'){
			int curidx = findidx(cur,roman);
			combo = 1; //update combo value
			while(s[++i] != '\0'){ //find a num
				int iidx = findidx(s[i],roman);
				if(iidx == curidx){
					++combo; sum+=val[curidx]; 
					continue;
				}
				else if(iidx > curidx){ // end of a num
					if(combo == 1){
						sum = sum + val[iidx] - val[curidx];
						cur = s[++i];// the new start
					}
					else{
						sum += val[curidx];
						cur = s[i];
					}
					break;
				}
				else{// iidx == curidx
					sum += val[curidx];
					cur = s[i];
					break;
					}
				}
		}
		if(cur != '\0') sum += val[findidx(cur,roman)];
	return sum;
    }
	int findidx(char c, string& s){
		for(int i = 0;i<s.size();i++)
			if(s[i] == c) return i;
		return -1;
	}
};