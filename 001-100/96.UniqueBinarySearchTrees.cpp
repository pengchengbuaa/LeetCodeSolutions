#include<vector>
using namespace std;
class Solution {
public:

    int numTrees(int n) {
	vector<int> an(n+1,0);
	an[0]=1;
	an[1]=1;
	for(int i=2;i<=n;i++){
	    for(int j=1;j<=i;j++){
		an[i]+=an[j-1]*an[i-j];
	    }
	}
	return an[n];
    }
};
