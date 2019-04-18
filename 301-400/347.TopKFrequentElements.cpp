#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> M;
    // map<int, int> M;
    for (int n : nums) {
      if (M.find(n) != M.end()) {
        M[n]++;

      } else
        M[n] = 1;
    }
    auto cmp = [](pair<int, int> left, pair<int, int> right) {
      return left.second > right.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> Q(
        cmp);
    int cnt = 0;
    for (auto i : M) {
      Q.push(i);
      cnt++;

      if (cnt > k) {
        Q.pop();
        cnt--;
      }
    }
    vector<int> ans;
    while (!Q.empty()) {
      ans.push_back(Q.top().first);
      Q.pop();
    }
    return ans;
  }
};

int main() {
  Solution s;
  // auto ele = vector<int>{1, 1, 1, 2, 2, 3};

  auto ele = vector<int>{4, 1, -1, 2, -1, 2, 3};
  // auto ele = vector<int>{1};
  for (auto e : s.topKFrequent(ele, 2)) {
    cout << e << endl;
  };
  return 0;
}