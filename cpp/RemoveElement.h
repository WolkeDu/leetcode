//Remove Element first sort the array , then remove the elements 
#pragma once
using namespace std;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if( n == 0 )
			return n;
		//QS(A, 0 , n-1);
	//	for(int i = 0; i< n; ++i)
	//		cout<<A[i];
		int i = -1, j = n;
		int l = -1, count = 0;
		while(1){
			while( A[++i] != elem && i <= n);
			while(A[--j] == elem && j >= 0){
				count++;
			};
			if(i > j) break;
			swap(A,i,j); 
			count++;
		}
		return n - count;
	}
	void swap(int* a, int i, int j){
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;	
	};
};