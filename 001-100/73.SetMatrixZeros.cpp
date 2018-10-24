#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row= matrix.size();
        if (row ==0 || matrix[0].size() ==0) return ;
        int col= matrix[0].size();

        vector<bool> flags  = vector<bool>(row+col,false);

        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (matrix[i][j]==0) {
                    flags[i]=true;
                    flags[row+j] = true;
                }
            }
        }

        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (flags[i]|| flags[row+j] ) {
                    matrix[i][j]=0;
                }
            }
        }
    }
};





void printmat(vector<vector<int>> & mat){
    for (int i =0;i<  mat.size();i++){
        for ( int j=0;j<mat[0].size();j++){
            cout<< mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
vector<vector<int>> test1 ={
    vector<int>{1,1,1},
    vector<int> {1,0,1},
    vector<int> {1,1,1,}
    };


    printmat(test1);
    Solution s= Solution();
    s.setZeroes(test1);
    printmat(test1);
    return 0;

}