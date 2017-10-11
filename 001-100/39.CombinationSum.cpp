#include<vector>
using namespace std;
class Solution {
    public:
	vector<vector<int>> ans;
	void find( vector<int> & candi, int  j, int target, vector<int> inpack){
	    if(j<0){
		if(target == 0) ans.push_back(inpack);
		return;
	    }
	    find(candi, j - 1, target, inpack);
	    target -= candi[j];
	    while(target >= 0){
		inpack.push_back(candi[j]);
		find( candi, j - 1, target, inpack);
		target -= candi[j];
	    }
	}
    public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	    int l = candidates.size();
	    int j = l-1;
	    sort(candidates.begin(),candidates.end());
	    vector<int> inpack;
	    find(candidates, j,target, inpack);
	    return ans;
	}
    };
