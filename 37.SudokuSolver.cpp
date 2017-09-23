//Why don't work ?
//-- Only use constrains is not able to solve sudoku problem 
//example:
//
//position x must be 3 but the constrain may not get that information
//so the soduke may use backtrack!
//
//* * * 3
//* * * * 3
//* * x
//3
//* 3
//
//
//




#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    void placen(vector<vector<int>> & con ,int ip,int jp,int n){
        for(int i=0;i<9;i++)	    con[i][jp]=con[i][jp]|1<<n;
        for(int j=0;j<9;j++)	    con[ip][j]=con[ip][j]|1<<n;
        for(int mi=ip/3*3;mi<ip/3*3+3;mi++) {
            for(int mj=jp/3*3;mj<jp/3*3+3;mj++){
                con[mi][mj]=con[mi][mj]|1<<n;
            }
        }
    }

    int solven( int n){
        cout<<"solven:"<<(bitset<10>)n<<endl;
        int p=400;
        for(int i=1;i<=9;i++){
            if((n>>i & 1 )==0){
                if(p==400)  p=i;
                else	    return -1;
            }
        }
        if(p==400)  return -1;
        else	return p;
    }

    void placeNsolve(vector<vector<char>> & b,vector<vector<int>> & con ,int pi,int pj,int n){
        b[pi][pj]='0'+n;
        cout<<"placeNsolve"<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<b[i][j];
            }
            cout<<endl;
        }
        placen(con,pi,pj,n);
        int ans;
        for(int ii=0;ii<9;ii++){
            if(b[ii][pj]!='.')	continue;
            cout<<"eval:"<<ii<<" "<<pj<<endl;
            ans=solven(con[ii][pj]);
            if(ans!=-1)	{cout<<"find:"<<ii<<" "<<pj<<endl;placeNsolve(b,con,ii,pj,ans);}
        }
        for(int jj=0;jj<9;jj++){
            if(b[pi][jj]!='.')	continue;
            cout<<"eval:"<<pi<<" "<<jj<<endl;
            ans=solven(con[pi][jj]);
            if(ans!=-1)	{cout<<"find:"<<pi<<" "<<jj<<endl; placeNsolve(b,con,pi,jj,ans);}
        }
        for(int ii=pi/3*3;ii<pi/3*3+3;ii++){
            for(int jj=pj/3*3;jj<pj/3*3+3;jj++){
                if(b[ii][jj]!='.')	continue;
                if(ii==pi||jj==pj)   continue;
                else {
                    cout<<"eval:"<<ii<<" "<<jj<<endl;
                    ans=solven(con[ii][jj]);
                    if(ans!=-1) {cout<<"find:"<<ii<<" "<<jj<<endl;placeNsolve(b,con,ii,jj,ans);}
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector <int>> con ( 9,vector<int> (9,0));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) {
                char n = board[i][j];
                if (n == '.') continue;
                else placen(con, i, j, n - '0');
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) {
                cout<<"init con:"<<i<<"  "<<j<<(bitset<10> )con[i][j]<<endl;

            }
        }


        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')	continue;
                int ans=solven(con[i][j]);
                cout<<"run through i:"<<i<<"j: "<<j<<ans<<endl;
                if (ans!=-1) placeNsolve(board,con,i,j,ans);
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<" "<<(bitset<10>)con[i][j];
            }
            cout<<endl;
        }
    }
};



int main()
{
    string ma = "..9748...7.........2.1.9.....7...24..64.1.59..98...3.....863.2.....9...6...2759..";
    vector<vector<char>> bo(9,vector<char>(9,'0'));
    for(int i=0;i<9;i++ ){
        for(int j=0;j<9;j++){
            bo[i][j]=ma[i*9+j];
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<bo[i][j];
        }
        cout<<endl;
    }

    Solution s;
    s.solveSudoku(bo);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<bo[i][j];
        }
        cout<<endl;
    }
    return 0;
}

