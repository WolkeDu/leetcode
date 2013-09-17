// define a function get(int arr[], int i) to manage the exceed of array index.
//first search array A for the median, if find, then return it; else search array B for the median.
#pragma once
#include<math.h>
using namespace std;
class Solution {
public:
	#define MAX 2147483647
	#define MIN -2147483647-1
    #define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if(m == 0 && n == 0) return NULL;
		if( m == 0 )
			return getMedian(B,n);
		else if(n == 0)
			return getMedian(A,m);
		return Median_search(A,B,m,n);
    }
	double Median_search(int A[], int B[],int m, int n){
		int mid = (m+n)/2,i,j; // if m+n is odd, mid is exactly the median idx. else median is the average of mid and mid-1.
		int start = 0, end = m-1;
		while(start <= end){
			 i = (start+end)/2;
			 j = mid - i;
			if(get(A,i,m) <= get(B,j,n) && get(A,i,m) >= get(B,j-1,n)){
				if ((m+n) % 2 == 0) { //index out of bound here
					return double((get(A,i,m) +  max(get(A, i-1,m), get(B, j-1,n)))) * 0.5;
				}
				else return (double) get(A,i,m);
			}
			if(get(A,i,m) > get(B,j,n)){
				end = i - 1;
				i = (start+end)/2;
				j = mid - i;
			}
			if(get(A,i,m) < get(B,j-1,n))
				start = i+1;
				i = (start+end)/2;
				j = mid - i;
		}
			return Median_search(B,A,n,m);	
	}
	int get(int a[], int i, int sz){
		if(i >= sz)
			return MAX;
		else if( i < 0 )
			return MIN;
		else
			return a[i];

	}
	int max(int a, int b){
		return a>=b?a:b;
	}
	int min(int a, int b){
		return a<=b?a:b;
	}
	double getMedian(int a[], int sz){
		if(sz%2)
			return a[sz/2];
		else 
			return double((a[sz/2] + a[sz/2 - 1]))/2;
	}
};

