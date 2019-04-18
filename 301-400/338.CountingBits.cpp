#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int num) {
    auto dp = vector<int>(num + 1, 0);
    for (int i = 0; i < num + 1; i++) {
      dp[i] = dp[i >> 1] + i % 2;
    }
    return dp;
  }
};

int main() {
  Solution s;
  for (auto a : s.countBits(1)) {
    cout << a << endl;
  }
  return 0;
}