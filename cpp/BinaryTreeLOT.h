#pragma once
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/**
 * Definition for binary tree */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode* > que, que_bk;
		vector<int> level_k;
		vector<vector<int> > ress;
		ress.clear(); level_k.clear();
		if(root == NULL) return ress;
		que.push(root);
		while(!que.empty()){
			while(!que.empty()){
				TreeNode *cur = que.front(); que.pop();
				level_k.push_back(cur->val);
				if(cur->left != NULL)
					que_bk.push(cur->left);
				if(cur->right != NULL)
					que_bk.push(cur->right);
			}
			swap(que,que_bk);
			ress.push_back(level_k);
			level_k.clear();
		}
		return ress;
    }
};