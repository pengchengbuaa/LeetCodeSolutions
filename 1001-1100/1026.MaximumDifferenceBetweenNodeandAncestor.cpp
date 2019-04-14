
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};
class Solution {
 public:
  // int maxdis = 0;
  void mmvalues(TreeNode *root, int &mimv, int &maxv, int &maxdis) {
    int mim_ = root->val;
    int max_ = root->val;
    mimv = mim_;
    maxv = max_;

    if (root->left) {
      mmvalues(root->left, mim_, max_, maxdis);

      mimv = min(mim_, mimv);
      maxv = max(max_, maxv);

      maxdis = max(maxdis, abs(mimv - root->val));
      maxdis = max(maxdis, abs(maxv - root->val));
    }

    if (root->right) {
      mmvalues(root->right, mim_, max_, maxdis);

      mimv = min(mim_, mimv);
      maxv = max(max_, maxv);

      maxdis = max(maxdis, abs(mimv - root->val));
      maxdis = max(maxdis, abs(maxv - root->val));
    }

    mimv = min(mimv, root->val);
    maxv = max(maxv, root->val);
  }
  int maxAncestorDiff(TreeNode *root) {
    if (root == NULL) return 0;

    int mimv = root->val;
    int maxv = root->val;
    int maxdis = 0;
    mmvalues(root, mimv, maxv, maxdis);

    return maxdis;
  }
};

int main() {
  Solution s;
  TreeNode *t = new TreeNode(
      8,
      new TreeNode(3, new TreeNode(1),
                   new TreeNode(6, new TreeNode(4), new TreeNode(7))),
      new TreeNode(10, NULL, new TreeNode(14, new TreeNode(13), NULL)));
  cout << s.maxAncestorDiff(t) << endl;
}