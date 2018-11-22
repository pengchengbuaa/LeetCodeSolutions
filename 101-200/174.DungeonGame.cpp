#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {

        int row = dungeon.size();
        int col = dungeon[0].size();

        if (row == 0 && col == 0)
            return 0;
        auto MinBeforeEnter = vector<vector<int>>(row, vector<int>(col, 0));
        MinBeforeEnter[row - 1][col - 1] = max(1, 1 + -dungeon[row - 1][col - 1]);

        for (int i = row - 2; i >= 0; i--)
        {
            MinBeforeEnter[i][col - 1] = max(1, MinBeforeEnter[i + 1][col - 1] - dungeon[i][col - 1]);
        }
        for (int j = col - 2; j >= 0; j--)
        {
            MinBeforeEnter[row - 1][j] = max(1, MinBeforeEnter[row - 1][j + 1] - dungeon[row - 1][j]);
        }

        for (int i = row - 2; i >= 0; i--)
        {
            for (int j = col - 2; j >= 0; j--)
            {
                MinBeforeEnter[i][j] = max(1, min(MinBeforeEnter[i + 1][j], MinBeforeEnter[i][j + 1]) - dungeon[i][j]);
            }
        }

        return MinBeforeEnter[0][0];
    }
};

int main()
{
    auto m = vector<vector<int>>{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};

    Solution s;
    cout << s.calculateMinimumHP(m) << endl;

    return 0;
}