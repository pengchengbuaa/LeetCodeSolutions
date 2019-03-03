#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();

    if (len == 0) return vector<int>();
    if (len == 1) return vector<int>(1, 0);

    vector<int> tmp(len, 0);

    int tmpProd = 1;
    for (int i = 0; i < len - 1; i++) {
      tmpProd *= nums[i];
      tmp[i] = tmpProd;
    }

    tmpProd = 1;
    for (int i = len - 1; i > 0; i--) {
      tmp[i] = tmp[i - 1] * tmpProd;
      tmpProd *= nums[i];
    }

    tmp[0] = tmpProd;

    return tmp;
  }
};

int main() {
  Solution s;
  vector<int> a = vector<int>{};
  auto ans = s.productExceptSelf(a);
  for (auto a : ans) {
    cout << a << endl;
  }
  return 0;
}