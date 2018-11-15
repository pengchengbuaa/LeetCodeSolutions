#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        if (preorder.empty())
        {
            return NULL;
        }
        int rootval = preorder[0];
        auto pin = find(inorder.begin(), inorder.end(), rootval);
        int leftSize = pin - inorder.begin();
        int rightSize = preorder.size() - 1 - leftSize;

        auto leftIn = vector<int>(inorder.begin(), inorder.begin() + leftSize);
        auto rightIn = vector<int>(inorder.begin() + leftSize + 1, inorder.end());

        auto leftPre = vector<int>(preorder.begin() + 1, preorder.begin() + leftSize + 1);
        auto rightPre = vector<int>(preorder.begin() + leftSize + 1, preorder.end());

        auto lt = buildTree(leftPre, leftIn);
        auto rt = buildTree(rightPre, rightIn);

        auto t = new TreeNode(rootval);

        t->left = lt;
        t->right = rt;

        return t;
    }
};

int main()
{

    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    Solution s;
    auto ans = s.buildTree(preorder, inorder);

    return 0;
}