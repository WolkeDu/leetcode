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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0) return NULL;
        TreeNode* root = dfs(0,num.size() - 1, num);
    }
    TreeNode* dfs(int l, int r, vector<int>& num){
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* cur = new TreeNode(num[mid]);
        cur->left = dfs(l,mid-1,num);
        cur->right = dfs(mid+1,r,num);
        return cur;
    }
};