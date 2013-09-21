#include <string>
#include <vector>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> res;
        vector<string> ans = dfs(0,0,s,res);
		return ans;
    }
	vector<string> dfs(int level, int idx, string& s, vector<string>& res){
		if(level == 4){
			vector<string> tmp; 
			if(idx >= s.size()) {
			tmp.push_back(res[0] + "." + res[1] + "." + res[2] + "." + res[3]);			
			}
			return tmp;
		}
		vector<string> ans;
		int range = s.size() - idx;
		range = range>=3?3:range;
		bool flag = false;
		FOR(i,1,range+1){
			int num = a2i(s.substr(idx,i));
			if(num > 255 || flag) break;
			if(num == 0) flag = true;
			res.push_back(s.substr(idx,i));
			vector<string> ret = dfs(level+1,idx+i,s,res);
			FOR(i,0,ret.size())
				ans.push_back(ret[i]);
			res.pop_back();
		}
		return ans;
	}
	int a2i(string s){
		vector<char> str(s.rbegin(),s.rend());
		int sum = 0;
		FOR(i,0,str.size()){
			sum += (str[i] - '0')*int(pow(10,i));
		}
		return sum;
	}
};