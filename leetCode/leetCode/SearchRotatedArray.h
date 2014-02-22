//Draw a line on Euclidean plane, we can get a intuitive impression.
class Solution {
public:
    int search(int A[], int n, int target) {
		if(n == 0) return -1;
		int ans = dfs(A,0,n-1,target);
		return ans;
    }
	int dfs(int*& A, int left, int right, int& target){
		if(left > right)
			return -1;
		int mid = (left + right)/2;
		if(A[mid] == target) return mid;
		if(A[mid] < target){
			if( A[right] >= A[mid] && A[right] < target) //A[left]>A[mid] &&
					return dfs(A,left,mid-1,target);
			return dfs(A,mid+1,right,target);
		}
		else{
			if(A[left] <= A[mid]  && A[left] > target) //&& A[right] < A[mid]
				return dfs(A,mid+1,right,target);
			return dfs(A,left,mid-1,target);
		}
	}
};