#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool divisorGame(int N) {
    vector<bool> dp(N + 1, false);

    if (N == 0 || N == 1) return false;
    // if (N == 2) return true;
    dp[2] = true;
    for (int i = 3; i <= N; i++) {
      for (int divident = 1; divident < i; divident++) {
        if (i % divident == 0) {
          if (!dp[i - divident]) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[N];
  }
};

int main() {
  Solution s;

  cout << s.divisorGame(2) << endl;
  return 0;
}