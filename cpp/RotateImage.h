#pragma once
#include <vector>
#include <algorithm>
#include <set>;
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // notice the index of the elements to be swapped
        int n = matrix.size();
        int range = n/2;
        for(int k = 0; k <= range; ++k){
            for(int i = k; i<n-1-k; ++i){
                int tmp = matrix[k][i];
                matrix[k][i] = matrix[n-1-i][k];
                matrix[n-1-i][k] = matrix[n-1-k][n-1-i];
                matrix[n-1-k][n-1-i] = matrix[i][n-1-k];
                matrix[i][n-1-k] = tmp;
            }
        }
    }
};