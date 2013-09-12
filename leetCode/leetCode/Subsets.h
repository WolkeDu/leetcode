#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > ress;
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> res;
		res.clear();ress.clear();
		ress.push_back(res);
		if(S.size() == 0){
			return(ress);
		}
		QS(S, 0 , S.size() - 1);
		findSets(S, 0 , res);
		return ress;
    }
	void QS(vector<int>& s, int l, int r){
		if(l >= r) return;
		int key = s[l], i = l, j = r+1;
		while (true)
		{
			while (i!= r && s[++i] <= key);
			while (j!=l && s[--j] > key);
			if(i >= j )
				break;
			swap(s,i,j);
		}
		swap(s,l,j);
		QS(s,l,j-1);
		QS(s,j+1,r);
	}
	void swap(vector<int>& s, int i, int j){
		int tmp = s[i]; s[i] = s[j]; s[j] = tmp;
	}
	void findSets(vector<int>& s, int start, vector<int>& res){
		if(start == s.size()){
			return;
		}
		for(int i = start;i<=s.size()-1;++i){
			res.push_back(s[i]);
			ress.push_back(res);
			findSets(s,i+1,res);
			res.pop_back();
		}	
	}
};