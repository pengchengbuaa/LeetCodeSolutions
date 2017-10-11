#include<vector>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
	int far=0;
	int t;
	int l=nums.size();
	for(int i=0;i<l;i++){
	    if(i>far)	return false;
	    t=nums[i]+i;
	    if(t>far)	far=t;
	}
	return true;
    }
};
