#include<vector>
using namespace std;
class Solution {
public:

    int getH(int n,vector<int> & heights){
	if(n==-1)   return 0;
	else	return heights[n];
    }
    int largestRectangleArea(vector<int>& heights) {
	int l=heights.size();
	int Ma=0;
	heights.push_back(0);
	vector<int> & h=heights;
	vector<int>stk(1,-1);
	stk.push_back(0);

	int hh;
	for(int i=1;i<=l;i++){
	    while(stk.size()>=1 && getH(i,h)<getH(stk.back(),h)){
		hh = getH(stk.back(),h);
		stk.pop_back();
		Ma=max(Ma ,hh*( i-stk.back()-1));
	    }
	    if(stk.size() && getH(i,h)>=getH(stk.back(),h))		stk.push_back(i);
	}
	return Ma;
    }
};
