//#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > ress;
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(k == 0 || n == 0 || k > n) return ress;
        vector<int> res;
		res.clear();
		combination(k,1,n,res);
		return ress;
    }
	void combination(int k, int start, int n, vector<int>& res){
		k--; 
		if( k == 0 ){
			for(int i = start; i<= n; i++){
				res.push_back(i);
				ress.push_back(res);
				res.pop_back();
			}
			return;
		}

		for( int i = start; i< n; i++){
			res.push_back(i);
			combination(k,i+1,n,res);
			res.pop_back();	
		}		
	}
};