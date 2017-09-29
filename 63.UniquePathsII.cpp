#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int n=obstacleGrid.size();
	if(n==0)    return 0;
	int m=obstacleGrid[0].size();
	if(m==0)    return 0;
	vector<vector<int>>  paths (n,vector<int>(m,0));
	if(obstacleGrid[0][0]!=1)	paths[0][0]=1;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		if(obstacleGrid[i][j]!=1){
		    if(i-1>=0 && obstacleGrid[i-1][j]!=1) paths[i][j]+=paths[i-1][j]; 
		    if(j-1>=0 && obstacleGrid[i][j-1]!=1) paths[i][j]+=paths[i][j-1];
		}
	    }
	}
	return paths[n-1][m-1];
    }
};
