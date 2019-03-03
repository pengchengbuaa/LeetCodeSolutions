#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    if (n <= 0) return 0;
    vector<int> ns;

    while (n) {
      ns.push_back(n % 10);
      n /= 10;
    }

    // reverse(ns.begin(), ns.end());

    int len = ns.size();
    // dp [1] means number of 1s in 1-> 10^1 -1 [1 - 10)
    // dp [2] means number of 1s in 1-> 10^2 -1 [10 - 100)
    auto dp = vector<long>(len + 1, 0);
    dp[1] = 1;
    for (int i = 2; i < len + 1; i++) {
      dp[i] = 10 * dp[i - 1] + pow(10, i - 1);
    }

    // 5149 i from 4 to 1
    long sum = 0;
    bool islast1 = false;

    for (int hi = len; hi > 0; hi--) {
      if (islast1) {
        int cnt = 0;
        for (int i = hi; i > 0; i--) {
          cnt = cnt * 10;
          cnt += ns[i - 1];
        }
        sum += cnt + 1;
      }
      if (ns[hi - 1] == 0) {
        islast1 = false;
        continue;
      }
      if (ns[hi - 1] == 1) {
        islast1 = true;
        sum += dp[hi - 1];
      } else {
        islast1 = false;
        sum += dp[hi - 1] * ns[hi - 1];

        sum += pow(10, hi - 1);
      }
    }
    if (islast1) sum++;
    return sum;
  }
};

int main() {
  Solution s;
  cout << s.countDigitOne(0) << endl;
  cout << s.countDigitOne(13) << endl;
  cout << s.countDigitOne(111) << endl;
  cout << s.countDigitOne(110) << endl;
  cout << s.countDigitOne(1) << endl;
  cout << s.countDigitOne(1410065408) << endl;
  return 0;
}