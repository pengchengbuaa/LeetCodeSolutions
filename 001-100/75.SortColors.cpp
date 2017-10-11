#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
	int l=nums.size();
	int p0=0;
	int p2=l-1;
	while(nums[p0]==0)  p0++;
	while(nums[p2]==2)  p2--;

	int c=p0;
	//wrong example : 1,2,0,2
	/*
	 * while(c<=p2){
	    if(nums[c]==0)	{
		int t=nums[c];
		nums[c]=nums[p0];
		nums[p0]=t;
		p0++;
	    }
	    else if(nums[c]==2){
		int t=nums[c];
		nums[c]=nums[p2];
		nums[p2]=t;
		p2--;
	    }
	    c++;
	}
	*/
	  while(c<=p2){
	    if(nums[c]==0)	{
		int t=nums[c];
		nums[c]=nums[p0];
		nums[p0]=t;
		p0++;
	    }
	    else if(nums[c]==2){
		int t=nums[c];
		nums[c]=nums[p2];
		nums[p2]=t;
		p2--;
		//key step: c go back to ensure bring back uncertain number 0;
		c--;
	    }
	    c++;
	}
	c=p2;
    }
};
