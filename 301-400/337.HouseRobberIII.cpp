#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
class Solution {
 public:
  // rob value for including root and without root
  pair<int, int> robwise(TreeNode* root) {
    // if (root->left == NULL && root-> right ==NULL){
    //     return make_pair(root->val, 0);
    // }

    int withroot = root->val;
    int withoutroot = 0;

    if (root->left != NULL) {
      auto leftans = robwise(root->left);
      withroot += leftans.second;
      withoutroot += max(leftans.second, leftans.first);
    }

    if (root->right != NULL) {
      auto rightans = robwise(root->right);
      withroot += rightans.second;
      withoutroot += max(rightans.second, rightans.first);
    }
    return make_pair(withroot, withoutroot);
  }
  int rob(TreeNode* root) {
    if (root == NULL) return 0;
    auto ans = robwise(root);
    return max(ans.first, ans.second);
  }
};

int main() {
  TreeNode* t;
  t = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(3)),
                   new TreeNode(5, NULL, new TreeNode(1)));

  Solution s;
  cout << s.rob(t) << endl;
}