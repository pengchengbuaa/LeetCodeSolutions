#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int l = nums.size();
	int lo =  0;
	int hi = l-1;
	int mid;
	while( lo< hi){
	    mid = (lo+ hi)/2;
	    if(nums[mid] ==  0 ) { mid ++; break;}
	    else if( nums[mid] <= 0)	lo = mid+1;
	    else hi =  mid;
	}
	if(nums[mid] != 1) return 1;

	lo = mid;
	hi = l-1;
	while(lo < hi-1){
	    mid = (lo + hi)/2;
	    if(nums[mid]- nums[lo] < mid- lo)	hi=mid;
	    else lo =mid;
	}
	return nums[lo]+1;
    }
};
