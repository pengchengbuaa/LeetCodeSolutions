#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsdfs(vector<int>& nums, int start, int end) {
    vector<vector<int>> ans;

    if (start == end) {
      ans.push_back(vector<int>());
      return ans;
    }

    for (auto a : subsetsdfs(nums, start, end - 1)) {
      ans.push_back(a);
      a.push_back(nums[end - 1]);
      ans.push_back(a);
    };

    return ans;
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    return subsetsdfs(nums, 0, nums.size());
  }
};
int main() {
  Solution s;
  vector<int> a{1, 2, 3};
  for (auto a : s.subsets(a)) {
    for (auto i : a) {
      cout << i << " ";
    }
    cout << " e" << endl;
  }
  return 0;
}