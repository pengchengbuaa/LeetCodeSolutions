#include<vector>
using namespace std;



/*
int threeSumClosest(vector<int> &num, int target) {        
    vector<int> v(num.begin(), num.end()); // I didn't wanted to disturb original array.
    int n = 0;
    int ans = 0;
    int sum;
    
    sort(v.begin(), v.end());
    
    // If less then 3 elements then return their sum
    while (v.size() <= 3) {
        return accumulate(v.begin(), v.end(), 0);
    }
    
    n = v.size();
    
    ans = v[0] + v[1] + v[2];
    for (int i = 0; i < n-2; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            sum = v[i] + v[j] + v[k];
            if (abs(target - ans) > abs(target - sum)) {
                ans = sum;
                if (ans == target) return ans;
            }
            (sum > target) ? k-- : j++;
        }
    }
    return ans;
}

*/
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
