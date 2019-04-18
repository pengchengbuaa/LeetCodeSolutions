#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return -1;
    if (len == 1) return nums[0];

    int minProd = nums[0];
    int maxProd = nums[0];

    int minProdBef = minProd;
    int maxProdBef = maxProd;

    int tmp1;
    int tmp2;
    for (int i = 1; i < len; i++) {
      tmp1 = min(nums[i], min(minProdBef * nums[i], maxProdBef * nums[i]));
      tmp2 = max(nums[i], max(minProdBef * nums[i], maxProdBef * nums[i]));

      minProdBef = tmp1;
      maxProdBef = tmp2;

      maxProd = max(maxProd, maxProdBef);
      minProd = min(minProd, minProdBef);
    }

    return maxProd;
  }
};

int main() {
  Solution s;
  //   vector<int> v{2, 3, -2, 4};
  vector<int> v{-2, 0, 1};
  //   vector<int> v{0, 2};
  cout << s.maxProduct(v) << endl;
  return 0;
}