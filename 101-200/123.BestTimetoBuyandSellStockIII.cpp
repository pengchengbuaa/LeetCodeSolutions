#include <vector>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        auto len = prices.size();
        vector<int> P1 = vector<int>(len);
        vector<int> P2 = vector<int>(len);

        if (len < 2)
            return 0;
        vector<int> MinBefore = vector<int>(len);
        vector<int> MaxAfter = vector<int>(len);
        MinBefore[0] = prices[0];
        P1[0] = 0;
        for (int i = 1; i < len; i++)
        {
            MinBefore[i] = min(prices[i], MinBefore[i - 1]);
            P1[i] = max(P1[i - 1], prices[i] - MinBefore[i]);
        }

        MaxAfter[len - 1] = prices[len - 1];
        P1[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--)
        {
            MaxAfter[i] = max(prices[i], MaxAfter[i + 1]);
            P2[i] = max(P2[i + 1], MaxAfter[i] - prices[i]);
        }
        int tmpMax = 0;
        for (int i = 0; i < len; i++)
        {
            tmpMax = max(tmpMax, P1[i] + P2[i]);
        }
        return tmpMax;
    }
};

int main()
{

    vector<int> p = {3,  5};

    Solution s;
    cout << s.maxProfit(p) << endl;

    return 0;
}
