#include <vector>
#include <string>
using namespace std;


class Solution {
    public:
	bool isMatch(string s, string p) {
	    int ls=s.size();
	    int lp=p.size();
	    vector<vector<int> > vv(lp+1,vector<int>(ls+1,0));
	    vv[0][0]=1;

	    for(int i=1;i<=lp;i++){
		for(int j=0;j<=ls;j++){
			//last term vv[i-1][j]==1 : a , a*  match !
	 		if(p[i-1]=='*' && (i==1||  vv[i][j-1]==1||vv[i-1][j-1]==1 || vv[i-1][j]==1))	vv[i][j]=1;
			else if(j>0 && p[i-1]=='?' && vv[i-1][j-1]==1) 	vv[i][j]=1;
			else if(j>0 && p[i-1]==s[j-1] && vv[i-1][j-1]==1)			vv[i][j]=1;
		}
	    }
	    return vv[lp][ls]==1;
	}
};

