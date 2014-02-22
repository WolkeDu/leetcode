#include <vector>
#include <unordered_map>
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
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(preorder.size() == 0 || preorder.size() != inorder.size()) return NULL;
        vector<TreeNode*> nodes;
		unordered_map<int,int> inmap;
		inmap.clear();nodes.clear();
		FOR(i,0,inorder.size()) inmap[inorder[i]] = i;
        vector<bool> marked(preorder.size(),false);        
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* cur = root;
		marked[inmap[cur->val]] = true;
        int idx_p = 0;
        nodes.push_back(cur); //indices.push_back(idx);
		while(!nodes.empty()){
			cur = nodes.back();
			int idx_i = inmap[cur->val];
			if(idx_i > 0 && marked[idx_i-1] == false){
				cur->left = new TreeNode(preorder[++idx_p]);
				cur = cur->left; nodes.push_back(cur);
				marked[inmap[cur->val]] = true;
			}
			else if(idx_i<preorder.size()-1 && marked[idx_i + 1] == false){
				cur->right = new TreeNode(preorder[++idx_p]);
				cur = cur->right; nodes.push_back(cur);
				marked[inmap[cur->val]] = true;
				}
			else{
				nodes.pop_back();
			}
		}
		return root;
    }
};