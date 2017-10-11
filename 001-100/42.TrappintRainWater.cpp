#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
	int l = height.size();
	if(l <= 2) return 0;
	vector<int> lm (l,0);
	vector<int> rm (l,0);
	lm[0]=0;
	rm[l-1]=0;
	for( int i =1;i<l;i++){
	    lm [i]= max(lm[i-1],height[i-1]);
	}
	for(int j = l-2;j>=0;j--){
	    rm [j] = max(rm[j+1],height[j+1]);
	}
	int sum = 0 ;
	for (int k = 1;k <l;k ++){
	    int lim= min(rm[k],lm[k]);
	    if(height[k]<lim)
	    sum += lim - height[k];
	}
	return sum;
    }
};
