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
template<class T>  void swap(T& a, T& b){	T tmp;tmp = a; a = b; b = tmp;}
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<TreeNode*> st1,st2;
		vector<vector<int> > ans;
		vector<int> res;
		ans.clear();st1.clear();st2.clear(); res.clear();
		bool flag;
		if(root == NULL) return ans;
		st1.push_back(root);
		while(!st1.empty()){
			while(!st1.empty()){
				TreeNode* cur = st1.back();
				st1.pop_back();
				res.push_back(cur->val);
				if(flag){
					if(cur->right != NULL) st2.push_back(cur->right);
					if(cur->left != NULL) st2.push_back(cur->left);
				}
				else{				
					if(cur->left != NULL) st2.push_back(cur->left);
					if(cur->right != NULL) st2.push_back(cur->right);
				}
			}
		swap(st1,st2);
		ans.push_back(res);
		res.clear();st2.clear(); //reset the stack
		flag = !flag;
		}
       return ans; 
    }
};