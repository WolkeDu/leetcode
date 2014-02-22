// Notice the boundary condition
#pragma once 
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size(), n = matrix[0].size();
		int left = 0,mid = 0, right = m-1;
		bool flag = false;
		while(left <= right){
			mid = left + (right - left)/2;
			if( matrix[mid][0] == target){
				flag = true; break;
			}
			if(matrix[mid][0] > target) right = mid - 1;
			else if(matrix[mid][0] < target) left = mid + 1;
		}
		if( flag == true) return true;
		else if(matrix[mid][0] > target && mid > 0)
			return bs(0,n-1,target,matrix[mid-1]);
		else if(matrix[mid][0] < target)
		    return bs(0,n-1,target,matrix[mid]);
		return false;
    }
	bool bs(int left, int right, int& target, vector<int>& val){
		if(left > right) return false;
		int mid = left + (right - left)/2;
		if(val[mid] == target) return true;
		else if( val[mid] > target) return bs(left,mid - 1,target, val);
		else return bs(mid + 1,right,target, val);
	}
};