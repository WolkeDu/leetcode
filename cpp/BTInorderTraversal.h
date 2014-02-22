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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
		vector<TreeNode*> st;
		TreeNode* cur = root;
		while(cur!=NULL || !st.empty()){
			if(cur!=NULL){
				st.push_back(cur);
				cur = cur->left;
			}
			else{
				cur = st.back();
				st.pop_back();
				ans.push_back(cur->val);
				cur = cur->right;
			}			
		}
		return ans;
    }
};