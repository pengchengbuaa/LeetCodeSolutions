#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int> > possibleFlags (9,vector<int> (9,(1<<10) -1));

        for (int i=0;i<9;i++){
            for (int j =0;j <9;j++){
                if(board[i][j]=='.')
                    continue;
                int block_i = i/3;
                int block_j = j/3;
                int N  = board[i][j] - '1';
                for (int ii = 0;ii<9;ii++){
                    if ((possibleFlags[ii][j] & ~(1<< N)) == 0 ) 
                    return false;

                    possibleFlags[ii][j] &= ~(1<<N);
                }

                for (int jj=0;jj<9;jj++){
                    if (jj == j) continue;
                    if ((possibleFlags[i][jj] & ~(1<< N))  == 0 )
                     return false;
                    possibleFlags [i][jj] &= ~(1<<N);
                }

                for (int iii = block_i*3 ; iii< block_i*3+3;iii++){
                    for (int jjj = block_j*3;jjj<block_j*3+3;jjj++){
                        if(iii == i|| jjj == j) continue;
                    if ((possibleFlags[iii][jjj] & ~(1<< N)) == 0 )
                     return false;
                        possibleFlags[iii][jjj] &= ~(1<<N);
                    }
                }
                possibleFlags[i][j]  = 1<< N;
            }
        }

        for ( int i  = 0;i<9;i++){
            for (int j =0;j<9;j++){
                if (possibleFlags[i][j] == 0) return false;
            }
        }
        return true;
        
    }
};



int main() {
    Solution solution;
    vector<vector<char>> test1
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    

    
    
    cout<< solution.isValidSudoku(test1)<<endl;
    return 0;
}

/*
 bool isValidSudoku(vector<vector<char>>& board) {
    vector<short> col(9, 0);
    vector<short> block(9, 0);
    vector<short> row(9, 0);
    for (int i = 0; i < 9; i++)
     for (int j = 0; j < 9; j++) {
         if (board[i][j] != '.') {
             int idx = 1 << (board[i][j] - '0');
             if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                return false;
            row[i] |= idx;
            col[j] |= idx;
            block[i/3 * 3 + j/3] |= idx;
         }
     }
     return true;
  }


  */


 /*只需要记录9个行、列、block 分别不能方什么数字即可，我的解法有冗余*/