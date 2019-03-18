#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> vecOp(vector<int> v1, vector<int> v2, char op) {
    // set<int> ans;
    vector<int> ans;
    for (auto a1 : v1) {
      for (auto a2 : v2) {
        if (op == '*')
          ans.push_back(a1 * a2);
        else if (op == '-')
          ans.push_back(a1 - a2);
        else
          ans.push_back(a1 + a2);
      }
    }
    return ans;
  }
  vector<int> recur(string input, unordered_map<string, vector<int>>& m) {
    if (m.find(input) != m.end()) {
      return m[input];
    }

    vector<int> ans;
    bool hasOp = false;
    for (auto i = 0; i < input.size(); i++) {
      if (input[i] == '*' || input[i] == '-' || input[i] == '+') {
        hasOp = true;
        string left = input.substr(0, i);
        string right = input.substr(i + 1, input.size() - i - 1);
        vector<int> leftans = recur(left, m);
        vector<int> rightans = recur(right, m);

        m[left] = leftans;
        m[right] = rightans;
        auto tmpans = vecOp(leftans, rightans, input[i]);
        ans.insert(ans.end(), tmpans.begin(), tmpans.end());
      }
    }
    if (!hasOp && input.size() != 0) {
      ans.push_back(stoi(input));
    }
    return ans;
  }

  vector<int> diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> m;

    return recur(input, m);
  }
};

int main() {
  string ip = "2*3-4*5";

  Solution s;

  for (auto a : s.diffWaysToCompute(ip)) {
    cout << a << endl;
  }
}
