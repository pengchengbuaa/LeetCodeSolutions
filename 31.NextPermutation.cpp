#include<vector>
using namespace std;


class Solution {
public:
    void swap (vector<int> & ns , int i , int j){
	int t = ns[i];
	ns[i] = ns[j];
	ns[j] = t;
    }

    void nextPermutation(vector<int>& nums) {
	int l = nums.size();
	if(l<2)
	    return;
	int firstDes= 0;
	for( int i = l-1; i>0 ;i--){
	    if(nums[i]>nums[i-1])
	    {
		firstDes= i;
		break;
	    }
	}
	if(firstDes==0){
	    ;
	}
	else{
	    if(nums[firstDes -1 ]< nums[l-1]){
		swap(nums, l-1, firstDes-1);
	    }
	    else{
		for(int j =firstDes;j<l-1;j++){
		    if(nums[j]>nums[firstDes-1] && nums[j+1]<=nums[firstDes-1]){
			swap(nums, j , firstDes-1);
			break;
		    }
		}
	    }
	}
	sort(nums.begin()+firstDes, nums.begin() + l);
    }
};
