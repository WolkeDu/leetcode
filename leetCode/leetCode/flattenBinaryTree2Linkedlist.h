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
	TreeNode* end;
#define FOR(i,m,n) for(int i = int(m); i< int(n); i++)
#define FOD(i,m,n) for(int i = int(m); i > int(n);i--)
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dfs(root);
		return;
    }
	TreeNode* dfs(TreeNode* cur){
		if(cur == NULL) return NULL;
		cur->left = dfs(cur->left);
		if(cur->left != NULL){
			TreeNode* t = cur->left;
			while(t->right != NULL) t = t->right;
		t->right = dfs(cur->right);
		cur->right = cur->left;
		cur->left = NULL;
		}
		else
			cur->right = dfs(cur->right);
		return cur;
	}
};