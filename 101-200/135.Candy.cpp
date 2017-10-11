#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
	int l=ratings.size();
	if(l==1)    return 1;
	int allcdy=l;//all candy add default that's every one has one;
	int i=1;
	while(i<l){
	    int maxindex=i;
	    int hi=0;
	    while(i<l){
		if(ratings[i-1]<ratings[i]) {
		    maxindex=i;
		    hi++;
		}
		else if(ratings[i-1]>ratings[i]) break;
		allcdy+=hi;
		i++;
	    }
	    int lo=hi;
	    while(i<l){
		if(ratings[i-1]>ratings[i]){
		    lo--;
		}
		else if(ratings[i-1]<ratings[i])    break;
		allcdy+=lo;
		i++;
	    }
	    allcdy=lo>=0? allcdy-(i-maxindex)*lo:allcdy+(i-maxindex+1)*(1-lo);
	    //if(lo>=0)	allcdy-= (i-maxindex)*lo;
	    //else if(lo<0)   allcdy+=(i-maxindex+1)*(1-lo);
	}
	return allcdy;
    }
};
