#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
	int n =matrix.size();
	int cir = n/2;
	int tmp;
	for(int i=0;i<cir;i++){
	    for(int j=i;j<n-i-1;j++){
		tmp= matrix[i][j];
		matrix [i][j]=matrix [n-j-1][i];
		matrix [n-j-1][i]=matrix [n-i-1][n-j-1];
		matrix [n-i-1][n-j-1]=matrix [j][n-i-1];
		matrix [j][n-i-1]=tmp;
	    }
	}
	return ;
    }
};
