class Solution {
public:
    int uniquePaths(int m, int n) {
	int sum=1;
	for(int i=1;i<=n;i++){
	    sum=sum*(i+m)/i;
	}
	return sum;
    }
};
