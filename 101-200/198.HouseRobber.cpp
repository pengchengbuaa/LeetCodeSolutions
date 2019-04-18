#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int len = nums.size();

    if (len == 0) return 0;
    if (len == 1) return nums[0];
    // the day before the day befoe
    int bb = 0;
    // the day before
    int b = nums[0];

    int newMax;
    for (int i = 1; i < len; i++) {
      newMax = max(bb + nums[i], b);
      bb = b;
      b = newMax;
    }

    return newMax;
  }
};

int main() {
  vector<int> v{2, 7, 9, 3, 1};
  //   vector<int> v{2};
  Solution s;

  cout << s.rob(v) << endl;

  return 0;
}