#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int pN = primes.size();
    auto counters = vector<int>(pN, 0);
    vector<int> numbers;
    numbers.push_back(1);
    int minProd;
    int minIdx;
    long long tmpN;
    while (n - 1 > 0) {
      minProd = INT32_MAX;
      minIdx = -1;
      for (auto i = 0; i < pN; i++) {
        tmpN = primes[i] * numbers[counters[i]];

        while (tmpN <= numbers.back()) {
          counters[i]++;
          tmpN = primes[i] * numbers[counters[i]];
        }
        if (tmpN <= numbers.back()) {
          counters[i]++;
          continue;
        }
        if (tmpN < minProd) {
          minProd = tmpN;
          minIdx = i;
        }
      }
      n--;
      numbers.push_back(minProd);
      counters[minIdx]++;
    }

    return numbers.back();
  }
};

int main() {
  int n = 45;
  // int n = 12;

  auto primes = vector<int>{2, 3, 7, 13, 17, 23, 31, 41, 43, 47};
  // auto primes = vector<int>{2, 7, 13, 19};

  Solution s;
  cout << s.nthSuperUglyNumber(n, primes) << endl;
}