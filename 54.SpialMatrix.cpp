#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int n=matrix.size();
	vector<int> res;
	for(int i=0;i< n/2 ;i++){
	    for(int j=i;j<n-i-1;j++){
		res.push_back(matrix[i][j]);
	    }
	    for(int j=i;j<n-i-1;j++){
		res.push_back(matrix[j][n-i-1]);
	    }
	    for(int j=i;j<n-i-1;j++){
		res.push_back(matrix[n-i-1][n-j-1]);
	    }
	    for(int j=i;j<n-i-1;j++){
		res.push_back(matrix[n-j-1][i]);
	    }
	}
	if(n%2){
	    res.push_back(matrix[n/2][n/2]);
	}


	return res;
    }
};
