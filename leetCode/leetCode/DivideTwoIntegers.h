#pragma once
#include <iostream>
using namespace std;
class Solution {
public:
#define MIN (-2147483647 - 1)
#define MAX 2147483647
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool flag = false;
		int remainder = 0;
		if(divisor == 0) return NULL;
        if(divisor < 0){ // consider the MIN
			if(divisor == MIN){
				if(dividend == divisor) return 1;
				else return 0;
				}
			else{
				divisor = -divisor;
				flag = !flag;
			}
        }
        if(dividend < 0){
			if(dividend == MIN){
				dividend = MAX - divisor + 1;
				remainder = 1;
				flag = !flag;
			}
			else{
				dividend = -dividend;
				flag = !flag;
			}
        } 
		int A = dividend, B = divisor, total = 0;
        int count = 1;
        while(A >= B){
			if((A - B) >= B){
				B += B;
				count += count;
			}
			else{
				total += count;
				A -= B;
				B = divisor;
				count = 1;
			}
        }
		if(flag)return -total-remainder;
		else return total + remainder;
    }
};