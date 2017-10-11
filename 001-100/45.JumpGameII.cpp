#include<vector>
using namespace std;

class Solution {
    public:
	int jump(vector<int>& nums) {
	    int len = nums.size();
	    if(len == 0)
		return 0;
	    int lo = 0;
	    int hi = 0;
	    int jump = 0;
	    int farest;
	    while( hi< len-1)
	    {
		farest = hi;
		for( int i=lo ;i<= hi;i++){
		    farest = max (farest , nums[i]+i);
		}
		jump++;
		lo=hi+1;
		hi=farest;
	    }
	    return jump;

	}
};
