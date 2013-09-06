// use an auxiliary array to store array A's values
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* tmp = new int[m];
        for(int i = 0; i < m; i++)
            *(tmp+i) = A[i];
        int i = 0, j= 0, k = 0;
        while(i<m && j<n){
            if(tmp[i] <= B[j]){
                A[k++] = tmp[i++];
            }
            if(B[j] < tmp[i]){
                A[k++] = B[j++];
            }
        }
        if(i != m)
            while(i<m) A[k++] = tmp[i++];
        if(j != n)
            while(j<n) A[k++] = B[j++];
    }
};