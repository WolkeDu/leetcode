#pragma once
#include <vector>
using namespace std;
//* Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	int sum;
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if(root == NULL) return NULL;
	   vector<int> num; num.clear();
	   sum= 0;
	   dfs_sum(root, num);
	   return sum;
    }
	void dfs_sum(TreeNode* cur, vector<int> num){
		num.push_back(cur->val);
		if(cur->left == NULL && cur->right == NULL){
			sum += v2num(num);
			return;
		}
		if(cur->left != NULL){
			dfs_sum(cur->left,num);
		}
		if(cur->right != NULL){
			dfs_sum(cur->right,num);
		}
		num.pop_back();
	}
	int v2num(vector<int> v_num){
		int l = v_num.size()-1;
		int res = 0;
		for(int i = 0; i<= l;i++){
			res += v_num[i]*int(pow(10,l-i));
		}
		return res;
	}
};