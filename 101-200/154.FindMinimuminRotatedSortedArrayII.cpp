#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int l = nums.size();
        int s = 0;
        int e = l - 1;

        if (l == 0)
            return 0;
        if (nums[s] < nums[e] || l == 1)
            return nums[s];

        while (nums[s + 1] == nums[s])
            s++;

        while (nums[e - 1] == nums[e])
            e--;

        if (s >= e)
        {
            return nums[0];
        }
        int mid = (s + e) / 2;

        while (nums[mid] <= nums[mid + 1])
        {
            if (nums[mid] >= nums[s])
            {
                s = mid;
            }
            else

                e = mid;

            mid = (s + e) / 2;
        }

        return nums[mid + 1];
    }
};

int main()
{
    Solution s;
    auto v = vector<int>{4, 5, 6, 7, 0, 1, 2};
    auto v1 = vector<int>{0, 1, 2};
    auto v2 = vector<int>{2, 2, 2, 0, 2, 2, 2, 2, 2};
    auto v3 = vector<int>{4, 2};

    cout << s.findMin(v) << endl;
    cout << s.findMin(v1) << endl;
    cout << s.findMin(v2) << endl;
    cout << s.findMin(v3) << endl;

    return 0;
}