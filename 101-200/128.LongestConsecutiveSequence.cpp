#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {

        list<vector<int>> seqs;

        for (int n : nums)
        {
            auto idx1 = seqs.end();
            auto idx2 = seqs.end();
            int isAlreadyIn  = 0;
            for (auto i = seqs.begin(); i != seqs.end(); i++)
            {
                if(n>= (*i)[0] && n<= (*i)[1]) {
                    isAlreadyIn = 1;
                    break;
                }
                if (n + 1 == (*i)[0])
                {

                    (*i)[0]--;
                    idx1 = i;
                }

                if (n - 1 == (*i)[1])
                {
                    (*i)[1]++;
                    idx2 = i;
                }
            }

            if (isAlreadyIn==1){
                continue;
            }
            if (idx1 == seqs.end() && idx2 == seqs.end())
            {
                // int seq[2];
                vector<int> seq;
                seq.push_back(n);
                seq.push_back(n);
                seqs.push_back(seq);
            }

            else if (idx1 != seqs.end() && idx2 != seqs.end())
            {
                (*idx2)[1] = (*idx1)[1];
                seqs.erase(idx1);
            }
        }

        int tmp = 0;
        for (auto s : seqs)
        {
            tmp = max(tmp, abs(s[1] - s[0]) + 1);
        }
        return tmp;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;
    vector<int> a = {100, 4, 200, 1, 3, 2};
    vector<int> a2 = {-6, 8, -5, 7, -9, -1, -7, -6, -9, -7,
                      5, 7, -1, -8, -8, -2, 0};
    cout << s.longestConsecutive(a) << endl;
    cout << s.longestConsecutive(a2) << endl;

    return 0;
}
