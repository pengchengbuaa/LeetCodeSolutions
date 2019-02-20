#include <vector>
#include <stack>
#include <iostream>
using std::cout, std::endl;
using std::vector;
class Solution
{
  private:
    void backtrack(vector<int> current, int cursum, int k, int n, vector<vector<int>> &ans)
    {
        if (k == 0 && cursum == n)
        {
            ans.push_back(current);
        }
        int lastn;
        if (current.empty())
        {
            lastn = 0;
        }
        else
            lastn = current.back();
        for (int i = lastn + 1; i < 10; i++)
        {
            current.push_back(i);
            backtrack(current, cursum + i, k - 1, n, ans);
            current.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> tmpans;

        backtrack(tmpans, 0, k, n, ans);
        return ans;
    }
};

void printans(vector<vector<int>> ans)
{
    for (auto v : ans)
    {
        for (auto vv : v)
        {
            cout << vv << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    Solution s;
    printans(s.combinationSum3(3, 7));
    printans(s.combinationSum3(3, 9));
}