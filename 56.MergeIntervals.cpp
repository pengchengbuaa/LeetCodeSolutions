#include<vector>
using namespace std;



struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };



    bool cmp(Interval a,Interval b){
	return a.start<b.start;
    }
class Solution {
public:
    vector<Interval> mi(vector<Interval> & m,vector<Interval>& ins,int k){
	if(k==(int)ins.size())    return m;
	if(ins[k].start<=m.back().end )	{
	    m.back().end=max(m.back().end,ins[k].end);
	    return mi(m,ins,k+1);
	}
	else{
	    m.push_back(ins[k]);
	    return mi(m,ins,k+1);
	}
	
    }
    vector<Interval> merge(vector<Interval>& intervals) {
	if(intervals.size()<=1)	return intervals;
	sort(intervals.begin(),intervals.end(),cmp);
	vector<Interval> m;
	m.push_back(intervals[0]);
	mi(m,intervals,1);

	return m;
    }
};
