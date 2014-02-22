#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( b == "") return a;
		else if(a == "") return b;
		vector<int> res; res.clear();
		vector<char> r_a(a.rbegin(),a.rend());
		vector<char> r_b(b.rbegin(),b.rend());		
		int idx = a.size() <= b.size()?a.size():b.size();
		int remain = 0,i = 0;
		while( i < idx){
			int val = remain;
			if(r_a[i] == '1')
				val += 1;
			if(r_b[i] == '1')
				val += 1;
			if(val >= 2)
				remain = 1;
			else remain = 0;
			val = val%2;
			res.push_back(val);
			i++;
		}
		if(a.size() > idx){
			for( int i = idx;i<a.size();i++){
				int val = remain;
				if(r_a[i] == '1')
					val += 1;
				if(val >= 2)
					remain = 1;
				else remain = 0;
				val = val%2;
				res.push_back(val);
			}
		}
		else if(b.size() > idx){
			for( int i = idx;i<b.size();i++){
				int val = remain;
				if(r_b[i] == '1')
					val += 1;
				if(val >= 2)
					remain = 1;
				else remain = 0;
				val = val%2;
				res.push_back(val);
			}
		}
		if(remain >0){ 
			res.push_back(remain);
		}
		string ans = "";
		for(int j = res.size()-1;j>=0;--j){
			if(res[j] == 1)
				ans += "1";
			else
				ans += "0";
		}
		return ans;
    }
};