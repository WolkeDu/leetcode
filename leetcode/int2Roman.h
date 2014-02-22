#pragma once
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
		if (num <= 0) return "";
		string roman[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
		int val[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
		string res = "";
		vector<int> indices;
		for(int i = 12;i>=0;--i){
			while(num >= val[i]){
				num = num - val[i];
				indices.push_back(i);
			}
			if(num == 0) break;
		}
		for(int i = 0; i < indices.size();i++){
			res += roman[indices[i]];
		}
		return res;
    }
};