#pragma once 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
template<class T>  T fmax(T& a, T& b ){if(a >= b) return a; return b;} // return the bigger value
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int sum = 0,max = 0;
		FOR(i,0,n){
			//int newSum = sum + A[i];
			//if(newSum >= max){  max = newSum; ans.push_back(max);}
			//else if(newSum < 0){
			//	max = sum = 0; 
			//	continue;
			//}
			//sum = newSum;
			int newSum = sum + A[i]; //when sum is negative,
			sum = fmax(newSum,A[i]); //  sum become A[i]
			max = fmax(sum,max);
		}
		return max;
    }
};