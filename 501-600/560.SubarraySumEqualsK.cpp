#define D
tatic auto _ = []() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    vector<int> sums(nums.size(), 0);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      sums[i] = sum;
    }

    int ans = 0;
    unordered_multiset<int> foundSums;

    foundSums.insert(0);
    for (int i = 0; i < sums.size(); i++) {
      ans += foundSums.count(sums[i] - k);
      foundSums.insert(sums[i]);
    }

    return ans;
  }
};
