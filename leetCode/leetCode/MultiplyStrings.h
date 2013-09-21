#pragma once 
#include <string>
#include <vector>
using namespace std;
class Solution {
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1 == "" || num2 == "") return "0";
		vector<char> vec1(num1.rbegin(),num1.rend());
		vector<char> vec2(num2.rbegin(),num2.rend());
		vector<int> res(num1.size() + num2.size(),0);
		int car = 0; //carry
		FOR(i,0,vec2.size()){
			FOR(j,0,vec1.size()){
				res[i+j] += (vec2[i] - '0')*(vec1[j]-'0') + car;
				car = res[i+j]/10;
				res[i+j] = res[i+j]%10;				
			}
			if(car > 0) res[i + vec1.size()] += car; // carry
			car = 0;
		}
		if(car > 0) res[num1.size() + num2.size() -1] += car;
		string s = "";
		int i = res.size() - 1;
		while(i >=0 && res[i] == 0) i--;
		if(i < 0 ) s += '0';
		FOD(j,i,-1){
				s += char(res[j] + '0');
		}
	return s;
    }
};