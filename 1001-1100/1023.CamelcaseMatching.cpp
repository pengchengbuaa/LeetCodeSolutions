#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool islower(char c) {
    if (c >= 'a' && c <= 'z') return true;
    return false;
  }
  bool matchone(string q, string p) {
    int qs = q.size();
    int ps = p.size();
    int qp = 0;
    int pp = 0;

    for (qp = 0; qp != qs;) {
      if (pp != ps && q[qp] == p[pp]) {
        pp++;
        qp++;
      } else if (islower(q[qp])) {
        qp++;
      } else {
        return false;
      }
    }

    if (pp == ps) return true;
    return false;
  }

  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;
    for (auto q : queries) {
      ans.push_back(matchone(q, pattern));
    }
    return ans;
  }
};

int main() {
  //   vector<string> queries = {"FooBar", "FooBarTest", "FootBall",
  //   "FrameBuffer",
  // "ForceFeedBack"};
  //   string pattern = "FoBaT";

  vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
                            "ForceFeedBack"};
  string pattern = "FB";
  Solution s;
  auto ans = s.camelMatch(queries, pattern);
  for (auto a : ans) {
    cout << a << endl;
  }

  return 0;
}