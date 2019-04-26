class Solution {
 public:
  int countSubstrings(string s) {
    int len = s.size();

    int parCnt = len;
    vector<bool> dpEven(len, false);
    vector<bool> dpOdd(len, true);

    for (int i = 0; i + 2 - 1 < len; i++) {
      if (s[i] == s[i + 1]) {
        dpEven[i] = true;
        parCnt++;
      }
    }

    int parlen = 3;

    while (parlen <= len) {
      if (parlen % 2) {
        for (int i = 0; i + parlen - 1 < len; i++) {
          if (dpOdd[i + 1] && s[i] == s[i + parlen - 1]) {
            dpOdd[i] = true;
            parCnt++;
          } else {
            dpOdd[i] = false;
          }
        }
      } else {
        for (int i = 0; i + parlen - 1 < len; i++) {
          if (dpEven[i + 1] && s[i] == s[i + parlen - 1]) {
            dpEven[i] = true;
            parCnt++;
          } else {
            dpEven[i] = false;
          }
        }
      }
      parlen++;
    }

    return parCnt;
  }
};

static auto _ = []() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();