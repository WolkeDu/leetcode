#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<vector<string> > res_all;
    vector<string> res;
	bool** flag;
	bool isPali(string s){
		int len = s.length();
	for(int i = 0;i<=len/2;i++)
		if(s[i] != s[len-i-1]) return 0;
	return 1;	
	}
	vector<vector<string> > partition(string s){
	 int len = s.length();
	  res_all.clear();res.clear();
 flag = new bool*[len];
 for(int i =0;i<len;i++){
	 flag[i] = new bool[len];
	 memset(flag[i],0,len);
 }
 for(int i = 0;i<len;i++){
	 flag[i][i] = true;
	 if(i<len-1 && s[i] == s[i+1]) flag[i][i+1]=true;
 }
 for(int i = 1;i<=len-1;i++){ // i is the step size
	 for(int j=0;j<=len-i-1;j++){  // j is the begin of each loop
		int k = j+i;
		if(s[j] == s[k])
			if(flag[j+1][k-1]){
				flag[j][k] = true;
			}
	 }
 }
//for(int i = 0;i<len;i++){
//	for(int j=0;j<len;j++)
//		cout<<flag[i][j]<<"\t";
//	cout<<endl;
//}

 DFS(s, len, -1);
return res_all;
}

	void DFS(string s, int len, int lf){
		if(lf == (len-1)){
		res_all.push_back(res);
		return;
		}
		int next = lf+1;
		for(int i =next;i<=len-1;i++){

			if(flag[next][i] == true){
				res.push_back(s.substr(next,i-next+1));
				DFS(s,len,i);
				res.pop_back();
			}
		}
	}
};


