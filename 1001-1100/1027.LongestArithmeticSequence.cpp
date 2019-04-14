#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestArithSeqLength(vector<int>& A) {
    int len = A.size();
    if (len <= 2) return len;
    int ans = 2;

    // map <distance , <endidx, len >>
    unordered_map<int, unordered_map<int, int>> dp;

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        int dis = A[j] - A[i];
        if (dp.find(dis) != dp.end() && dp[dis].find(i) != dp[dis].end()) {
          dp[dis][j] = dp[dis][i] + 1;
        } else {
          dp[dis][j] = 2;
        }
      }
    }

    for (auto m : dp) {
      for (auto mm : m.second) {
        ans = max(ans, mm.second);
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> d{20, 1, 15, 3, 10, 5, 8};
  //   vector<int> d{2, 4, 6, 8};

  //   vector<int> d{9, 4, 7, 2, 10};
  cout << s.longestArithSeqLength(d) << endl;
  return 0;
}