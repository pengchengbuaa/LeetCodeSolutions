#include<vector>
using namespace std;

class Solution {
public:
    void placen(vector<vector<int>> & con ,int ip,int jp,int n){
	for(int i=0;i<9;i++)	    con[i][jp]=con[i][jp]|1<<n;
	for(int j=0;j<9;j++)	    con[ip][j]=con[jp][j]|1<<n;
	for(int mi=ip/3*3;mi<ip/3*3+3;mi++) {
	    for(int mj=jp/3*3;mj<jp/3*3+3;mj++){
		con[mi][mj]=con[mi][mj]|1<<n;
	    }
	}
	return;
    }

    int solven( int n){
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
	placen(con,pi,pj,n);
	int ans;
	for(int ii=0;ii<9;ii++){
	    if(b[ii][pj]!='.')	continue;
	    ans=solven(con[ii][pj]);
	    if(ans!=-1)	placeNsolve(b,con,ii,pj,ans);
	}
	for(int jj=0;jj<9;jj++){
	    if(b[pi][jj]!='.')	continue;
	    ans=solven(con[pi][jj]);
	    if(ans!=-1)	placeNsolve(b,con,pi,jj,ans);
	}
	for(int ii=pi/3*3;ii<pi/3*3+3;ii++){
	    for(int jj=pj/3*3;jj<pj/3*3+3;jj++){
		if(b[ii][jj]!='.')	continue;
		if(ii==pi||jj==pj)   continue;
		else {
		    ans=solven(con[ii][jj]);
		    if(ans!=-1) placeNsolve(b,con,ii,jj,ans);
		}
	    }
	}
	return;
    }

    void solveSudoku(vector<vector<char>>& board) {
	vector<vector <int>> con ( 9,vector<int> (9,0));
	for(int i=0;i<9;i++){
	    for(int j=0;j<9;j++){
		char n=board[i][j];
		if(n=='.') continue;
		else	placen(con,i,j,n-'0');
	    }
	}
	for(int i=0;i<9;i++){
	   for(int j=0;j<9;j++){
		if(board[i][j]!='.')	continue;
	        int ans=solven(con[i][j]);
	 	    if (ans!=-1) placeNsolve(board,con,i,j,ans);
	   }
	}
	//placeNsolve(board,con,0,0,5);
	//
	//
	for(int i=0;i<9;i++){
	    for(int j=0;j<9;j++){
		board[i][j]=solven(con[i][j])+'0';
	    }
	}
    }
};
