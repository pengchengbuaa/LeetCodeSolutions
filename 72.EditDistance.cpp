#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
	int l1=word1.size();
	int l2=word2.size();
	vector<vector<int>> ops (l1+1,vector<int>(l2+1,0));
	ops[0][0]=0;
	for(int i=0;i<=l1;i++){
	    for(int j=0;j<=l2;j++){
		if(i==0 && j==0)    continue;
		int minop=INT_MAX;
		if(i-1>=0 && j-1>=0 && word1[i-1]==word2[j-1])	ops[i][j]=ops[i-1][j-1];
		else{
		//add
		if(j-1>=0 ) minop=min(minop,ops[i][j-1]+1);
		//replace
		if(j-1>=0 && i-1>=0) minop=min(minop,ops[i-1][j-1]+1);
		//delete
		if(i-1>=0)minop=min(minop,ops[i-1][j]+1);
		ops[i][j]=minop;
		}
	    }
	}
	return ops[l1][l2];
    }

};
