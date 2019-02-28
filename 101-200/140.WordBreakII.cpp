#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canBreak(string s, vector<string>& wordDict) {
    int n = s.size();

    set<string> dict;
    for (auto w : wordDict) dict.insert(w);

    vector<bool> dp(n + 1, false);
    dp[0] = true;  // You can make empty string with any wordDict

    // From every i position check if you can make word ending here
    for (int i = 0; i < n; i++) {
      // If we can makem a word from j->i
      // We need to check if we can make a word till j first
      for (int j = i; j >= 0; j--) {
        string curr = s.substr(j, i - j + 1);  // pos,noOfChars

        if (dict.find(curr) != dict.end())
          dp[i + 1] =
              dp[i + 1] ||
              dp[j];  // dp[j] means can be make words before j(dp is 1 indexed)

        if (dp[i + 1]) break;
      }
    }

    return dp[n];
  }

  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    auto dp = vector<vector<string>>(len, vector<string>(0));

    if (!canBreak(s, wordDict)) return dp[0];

    for (int i = 0; i < len; i++) {
      for (auto w : wordDict) {
        if (i < w.size() - 1) {
          continue;
        }

        if (s.substr(i - w.size() + 1, w.size()) == w) {
          if (i - w.size() + 1 == 0) {
            dp[i].push_back(w);
            continue;
          }
          for (auto lstv : dp[i - w.size()]) {
            lstv.append(" ");
            // lstv.append(w);
            dp[i].push_back(lstv.append(w));
          }
        }
      }
    }
    return dp[len - 1];
  }
};

int main() {
  auto s = "catsanddog";
  vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  auto s2 = "pineapplepenapple";
  vector<string> wordDict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
  Solution so;

  auto s3 =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaa";
  vector<string> wordDict3 = {"a",         "aa",        "aaa",     "aaaa",
                              "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                              "aaaaaaaaa", "aaaaaaaaaa"};

  // auto ans = so.wordBreak(s, wordDict);
  auto ans2 = so.wordBreak(s3, wordDict3);
  // for (auto n : ans) {
  //   cout << n << endl;
  // }
  for (auto n : ans2) {
    cout << n << endl;
  }

  return 0;
}