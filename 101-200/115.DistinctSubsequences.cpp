#include <string>
#include <iostream>

#include <vector>

using namespace std;
class Solution
{
  public:
    int numDistinct(string s, string t)
    {
        int sl = s.size();
        int tl = t.size();

        if (sl == 0 || tl == 0)
            return 0;
        vector<vector<int>> num = vector<vector<int>>(tl, vector<int>(sl, 0));

        num[0][0] = (s[0] == t[0]);

        for (int j = 1; j < sl; j++)
        {
            num[0][j] = (s[j] == t[0] ? num[0][j - 1] + 1 : num[0][j - 1]);
        }
        for (int i = 1; i < tl; i++)
        {
            int tmpN = 0;
            int j = i;
            for (; j < sl; j++)
            {
                if (num[i - 1][j - 1] == 0)
                    continue;
                else if (t[i] == s[j])
                {
                    num[i][j] = num[i - 1][j - 1];
                    j++;
                    break;
                }
            }
            for (; j < sl; j++)
            {
                num[i][j] = num[i][j - 1];
                if (t[i] == s[j])
                {
                    //When t(i)==s(j)
                    //N[i][j] = N[i-1][j-1] + N[i][j-1]
                    num[i][j] += num[i - 1][j - 1];
                }
            }
        }
        return num[tl - 1][sl - 1];
    }
};

int main()
{

    auto ss = "rabbbit";
    auto ts = "rabbit";

    Solution s;
    cout << s.numDistinct(ss, ts) << endl;
    cout << s.numDistinct("babgbag", "bag") << endl;

    return 0;
}