#include <iostream>
#include <vector>
using namespace std;

int lastOne(int x) { return x & (-x); }

class NumArray {
 public:
  vector<int> sum;
  vector<int> nums_;
  NumArray(vector<int> nums) {
    nums_ = nums;
    int len = nums.size();
    sum = *(new vector<int>(len + 1, 0));
    for (int i = 0; i < len; i++) {
      //   update(i, nums[i]);
      //   int binaryIdx = lastOne(i + 1);
      int binaryIdx = i + 1;
      while (binaryIdx <= len) {
        sum[binaryIdx] += nums[i];
        binaryIdx = binaryIdx + lastOne(binaryIdx);
      }
    }
  }

  void update(int i, int val) {
    int len = nums_.size();
    int idx = i + 1;
    int diff = val - nums_[i];
    nums_[i] = val;

    int binaryIdx = i + 1;
    while (binaryIdx <= len) {
      sum[binaryIdx] += diff;
      binaryIdx = binaryIdx + lastOne(binaryIdx);
    }
  }

  int sumStart(int i) {
    if (i < 0) {
      return 0;
    }

    int binaryIdx = i + 1;

    int tmpsum = 0;
    while (binaryIdx >= 1) {
      tmpsum += sum[binaryIdx];
      binaryIdx -= lastOne(binaryIdx);
    }
    return tmpsum;
  }
  int sumRange(int i, int j) { return sumStart(j) - sumStart(i - 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
  //   auto s = NumArray(vector<int>{1, 3, 5});

  // ["NumArray","sumRange","update","sumRange"]
  // [[[-1]],[0,0],[0,1],[0,0]]
  auto s = NumArray(vector<int>{-1});
  cout << s.sumRange(0, 0) << endl;

  s.update(0, 1);
  cout << s.sumRange(0, 0) << endl;
}
