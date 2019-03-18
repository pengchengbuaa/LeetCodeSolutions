#include <iostream>
#include <vector>
using namespace std;

// class Solution {
//  public:
//   int maxProfit(vector<int>& prices) {
//     int len = prices.size();
//     if (len <= 1) return 0;
//     vector<int> dp(len, 0);
//     // max profit of day[0, i]

//     int tmpmax;
//     int maxSeen;
//     for (int i = 1; i < len; i++) {
//       // with dp [0, j] calculate the new Profit[0, i] with a new transaction
//       tmpmax = dp[i - 1];
//       maxSeen = prices[i];
//       // try every j if new transaction happened in [j, i]  j value in [0,
//       i-1] for (int j = i - 1; j >= 0; j--) {
//         maxSeen = max(prices[j + 1], maxSeen);
//         if (j <= 1)
//           tmpmax = max(tmpmax, maxSeen - prices[j]);
//         else
//           tmpmax = max(tmpmax, maxSeen - prices[j] + dp[j - 2]);
//       }
//       dp[i] = tmpmax;
//     }
//     return dp[len - 1];
//   }
// };

// thinking in state machine 3 state empty, hold, coolDown

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;
    int empty = 0;
    int hold = 0;
    int coolDown = 0;

    int newEmpty;
    int newHold;
    int newCoolDown;

    hold = -prices[0];

    for (auto i = 1; i < len; i++) {
      newEmpty = max(empty, coolDown);
      newHold = max(hold, empty - prices[i]);
      newCoolDown = max(hold + prices[i], coolDown);

      empty = newEmpty;
      hold = newHold;
      coolDown = newCoolDown;
    }

    return max(empty, coolDown);
  }
};

int main() {
  Solution s;

  auto d = vector<int>{1, 2, 3, 0, 2};
  cout << s.maxProfit(d) << endl;
  return 0;
}