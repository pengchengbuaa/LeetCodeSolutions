#include<vector>
using namespace std;
class Solution {
    public:
	vector<vector<int>> ans;
	void find( vector<int> & candi, int  j, int target, vector<int> inpack){
	    if(j<0){
		if(target == 0) ans.push_back(inpack);
		//inpack.push_back(target);
		//ans.push_back(inpack);
		return;
	    }
	    int jj=j;
	    while(jj > 0 && candi[jj-1] == candi[jj]){
		jj--;
	    }
	    find(candi, jj - 1, target, inpack);
	    for( int m = j; target- candi[j]>=0 && m>=jj ;m--){
		target -= candi[j];
		inpack.push_back(candi[j]);
		find(candi, jj-1, target,inpack);
	    }
	}
    public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	    int l = candidates.size();
	    int j = l-1;
	    sort(candidates.begin(),candidates.end());
	    vector<int> inpack;
	    find(candidates, j,target, inpack);
	    return ans;
	}
};
