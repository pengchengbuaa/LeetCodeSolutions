#include<vector>
using namespace std;

class Solution {

    public:
	vector<vector<int>> ans;
    public:
	vector<int> insert (vector<int> ve,int p,int v){
	    vector <int> ne;
	    for(int i=0;i<p;i++){
		ne.push_back(ve[i]);
	    }
	    ne.push_back(v);
	    for(int i=p; i<(int) ve.size();i++){
		ne.push_back(ve[i]);
	    }
	    return ne;
	}
	void per(vector<vector<int>>  already, int n, vector<int>&nums){
	    if(n == (int)nums.size()) ans.assign(already.begin(),already.end());
	    else{
		vector<vector<int>> newal;
		int newi = nums[n];
		for(unsigned int i=0;i<already.size();i++){
		    vector<int> oldv=already[i];
		    for(unsigned int j = 0;j <= oldv.size();j++){
			newal.push_back(insert(oldv, j,newi));
		    }
		}
		per(newal,n+1,nums);
	    }
	}

    public:
	vector<vector<int>> permute(vector<int>& nums) {
	    if(nums.size()==0) return ans;
	    vector<vector<int>> v;
	    vector<int> vv;
	    vv.push_back(nums[0]);
	    v.push_back(vv);

	    per(v,1,nums);
	    return ans;
	}
};
