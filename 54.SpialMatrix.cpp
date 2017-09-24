#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	int n=matrix.size();
	if(n==0)    return  res;
	int m=matrix[0].size();
	if(m==0)    return  res;
	int t=(m>n)? n:m;
	for(int tt=0;tt< t/2 ;tt++){
	    for(int j=tt;j<m-tt-1;j++){
		res.emplace_back(matrix[tt][j]);
	    }
	    for(int i=tt;i<n-tt-1;i++){
		res.emplace_back(matrix[i][m-tt-1]);
	    }
	    for(int j=m-1-tt;j>tt;j--){
		res.emplace_back(matrix[n-tt-1][j]);
	    }
	    for(int i=n-tt-1;i>tt;i--){
		res.emplace_back(matrix[i][tt]);
	    }
	}
	if(t%2){
	    if(n>m){
		for(int i=t/2;i<n-t/2;i++){
		    res.emplace_back(matrix[i][m/2]);
		}
	    }
	    else{
		for(int j=t/2;j<m-t/2;j++){
		    res.emplace_back(matrix[n/2][j]);
		}
	    }
	}
	return res;
    }
};
