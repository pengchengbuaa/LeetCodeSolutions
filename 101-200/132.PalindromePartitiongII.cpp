#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{

  public:
    bool isPalind(string s)
    {
        auto l = s.size();
        for (int i = 0; i < l / 2; i++)
        {
            if (s[i] != s[l - i - 1])
                return false;
        }
        return true;
    }

    int minCut(string s)
    {
        auto l = s.size();
        if (l <= 1)
            return 0;
        auto cut = vector<int>(l, 0);

        cut[0] = 0;

        for (int i = 1; i < l; i++)
        {
            if (isPalind(s.substr(0, 1 + i)))
            {
                cut[i] = 0;
                continue;
            }

            int tmpM = 99999;
            for (int j = 1; j <= i; j++)
            {
                if (isPalind(s.substr(j, i - j + 1)))
                {
                    tmpM = min(tmpM, cut[j - 1] + 1);
                }
            }
            cut[i] = tmpM;
        }
        return cut[l - 1];
    }
};


// better:;


//Manancher-like solution

/*
class Solution {
public:
    int minCut(string s) {
        const int N = s.size();
        if(N<=1) return 0;
        
        int i, j, minCUTS[N+1];
        for(i=0; i<=N; ++i) minCUTS[i] = i-1;
        
        for(i=1;i<N;i++)
        {
            for(j=0;(i-j)>=0 && (i+j)<N && s[i-j]== s[i+j]; ++j) // odd-length substrings 
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j]);

            for(j=0;(i-j-1)>=0 && (i+j)<N && s[i-j-1]== s[i+j]; ++j) // even-length substrings
                minCUTS[i+j+1] = min(minCUTS[i+j+1], 1 + minCUTS[i-j-1]);
        }
        return minCUTS[N];
    }
};


*/
int main()
{

    Solution s;

    cout << s.minCut("aab") << endl;

    return 0;
}