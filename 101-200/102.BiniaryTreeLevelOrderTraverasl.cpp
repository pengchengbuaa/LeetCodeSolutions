#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *ln, TreeNode *rn) : val(x), left(ln), right(rn) {}
};
class Solution
{

  public:
    vector<TreeNode *> travelLevel(vector<TreeNode *> level)
    {
        vector<TreeNode *> newLevel;
        for (auto n : level)
        {
            if (n->left)
                newLevel.push_back(n->left);
            if (n->right)
                newLevel.push_back(n->right);
        }
        return newLevel;
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        vector<TreeNode *> level{root};
        while (!level.empty())
        {
            vector<int> levelVal;
            for (auto n : level)
            {
                levelVal.push_back(n->val);
            }
            ans.push_back(levelVal);
            level = travelLevel(level);
        }
        return ans;
    }
};

int main()
{
    Solution s;

    TreeNode *t = new TreeNode(3,
                               new TreeNode(9),
                               new TreeNode(20,
                                            new TreeNode(15),
                                            new TreeNode(7)));

    auto ans = s.levelOrder(t);

    return 0;
}