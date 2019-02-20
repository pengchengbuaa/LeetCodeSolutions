#include <iostream>
#include <vector>
#include <iterator>
using std::cout, std::endl;
using std::vector;

class Solution
{
  public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        auto pf = nums.begin();
        auto pe = nums.begin();
        int tmps = 0;
        int minlen = 0;
        while (tmps < s && pf < nums.end())
        {
            tmps += *pf;
            pf++;
        }

        while (pf != nums.end() || tmps >= s)
        {
            if (tmps >= s)
            {

                if (minlen == 0)
                    minlen = std::distance(pe, pf);
                // minlen = (int)(pf - pe);
                else
                    // minlen = std::min(minlen, (int)(pf - pe));
                    minlen = std::min(minlen, (int)std::distance(pe, pf));
            }
            if (tmps >= s)
            {
                tmps -= *pe;
                pe++;
            }
            else
            {
                tmps += *pf;
                pf++;
            }

            //     if (pf == nums.end() && tmps < s)
            //         break;
        }

        return minlen;
    }
};

int main()
{
    Solution s;
    auto v = vector<int>{2, 3, 1, 2, 4, 3};
    auto vv = vector<int>{1, 1};
    auto vvv = vector<int>{5, 1, 3, 5, 10, 7, 4, 9, 2, 8};

    std::cout << s.minSubArrayLen(7, v) << std::endl;
    std::cout << s.minSubArrayLen(3, vv) << std::endl;
    std::cout << s.minSubArrayLen(15, vvv) << std::endl;
}