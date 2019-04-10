#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:

  int numSquares(int n) {
    if (n == 1 || n == 0) return n;
    int sqr = sqrt(n);
    vector<int>* bfs1 = new vector<int>;
    vector<int>* bfs2 = new vector<int>;
    vector<int> sqrs;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= sqr; i++) {
      sqrs.push_back(i * i);
    }

    int nc = 1;
    for (auto s : sqrs) {
      if (s == n) return nc;
      bfs1->push_back(s);
      visited[s] = true;
    }

    while (true) {
      for (auto b : *bfs1) {
        for (auto s : sqrs) {
          if (b + s == n) return nc + 1;
          if (b + s <= n && !visited[b + s]) {
            bfs2->push_back(b + s);
            visited[b + s] = true;
          }
        }
      }
      auto tmp = bfs1;
      bfs1 = bfs2;
      bfs2 = tmp;
      bfs2->clear();
      nc++;
    }
    return 0;
  }
};

int main() {
  Solution s;
  cout << s.numSquares(13103) << endl;
  cout << s.numSquares(0) << endl;
  cout << s.numSquares(2) << endl;
}