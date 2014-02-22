/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return false;
        return dfs(root,0,sum);
    }
    bool dfs(TreeNode* root, int sum, int target){
        sum += root->val;
        if(root->left == NULL && root->right == NULL) 
            if(sum == target) return true;
            else return false;
        bool flag = false;
        if(root->left != NULL) flag = flag | dfs(root->left,sum,target);
        if(root->right != NULL) flag = flag | dfs(root->right,sum,target);
        return flag;
    }
};