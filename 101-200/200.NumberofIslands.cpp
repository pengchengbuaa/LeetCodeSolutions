#include <vector>
#include <iostream>
using std::pair;
using std::vector;
class Solution
{
  public:
    //up left down right
    vector<pair<int, int>> dirs =
        {pair(-1, 0), pair(0, -1), pair(1, 0), pair(0, 1)};

    void dfs(vector<vector<char>> &grid,
             vector<vector<char>> &visited, int h, int w, int i, int j)

    {
        visited[i][j] = 1;
        for (int c = 0; c < 4; c++)
        {
            int next_h = i + dirs[c].first;
            int next_w = j + dirs[c].second;
            if (next_w >= 0 && next_w < w && next_h >= 0 && next_h < h &&
                !visited[next_h][next_w] && '1' == grid[next_h][next_w])
            {
                dfs(grid, visited, h, w, next_h, next_w);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int h = grid.size();
        if (h == 0)
            return 0;
        int w = grid[0].size();
        if (w == 0)
            return 0;

        auto visited = vector<vector<char>>(h, vector<char>(w, 0));

        int cnt = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == 0)
                {
                    cnt++;
                    dfs(grid, visited, h, w, i, j);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<char>> m =
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };

    Solution s;
    std::cout << s.numIslands(m) << std::endl;
    return 0;
}
