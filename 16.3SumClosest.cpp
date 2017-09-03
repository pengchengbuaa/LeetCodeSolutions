#include<vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(),nums.end());
	int n = nums.size();
	int closestGap = INT_MAX;
	int sum;


	int b,c;
	int gap = INT_MAX;
	for(int a=0 ;a <n-2; a++){
	    b = a+1;
	    c = n-1;
	    while(gap && b<c){
		gap = nums[a]+nums[b]+nums[c] - target;	
		if(gap ==0){
		    sum = target;
		}
		else if( gap > 0){
		    c--;
		}
		else{
		    b++;
		}
		if(gap>=0 && gap<closestGap){
		    sum = gap + target;
		    closestGap = gap;
		}
		else if(gap<0 && -gap <closestGap){
		    sum = gap + target;
		    closestGap = -gap;
		}
	    }
	}

	return sum;
    }
};
