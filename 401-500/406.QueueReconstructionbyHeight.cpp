class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    auto p = [](vector<int>& a, vector<int>& b) {
      if (b[0] != a[0])
        return b[0] < a[0];
      else
        return b[1] > a[1];
    };

    sort(people.begin(), people.end(), p);

    vector<vector<int>> anslist;
    for (auto p : people) {
      anslist.insert(anslist.begin() + p[1], p);
    }

    return anslist;
  }
};
