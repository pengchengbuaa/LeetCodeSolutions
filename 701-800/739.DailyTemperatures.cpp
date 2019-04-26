class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    int len = T.size();
    vector<int> idxStack;

    deque<int> ans;

    for (int i = len - 1; i >= 0; i--) {
      while (!idxStack.empty() && T[i] >= T[idxStack.back()]) {
        idxStack.pop_back();
      }
      if (idxStack.empty()) {
        ans.push_front(0);
      } else
        ans.push_front(idxStack.back() - i);

      idxStack.push_back(i);
    }

    return vector<int>(ans.begin(), ans.end());
  }
};

static auto _ = []() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();