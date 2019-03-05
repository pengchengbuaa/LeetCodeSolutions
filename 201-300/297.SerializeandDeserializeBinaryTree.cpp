#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == NULL)
      return "null";
    else {
      return to_string(root->val) + "," + serialize(root->left) + "," +
             serialize(root->right);
    }
  }
  // Decodes your encoded data to tree.
  string::iterator si;
  TreeNode* deserialize(string data) {
    si = data.begin();
    return ds(data);
  }

  TreeNode* ds(string& s) {
    if (si == s.end()) return NULL;
    auto comma = s.find(",", si - s.begin());
    string rootstring = s.substr(si - s.begin(), s.begin() + comma - si);
    si = s.begin() + comma + 1;
    if (rootstring == "null")
      return NULL;
    else {
      int rootint = atoi(rootstring.c_str());
      TreeNode* l = ds(s);
      TreeNode* r = ds(s);
      TreeNode* newT = new TreeNode(rootint);
      newT->left = l;
      newT->right = r;
      return newT;
    }
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
  auto r = new TreeNode(1, new TreeNode(2),
                        new TreeNode(3, new TreeNode(4), new TreeNode(5)));
  //   auto r = (TreeNode*)NULL;

  Codec c;
  string sls = c.serialize(r);
  cout << sls << endl;

  auto t = c.serialize(c.deserialize(sls));

  cout << t << endl;
  return 0;
}