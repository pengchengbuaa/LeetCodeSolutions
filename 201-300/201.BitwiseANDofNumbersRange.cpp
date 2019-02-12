#include <iostream>

class Solution
{
  public:
    int rangeBitwiseAnd(int m, int n)
    {
        int ans = 0;
        int andm = 0;
        int andn = 0;
        for (int i = 30; i >= 0; i--)
        {
            andm = (1 << i) & m;
            andn = (1 << i) & n;
            if (andm == andn)
            {
                ans = ans | andm;
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    int m = 0;
    int n = 1;
    Solution s;
    std::cout << s.rangeBitwiseAnd(m, n) << std::endl;
    return 0;
}