#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    auto len = nums.size();
    int p1 = len - 1;
    int p2 = len - 1;

    int step = 0;
    while (p1 != p2 || step == 0) {
      p1 = nums[p1] - 1;
      p2 = nums[p2] - 1;
      p2 = nums[p2] - 1;
      step++;
    }

    p1 = len - 1;
    while (nums[p1] != nums[p2]) {
      p1 = nums[p1] - 1;
      p2 = nums[p2] - 1;
    }

    return nums[p1];
  }
};

int main() {
  Solution s;
  //   auto v = vector<int>{3, 1, 3, 4, 2};
  auto v = vector<int>{1, 3, 4, 2, 2};
  cout << s.findDuplicate(v) << endl;
  return 0;
}