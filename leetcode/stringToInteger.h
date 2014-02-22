#include <vector>
#include <math.h> 
using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int i = 0;
		bool flag = false;
		int cut_flag = -1;
		char cur;
		vector<int> nums;
		nums.clear();
		int precise = 10;
		int res = 0;

		while(str[i]!='\0' && (str[i] <48 || str[i]>57)){
			if(str[i]== '+'){
				i++;
				break;
			}
			else if(str[i] == '-'){
				i++;
				flag = true;
				break;
			}
			else if(str[i] == ' ')
				i++;
			else break;
		}
		while(str[i] != '\0' ){

			if(str[i] <48 || str[i]>57){
				cut_flag++;
				break;
			}
			//cur = str[i];
			nums.push_back(str[i]-48);
			i++;
		}
		int len = nums.size();
		for(int i = len-1;i>=0;i--)
		{
			res += int(pow(float(precise),len - 1 - i)) * nums[i];
			if(res < 0) break;
		
		}
		if(flag == true){
			if(res<0) res = -2147483648;
			else res = - res;
		}
		else{
		if(res < 0) res = 2147483647;
		}
       return res;
    }
};