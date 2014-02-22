#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) return 0;
        if(tokens.size() == 1) return str2num(tokens[0]);
        vector<int> nums;
        for(int i =0; i<tokens.size(); ++i){
            if(tokens[i] == "+"){
                int rnum = nums.back();nums.pop_back();
                int lnum = nums.back();nums.pop_back();
                nums.push_back(lnum+rnum);
                cout<< lnum << " + "<< rnum << " = "<< nums.back()<<endl;
            }
            else if(tokens[i] == "-"){
                int rnum = nums.back();nums.pop_back();
                int lnum = nums.back();nums.pop_back();
                nums.push_back(lnum-rnum);                
                cout<< lnum << " - "<< rnum << " = "<< nums.back()<<endl;
            }
            else if(tokens[i] == "*"){
                int rnum = nums.back();nums.pop_back();
                int lnum = nums.back();nums.pop_back();
                nums.push_back(lnum*rnum);                
                cout<< lnum << " * "<< rnum << " = "<< nums.back()<<endl;
            }
            else if(tokens[i] == "/"){
                int rnum = nums.back();nums.pop_back();
                int lnum = nums.back();nums.pop_back();
                nums.push_back(lnum/rnum);                
                cout<< lnum << " / "<< rnum << " = "<< nums.back()<<endl;
            }
            else{
                nums.push_back(str2num(tokens[i]));
            }
        }
        return nums[0];
    }
    int str2num(string str){
        int ans = 0;
        bool flag = false;
        for(int i = 0;i<str.size();++i){
            if(str[i] == '-') {
                flag = true; continue;
            }
            if(str[i] == '+'){
                continue;
            }
            ans += (str[i]-48)*pow(10,double(str.size()-1-i));
        }
        if(true == flag) return -ans;
        return ans;
    }
};
