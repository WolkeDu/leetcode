#include <vector>
using namespace std;
//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
		vector<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		while(cur != NULL || !st.empty()){
			if(cur != NULL){
				st.push_back(cur);
				cur = cur->left;
			}
			else {
				cur = st.back();
				if(cur->right != NULL && pre != cur->right){
					cur = cur->right;
				}
				else{
					pre = cur = st.back(); // record the visit history of right subtree
					st.pop_back();
					ans.push_back(cur->val);
					cur = NULL;
				}
			}
		}
		return ans;
    }
};