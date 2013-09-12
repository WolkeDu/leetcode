#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > ress;
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(num.size() == 0) return ress;
		vector<int> res;
		ress.clear(); res.clear();
		permutation(num,res);  
		return ress;
    }
	void permutation(vector<int> nums, vector<int>& res){
		if(nums.size() == 1){
			res.push_back(nums[0]);
			ress.push_back(res);
			res.pop_back();
			return;
		}
		for(int i = 0;i< nums.size();i++){
			res.push_back(nums[i]);
			vector<int> tmp = nums;
			tmp.erase(tmp.begin() + i);
			permutation(tmp, res);
			res.pop_back();
		}
	};
};