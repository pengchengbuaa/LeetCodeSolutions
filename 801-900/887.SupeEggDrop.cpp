#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  // K eggs , N floors
  int superEggDrop(int K, int N) {
    vector<int> vec1(K + 1, 0);
    vector<int> vec2(K + 1, 0);

    for (int i = 1; i <= K; i++) {
      vec1[i] = 1;
    }

    vector<int>* pNew;
    vector<int>* pOld;
    vector<int>* ptmp;
    pNew = &vec1;
    pOld = &vec2;
    int Move = 1;
    while (true) {
      if ((*pNew)[K] >= N) return Move;
      Move++;
      ptmp = pNew;
      pNew = pOld;
      pOld = ptmp;

      (*pNew)[1] = Move;
      for (auto e = 2; e <= K; e++) {
        (*pNew)[e] = (*pOld)[e] + (*pOld)[e - 1] + 1;
      }
    }
  }
};

int main() {
  Solution s;
  cout << s.superEggDrop(1, 2) << endl;
  cout << s.superEggDrop(2, 6) << endl;
  cout << s.superEggDrop(10, 6) << endl;
  cout << s.superEggDrop(3, 14) << endl;
  cout << s.superEggDrop(1, 100) << endl;
  cout << s.superEggDrop(100, 100) << endl;
  cout << s.superEggDrop(100, 1) << endl;
  cout << s.superEggDrop(6, 5000) << endl;

  return 0;
}