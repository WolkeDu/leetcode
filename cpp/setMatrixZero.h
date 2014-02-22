//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
// notice the index of vector array. we can use the zero column and zero row as the notice array to mark the rest elements of the matrix.
#include <vector>
using namespace std;
class Solution{
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m = matrix.size();
		int n = matrix[0].size();
		bool rowzero = false, colzero = false;
		for(int i =0;i<m;i++)
			if(matrix[i][0] == 0) rowzero = true;
		for(int j = 0;j<n;j++)
			if(matrix[0][j] == 0) colzero = true;
		for(int i = 1;i<m;i++){
			for(int j = 1;j<n;j++){
				if(matrix[i][j] == 0){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for(int i = 1;i<m;i++){
			if(matrix[i][0] == 0)
				setrowzeros(matrix,i);
		}
		for(int j = 1;j<n;j++)
			if(matrix[0][j] == 0)
				setcolzeros(matrix,j);
		if(rowzero == true)
			setcolzeros(matrix,0);
		if(colzero == true)
			setrowzeros(matrix,0);
    }
	void setrowzeros(vector<vector<int> > &M, int i){
		for(int j = 0;j<M[i].size();j++)
			M[i][j] = 0;
	}
	void setcolzeros(vector<vector<int> > &M, int j){
		for(int i =0;i<M.size();i++)
			M[i][j] = 0;
	};
};