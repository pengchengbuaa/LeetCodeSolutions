#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int sqrFunc(int n, vector<int>& dp) {
    int sqr = sqrt(n);
    int mimN = INT_MAX;

    if (n == 1 || n == 0) return n;

    if (dp[n] != 0) {
      return dp[n];
    }
    for (auto i = sqr; i > 0; i--) {
      mimN = min(1 + sqrFunc(n - i * i, dp), mimN);
    }
    dp[n] = mimN;

    return mimN;
  }

  int numSquares(int n) {
    auto dp = vector<int>(n + 1, 0);

    return sqrFunc(n, dp);
  }
};

int main() {
  Solution s;
  cout << s.numSquares(13103) << endl;
}