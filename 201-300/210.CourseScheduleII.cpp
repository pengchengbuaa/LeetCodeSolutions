#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
using std::multimap;
using std::pair;
using std::set;
using std::string;
using std::unordered_multiset;
using std::vector;

class Solution
{
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());

        auto in_degree = vector<int>(numCourses, 0);
        for (auto p : prerequisites)
        {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }
        auto avail = vector<int>{};

        // find out available start courses
        for (int i = 0; i < numCourses; i++)
        {
            if (in_degree[i] == 0)
                avail.push_back(i);
        }
        // travel over graph
        vector<int> ans;
        while (!avail.empty())
        {
            for (auto a : graph[*avail.begin()])
            {
                if (!--in_degree[a])
                    avail.push_back(a);
            }
            ans.push_back(*avail.begin());
            avail.erase(avail.begin());
        }
        if (ans.size() < numCourses)
            return vector<int>();
        return ans;
    }
};

int main()
{
    int num = 4;
    // int num = 2;
    auto pre = vector<pair<int, int>>{
        pair<int, int>{1, 0},
        pair<int, int>{2, 0},
        pair<int, int>{3, 1},
        pair<int, int>{3, 2}};

    Solution s;
    auto ans = s.findOrder(num, pre);

    for (auto i : ans)
    {
        std::cout << i << std::endl;
    }
    return 0;
}