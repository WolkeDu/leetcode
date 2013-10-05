#pragma once
#include <vector>
#include <algorithm>
#include <set>;
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    vector<vector<int> > ans;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(num.size() <= 1){
          ans.push_back(num); 
          return ans;
        } 
		sort(num.begin(),num.end());
        vector<int> res;
        ans.clear(); res.clear();
        dfs(num,res);
        return ans;
    }
    void dfs(vector<int> num, vector<int>& res){
        if(num.size() == 1){
            res.push_back(num[0]); ans.push_back(res);
            res.pop_back();
            return;
        }
        vector<int> tmp;
        for(int i = 0; i < num.size(); ++i){
            tmp = num;
            if(i<num.size()-1 && num[i] == num[i+1])
                continue;
            tmp.erase(tmp.begin()+i); res.push_back(num[i]);
            dfs(tmp,res);
            res.pop_back();
        }
    }
};