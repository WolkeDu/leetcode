#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
    	int steps = 0;
		vector<int> map(n);
		map[0] = 1; map[1] = 2;
		for(int i = 2;i<n;i++)
			map[i] = map[i-1]+map[i-2];
		return map[n-1];
    }
};