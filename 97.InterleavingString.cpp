#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
	int l1=s1.size();
	int l2=s2.size();
	int l3=s3.size();
	if(l3!=l1+l2)	return false;
       
	if(l3==0)   return true;
	vector<vector<bool>> inter(l1+1,vector<bool> (l2+1,false));
	inter[0][0]=true;

	for(int t=1;t<=l3;t++){
	    for(int i=0;i<=l1;i++){
		int j=t-i;
		if(j>l2 || j<0)    continue;
		if(i>=1 && inter[i-1][j] && s3[i+j-1]==s1[i-1])	inter[i][j]=true;
		if(j>=1 && inter[i][j-1] && s3[i+j-1]==s2[j-1])	inter[i][j]=true;
	    }
	}
	return inter[l1][l2];
    }
};
