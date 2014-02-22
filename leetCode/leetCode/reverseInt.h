#pragma once
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
	#define MAX 2147483647
	#define MIN -2147483647-1
	#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		bool flag = false;
		if(x<0){
			x = -x; flag = true;
			if( x < 0 )
				return x;
		}
		vector<int> nums;
		while(x >= 10){
			nums.push_back(x%10);
			x = x/10;
		}
		nums.push_back(x);
		int ans = 0;
		FOR(i,0,nums.size()){
			ans += nums[i]*int(pow(10,nums.size()-i-1));
			if(ans < 0 ){
				if(flag)
					return ans;
				else return MAX;
			}
		}
		if(flag) return -ans;
		else return ans;
    }
};