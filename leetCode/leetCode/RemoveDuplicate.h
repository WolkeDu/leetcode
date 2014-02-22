#pragma once
#include <iostream>
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0 ) return NULL;
        int cur = A[0], idx = 1, len = 0;
        while(1){
            while(idx<n && A[idx] == cur ) idx++;
            if( idx == n) return len + 1;
            else{
                len++; A[len] = A[idx]; 
                cur = A[idx];
            }
        }
    }
};