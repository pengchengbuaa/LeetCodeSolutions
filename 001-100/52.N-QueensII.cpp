#include<vector>
#include<string>
using namespace std;



class Solution {
    public:
    string findvalid(vector<string> b,int k,int n){
	string s(n,'.');
	for(int i=0;i<k-1;i++){
	    int j=0;
	    while(true){
		if (b[i][j]=='Q')   break;
		j++;
	    }
	    s[j]='x';
	    int j1=j+(k-1-i);
	    int j2=j-(k-1-i);
	    if(j1>=0 && j1<n)	s[j1]='x';
	    if(j2>=0 && j2<n)	s[j2]='x';
	}
	return s;
    }

    void back(vector<string> & b,int k,int n,int  &  ans){
	if(k==n)    {
	    ans++;
	    return;
	}
	else{
	    string valid=findvalid(b,k+1,n);
	    for(int i=0;i<n;i++){
		if(valid[i]=='x')   continue;
		b[k][i]='Q';
		back(b,k+1,n,ans);
		b[k][i]='.';
	    }
	}
    }

    int totalNQueens(int n) {
	int ans=0;
	vector< string> b(n,string(n,'.'));
	for(int i=0;i<n;i++){
	    string fir(n,'.');
	    fir[i]='Q';
	    b[0]=fir;
	    back(b,1,n,ans);
	}
	return ans;
    }
};

