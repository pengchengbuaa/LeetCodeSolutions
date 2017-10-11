#include<vector>
using namespace std;

class Solution {
public:
    int find(vector<int> & n, int a,int b,int t){
	if(a>b)	return -1;
	if(a==b ){
	    if(n[a]==t)
		return a;
	    else
		return -1;
	}
	int mid = (a+b)/2;
	int res;

	if(n[a]<n[b] && ( t< n[a] || t> n[b]))	    return -1;
	else{
	    res= find(n, a, mid, t);
	    if(res == -1)
		res=find( n, mid+1, b, t);
	    return res;
	}
    }

    int search(vector<int>& nums, int target) {
	int l= nums.size();
	return find(nums,0,l-1,target);
    }
};
