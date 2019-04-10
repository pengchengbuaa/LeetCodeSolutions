
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int len = nums.size();

    vector<int> newNums = {1};
    newNums.insert(newNums.end(), nums.begin(), nums.end());
    newNums.push_back(1);

    auto dp = vector<vector<int>>(len + 2, vector<int>(len + 2, 0));

    for (int l = 1; l <= len; l++) {
      if (l == 1) {
        for (int st = 1; st <= len; st++) {
          dp[st][st] = newNums[st] * newNums[st - 1] * newNums[st + 1];
          // cout << st << "\t" << st << "\t" << dp[st][st] << endl;
        }
      }

      //   dp[0][0] = 1;
      //   dp[len + 1][len + 1] = 1;

      else {
        for (int st = 1; st <= len - l + 1; st++) {
          int maxprod = 0;
          int ed = st + l - 1;
          //   int ed = len - l + 1;

          for (int lastB = st; lastB <= ed; lastB++) {
            int prod = dp[st][lastB - 1] + dp[lastB + 1][ed] +
                       newNums[lastB] * newNums[st - 1] * newNums[ed + 1];
            maxprod = max(prod, maxprod);
          }
          dp[st][ed] = maxprod;
          // cout << st << "\t" << ed << "\t" << dp[st][ed] << endl;
        }
      }
    }

    return dp[1][len];
  }
}

;

int main() {
  Solution s;
  vector<int> a = {3, 1, 5, 8};
  cout << s.maxCoins(a) << endl;
}