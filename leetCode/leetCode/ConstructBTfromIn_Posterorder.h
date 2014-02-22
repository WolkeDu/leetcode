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
	unordered_map<int,int> inmap;
	int idx_p;
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(postorder.size() == 0 || postorder.size() != inorder.size()) return NULL;
		inmap.clear();
		FOR(i,0,inorder.size()) inmap[inorder[i]] = i;
		idx_p = postorder.size();
		TreeNode* root = dfs(0,inorder.size()-1,inorder,postorder);
		return root;
	}
	TreeNode* dfs(int l, int r,vector<int>& inorder, vector <int>& postorder){
		if(l > r) return NULL;
		TreeNode* cur = new TreeNode(postorder[--idx_p]);
		int idx = inmap[cur->val];
		cur->right = dfs(idx+1,r,inorder,postorder);
		cur->left = dfs(l,idx-1,inorder,postorder);
		return cur;
	}
	//under are iterative answer
   /* TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(postorder.size() == 0 || postorder.size() != inorder.size()) return NULL;
        vector<TreeNode*> nodes;
		unordered_map<int,int> inmap;
		inmap.clear();nodes.clear();
		FOR(i,0,inorder.size()) inmap[inorder[i]] = i;
		int idx_p = postorder.size()-1;
        vector<bool> marked(postorder.size(),false);        
        TreeNode* root = new TreeNode(postorder[idx_p]);
        TreeNode* cur = root;
		marked[inmap[cur->val]] = true;
        nodes.push_back(cur);
		while(!nodes.empty()){
			cur = nodes.back();
			int idx_i = inmap[cur->val];
			if(idx_i<postorder.size()-1 && marked[idx_i + 1] == false){
				cur->right = new TreeNode(postorder[--idx_p]);
				cur = cur->right; nodes.push_back(cur);
				marked[inmap[cur->val]] = true;
				}
			
			else if(idx_i > 0 && marked[idx_i-1] == false){
				cur->left = new TreeNode(postorder[--idx_p]);
				cur = cur->left; nodes.push_back(cur);
				marked[inmap[cur->val]] = true;
			}
			else{
				nodes.pop_back();
			}
		}
		return root;
    }
	*/
};