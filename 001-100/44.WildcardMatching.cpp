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

//http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
/*
Analysis:

For each element in s
If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
       if there is no *,  return false;
       if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.

e.g.

abed
?b*d**

a=?, go on, b=b, go on,
e=*, save * position star=3, save s position ss = 3, p++
e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
d=d, go on, meet the end.
check the rest element in p, if all are *, true, else false;

Note that in char array, the last is NOT NULL, to check the end, use  "*p"  or "*p=='\0'".
//Linearal solution 
//
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
