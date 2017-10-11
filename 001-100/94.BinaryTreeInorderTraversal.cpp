#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {

    void tral (TreeNode * r, vector<int> & res){
	if(r->left) tral(r->left,res);
	res.push_back(r->val);
	if(r->right) tral(r->right,res);
    }


public:
    vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	if(root==NULL) return res;
	tral(root,res);
	return res;
    }
};
