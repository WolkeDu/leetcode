#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() <= 1) return;
        int i;
        for(i = num.size()-2;i>=0;i--){
            if(num[i]<num[i+1]){
                int t = num[i],j = i;
                while(++j<num.size() && t < num[j]);
                j--;
                num[i] = num[j];
                num[j] = t;
                sort(num.begin()+i+1,num.end());
				break;
            }
        }
        if(i == -1) sort(num.begin(),num.end());
    }
};