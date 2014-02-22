 // consider BFS to traverse the BST tree
// notice to check that the subtree's value all less than or greater than the parent node.
#include <iostream>
#include <queue>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(root == NULL ) return true;
		 queue<TreeNode*> que;
		 TreeNode* cur;
		 que.push(root);
		 while(!que.empty()){
			 cur = que.front();
			// cur = que.pop();
			 que.pop();
			 if(cur->left == NULL && cur->right == NULL)
				 continue;
			 if(cur->left != NULL){
				 que.push(cur->left);
                 TreeNode* tmp = cur->left;
                 while(tmp!=NULL){
                     if(tmp->val >= cur->val) return false;
                     tmp = tmp->right;
                 }	 
			 }
			 if(cur->right != NULL){
				 que.push(cur->right);
                 TreeNode* tmp = cur->right;
                 while(tmp!=NULL){
                     if(tmp->val <= cur->val) return false;
                     tmp = tmp->left;
                 } 
			 }
		 }
		 if(que.empty()) return true;
    }
};