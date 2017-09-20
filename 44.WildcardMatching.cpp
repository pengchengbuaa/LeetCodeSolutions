#include <vector>
#include <string>
using namespace std;


class Solution {
    public:
	bool isMatch(string s, string p) {
	    int ls=s.size();
	    int lp=p.size();
	    vector<vector<int> > vv(lp+1,vector<int>(ls+1,0));
	    vv[0][0]=1;
	    for(int i=1;i<=lp;i++){
		for(int j=0;j<=ls;j++){
			//last term vv[i-1][j]==1 : a , a*  match !
	 		if(p[i-1]=='*' && (i==1||  vv[i][j-1]==1||vv[i-1][j-1]==1 || vv[i-1][j]==1))	vv[i][j]=1;
			else if(j>0 && p[i-1]=='?' && vv[i-1][j-1]==1) 	vv[i][j]=1;
			else if(j>0 && p[i-1]==s[j-1] && vv[i-1][j-1]==1)			vv[i][j]=1;
		}
	    }
	    return vv[lp][ls]==1;
	}
};


//Linearal solution 
//
/*
 *  bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}

            // * found in pattern, track index of *, only advancing pattern pointer
            if (*p=='*'){star=p++; ss=s;continue;}

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;}

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;
    }
    */
