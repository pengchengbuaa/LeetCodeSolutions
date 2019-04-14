#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void getN(int &n, int &dep, string::iterator &p, string &S) {
    if (p == S.end()) {
      n = 0;
      dep = -1;
      return;
    }

    dep = 0;
    while (*p == '-') {
      dep++;
      p++;
    }

    n = 0;
    while (p != S.end() && *p != '-') {
      n = n * 10 + ((*p) - '0');
      p++;
    }
  }

  TreeNode *recoverFromPreorder(string S) {
    if (S.size() == 0) return NULL;
    int n;
    int dep;

    auto p = S.begin();

    vector<TreeNode *> ancestors;

    // TreeNode *ans;
    while (p != S.end()) {
      getN(n, dep, p, S);

      auto node = new TreeNode(n);

      if (ancestors.size() < dep + 1) {
        ancestors.push_back(node);
        if (dep != 0) {
          ancestors[dep - 1]->left = node;
        }
      }

      else {
        ancestors[dep - 1]->right = node;
        ancestors[dep] = node;
        while (ancestors.back() != node) {
          ancestors.pop_back();
        }
      }
    }

    return ancestors[0];
  }
};

int main() {
  Solution s;
  //   string st{"1-401--349---90--88"};
  string st{"1-2--3---4-5--6---7"};
  auto ans = s.recoverFromPreorder(st);

  return 0;
}