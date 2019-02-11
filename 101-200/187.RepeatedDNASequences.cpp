#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <iostream>
using std::deque;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
class Solution
{
  private:
    unordered_map<char, int> C2I =
        {{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};

    unordered_map<int, char> I2C =
        {{0, 'A'}, {1, 'G'}, {2, 'C'}, {3, 'T'}};

    inline int stringtoint(string::iterator b, string::iterator e)
    {
        int sum = 0;
        for (auto i = b; i != e; i++)
        {
            sum = sum * 4 + C2I[*i];
        }
        return sum;
    }

  public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        int len = s.size();
        if (len < 10)
            return ans;
        auto reading = s.begin() + 10;
        unordered_map<int, int> cnt;
        int n;
        int base = 1024 * 1024;
        n = stringtoint(s.begin(), reading);
        while (reading != s.end() + 1)
        {

            cnt[n]++;

            n = n * 4 % base + C2I[*reading];
            reading++;
        }

        string a;
        for (auto ct : cnt)
        {
            n = ct.first;
            if (ct.second == 1)
                continue;
            a = "";
            for (int i = 0; i < 10; i++)
            {
                a.push_back(I2C[n % 4]);
                n = n / 4;
            }
            ans.push_back(a);
        }
        return ans;
    }
};

int main()
{
    // auto s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto s = "AAAAAAAAAAA";
    Solution so;

    // auto ans = so.findRepeatedDnaSequences(s);
    auto ans = so.findRepeatedDnaSequences(s);

    for (auto ann : ans)
    {
        std::cout << ann << std::endl;
    }
    return 0;
}