#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
// #include <map>
// #include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    unordered_map<int, unordered_set<int>> G;
    vector<int> CourseInDeg(numCourses, 0);

    for (auto eg : prerequisites) {
      CourseInDeg[eg.first]++;

      G[eg.second].insert(eg.first);
    }
    // first implementation TOPO SORT
    //     while (upper_bound(CourseInDeg.begin(), CourseInDeg.end(), 0) !=
    //            CourseInDeg.end()) {
    //       int processingCourse = -1;
    //       for (int i = 0; i < numCourses; i++) {
    //         if (CourseInDeg[i] == 0 && !G[i].empty()) processingCourse = i;
    //       }

    //       if (processingCourse == -1) return false;

    //       for (int c : G[processingCourse]) {
    //         CourseInDeg[c]--;
    //       }
    //       G[processingCourse].clear();
    //     }

    //     return true;

    // second implementation :DFS
    auto processing = CourseInDeg.begin();
    while (processing = find(CourseInDeg.begin(), CourseInDeg.end(), 0),
           processing != CourseInDeg.end()) {
      for (int c : G[processing - CourseInDeg.begin()]) {
        CourseInDeg[c]--;
      }
      *processing = -1;
    }

    for (auto in : CourseInDeg) {
      if (in > 0) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  int nC = 2;
  //   auto pre = vector<pair<int, int>>{{1, 0}, {0, 1}};
  auto pre = vector<pair<int, int>>{{1, 0}};

  cout << s.canFinish(nC, pre) << endl;
}