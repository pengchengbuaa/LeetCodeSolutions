#include <vector>

using namespace std;

class Solution {
    public:
	vector<int>  n;
	void swap(int i, int j){
	    if(i>=(int) n.size() || j>=(int)n.size()) return ;
	    int t=n[i];
	    n[i]=n[j];
	    n[j]=t;
	}
	int firstMissingPositive(vector<int>& nums) {
	    n= nums;
	    sort(n.begin(),n.end());
	    //if not  sorted for instance 3 4 -1 1 
	    //swap 3 and -1 4 and 1 and go to end 
	    //then : -1 1 3 4
	    for(unsigned int i=0;i<n.size();i++){
		if(n[i]>0 && n[i]!=(int)i+1) swap(i,n[i]-1);
	    }
	    for( int i=0; i< (int)n.size();i++){
		if(n[i]!=i+1) return i+1;
	    }
	    return n.size()+1;
	}
};
