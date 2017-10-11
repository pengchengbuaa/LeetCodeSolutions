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

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> m;
	int l=intervals.size();
	if(l==0){
	    m.push_back(newInterval);
	    return m;
	}
	sort(intervals.begin(),intervals.end(),cmp);
	int i;
	for( i=0;i<l;i++){
	    if(intervals[i].end < newInterval.start) 	    m.push_back(intervals[i]);
	    else    break;
	}
	if(i==l  || intervals[i].start>newInterval.end){
	    m.push_back(newInterval);
	    for(;i<l;i++){
		m.push_back(intervals[i]);
	    }
	    return m;
	}
	int newend=0;

	int newstart=min(intervals[i].start, newInterval.start);
	newend= max(intervals[i].end,newInterval.end);
	while(i<l&& intervals[i].start<=newend){
	    newend=max(newend,intervals[i].end);
	    i++;
	}
	m.push_back(Interval(newstart,newend));
	for(;i<l;i++){
	    m.push_back(intervals[i]);
	}
	return m;
    }
};
