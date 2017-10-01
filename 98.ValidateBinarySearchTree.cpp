/**
 * Definition for a binary tree node.
 */
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
bool isbt(TreeNode* t ,long mi,long ma){
    int v=t->val;
    if(v<=mi || v>=ma)	return false;
    if(t->left && !isbt(t->left,mi,v)) return false;
    if(t->right && !isbt(t->right,v,ma))	return false;
    return true;
}

public:
    bool isValidBST(TreeNode* root) {
	if(!root)   return true;
	return isbt(root,LONG_MIN,LONG_MAX);
    }
};
