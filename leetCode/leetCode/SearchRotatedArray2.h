//if the array hasn't target, the time complex will be o(n)
class Solution {
public:
    bool search(int A[], int n, int target) {
		if(n == 0) return false;
		bool ans = bs(A,0,n-1,target);
		return ans;
    }
	bool bs(int*& A, int left, int right, int& target){
		if(left > right)
			return false;
		int mid = left + (right - left)/2;
		if(A[mid] == target) return true;
		if(A[left] < A[mid]){
			if(A[left]<=target && A[mid] > target)
				return bs(A, left, mid -1, target);
			else return bs(A,mid+1,right,target);
		}
		else if( A[left] > A[mid] ){
			if(A[mid] < target && A[right] >= target)
				return bs(A,mid+1,right,target);
			else return bs(A,left,mid-1,target);
		}
		else return bs(A,left+1,right,target);
	}
};