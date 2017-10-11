#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
	int sl=s.size();
	vector<int> tcount(130,0);
	for(int i=0;i<(int)t.length();i++){
	    tcount[ t[i]]++;
	}
	int remain=0;
	for(int i=0;i<130;i++){
	    if(tcount[i]>0) remain++;
	}
	int mi=0;
	int mj=0;
	int si=0;
	int sj=0;

	bool isin=false;
	// (sj, si]
	while(sj<=sl){
	    if(!isin){
		si++;
		if(si>sl)   break;
		tcount[ s[si-1]]--;
		if(tcount[s[si-1]]==0) remain--;
		if(remain<=0)	isin=true;
	    }
	    if(isin){
		if((mi==mj && mi==0) || si-sj< mi-mj){
		    mi=si;
		    mj=sj;
		}
		sj++;
		tcount[s[sj-1]]++;
		if(tcount[s[sj-1]]==1) remain++;
		if(remain>0)	isin=false;
	    }
	}
    return s.substr(mj-1,mi-mj);
//    return  ""+to_string(mi)+""+to_string(mj);
    }
};
