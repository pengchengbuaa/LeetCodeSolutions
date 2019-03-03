#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 1) return nums;
    deque<int> indxs(1, 0);
    vector<int> ans;
    for (int i = 1; i < nums.size(); i++) {
      if (!indxs.empty() && indxs.front() <= i - k) indxs.pop_front();
      while (!indxs.empty() && nums[indxs.back()] <= nums[i]) indxs.pop_back();
      indxs.push_back(i);
      if (i >= k - 1) ans.push_back(nums[indxs.front()]);
    }
    return ans;
  }
};

static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

int main() {
  Solution s;

  //   auto nums = vector<int>{1, 3, -1, -3, 5, 3, 6, 7};
  auto nums = vector<int>{1, 1, 01, -1};
  //   int k = 3;
  int k = 2;
  auto ans = s.maxSlidingWindow(nums, k);
  for (auto a : ans) {
    cout << a << endl;
  }
  return 0;
}