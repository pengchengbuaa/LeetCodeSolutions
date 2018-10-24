#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:

    inline int matN(vector<vector<int>> mat , int m, int N){ return mat[N/m][N%m];}
    bool search(vector<vector<int>> & matrix, int target, int start ,int end ,int size){
        int mid = (start + end)/2;
        int midv = matN(matrix,matrix[0].size(),mid);
         if (mid == start){
             return midv==target;
         }
         if (midv > target) {
             return search(matrix, target,start, mid,size);
         }else return search(matrix, target, mid, end, size );
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0 || matrix[0].size() == 0) return false;
        int n = matrix[0].size();
        int cnt = m*n;
        return search(matrix,target,0,cnt, cnt);
    }
}; 


int main(){

    vector<vector<int>> m1 {
        vector<int> {1,2,3,7},
        vector<int> {10,11,16,20 },
        vector< int> {23,30,34,50} 
    };


    Solution solutin =Solution();
     bool ans1 = solutin.searchMatrix(m1,3 );
     bool ans2 = solutin.searchMatrix(m1,13);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}