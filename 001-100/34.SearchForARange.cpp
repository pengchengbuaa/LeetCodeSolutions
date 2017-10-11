#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
	int l = 0;
	int h =  len-1;
	int m = (l+h)/2;
	if(len==0 || (len==1  && nums[0]!=target))
	    return vector<int> (2 , -1);
	if(len==1)
	    return vector<int>( 2,0);

	while(l<h){
	    if(nums[m]== target) break;
	    if( nums[m]> target) h = m-1;
	    else l=m+1;
	    m=(l+h)/2;
	}
	if(nums[m]!=target)
	    return vector<int> (2,-1);
	else{
	    int lb = m;
	    int hb = m;
	    int lm = (l+lb)/2;
	    int hm = (h + hb)/2;
	    while(l<lb){
		if ( nums[lm]<nums[m]){
		    l=lm+1;
		}
		else{
		    lb=lm;
		}
		lm=(l+lb)/2;
	    }
	    while(h>hb){
		if( nums[hm]>nums[m]){
		    h = hm-1;
		}
		else{
		    hb = hm;
		}
		hm = (h+1  + hb)/2;
	    }
	    vector<int> r;
	    r.push_back(lb);
	    r.push_back(hb);
	    return r;
	}
    }
};
