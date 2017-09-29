#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
	int mul(int k){
	    if(k==0)	return 1;
	    int ans=1;
	    while(k){
		ans=k* ans;
            k--;
	    }
	    return ans;
	}
	vector<bool> a ;
	void	initbool  (int n){
	    a=*(new vector<bool> (n+1,true));
	}
	char getReNthC(int n)
	{
	    int i=1;
	    while (n>0){
		if(a[i]==true)	n--;
		i++;
	    }
	    a[i-1]=false;
	    return (i-1)+'0';
	
	}
    public:
	string getPermutation(int n, int k) {
	    string ans="";
	    initbool(n);
	    if(k>mul(n))    return "nulllll";
	    k--;
	    while(n>0){
		int kinds=mul(n-1);
		ans.push_back(getReNthC((k)/kinds+1));
		k=k%kinds;
		n--;
	    }
	    return ans;
	}
};
