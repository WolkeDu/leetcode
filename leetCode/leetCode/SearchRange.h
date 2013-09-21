#include <vector>
using namespace std;
class Solution {
public:
	vector<int> ans;
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> vec;vec.clear();
		vec.push_back(-1);vec.push_back(-1);
		if(n == 0 ) return vec;
		ans.clear();
        dfs(A,0,n-1,target,n); // binary search
		if(ans.size() == 0) return vec;
		if(ans.size() == 1)
			ans.push_back(ans[0]);
		if(ans[0] > ans[1]) {int tmp = ans[0]; ans[0] = ans[1]; ans[1] = tmp;};
		return ans;
    }
	void dfs(int*& A, int left, int right, int& target, int& n){
		if(left > right) return;
		if(ans.size() == 2) return;
		int mid = (left + right)/2;
		if(A[mid] < target) dfs(A,mid+1,right,target,n);
		else if(A[mid] > target) dfs(A,left,mid-1,target,n);
		else{
			if(mid ==0 ){ ans.push_back(mid);dfs(A,mid+1,right,target,n);}
 			else if(mid == (n-1)){ans.push_back(mid);dfs(A,left,mid-1,target,n);}
			else{
				if(A[mid - 1] < A[mid] || A[mid+1] > A[mid]){ 
					ans.push_back(mid);
					if(A[mid - 1] < A[mid]) dfs(A,mid+1,right,target,n);			
					else dfs(A,left,mid-1,target,n);
				}
				if(A[mid - 1] == A[mid])
					dfs(A,left,mid-1,target,n);
				if(A[mid+1] == A[mid])
					dfs(A,mid+1,right,target,n);
			}
		}
	};
};