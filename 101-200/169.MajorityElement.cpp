
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return -1;
    if (len == 1) return nums[0];

    int tmpMax = nums[0];
    int cnt = 1;
    for (int i = 1; i < len; i++) {
      if (nums[i] == tmpMax) {
        cnt++;
      } else {
        cnt--;
        if (cnt == 0) {
          if (i == len - 1) return -1;
          tmpMax = nums[i + 1];
          i++;
          cnt++;
        }
      };
    }
    return tmpMax;
  }
};

int main() {
  Solution s;
  vector<int> ele{2, 2, 1, 1, 1, 2, 2};

  //   vector<int> ele{3, 3, 4};
  cout << s.majorityElement(ele) << endl;
}