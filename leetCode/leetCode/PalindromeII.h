#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
	vector<vector<int> > flag; // 0-undefined;1-true;2-false;
int minCut(string s){
	 int len = s.length();
	 if(len == 0||len==1) return 0;
	 vector<int> min, vtmp;
	 min.clear();vtmp.clear();flag.clear();
	for(int i = 0;i<len;i++){
		vtmp.push_back(-1);
		min.push_back(0);
	}
 for(int i =0;i<len;i++){
	 flag.push_back(vtmp);
 }
 int ans,tmp;
 for(int i = 1;i<=len-1;i++){ //step size
	 if(isPali(s,0,i)) min[i] = 0;
	 else{
		ans = len-1;
		for(int k = 0;k<i;k++){
				if(isPali(s,k+1,i)) tmp = min[k] +1;
				else
				 tmp = min[k] + i - k;
				if(tmp < ans) ans = tmp;
			}
	     min[i] = ans;
	 }
 }

return min[len-1];
}
bool isPali(string& s, int i, int j){
	if(flag[i][j] != -1) return flag[i][j];
	if(i == j) return flag[i][i]=1;
	if(s[i] != s[j]) return flag[i][j] = 0;
	else{
		if(j-i == 1) return flag[i][j] = 1;
		else
		return flag[i][j]=isPali(s,i+1,j-1);
	}	
}

};

