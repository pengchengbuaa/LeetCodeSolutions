#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int l1;
	int l2;
	vector<int> n1;
	vector<int> n2;
	if(nums1.size()<nums2.size()){
	    n1=nums2;
	    n2=nums1;
	    l1=nums2.size();
	    l2=nums1.size();
	}
	else{
	    n1=nums1;
	    n2=nums2;
	    l1=nums1.size();
	    l2=nums2.size();
	}

	if(l1==0 && l2==0){
	    return 0;
	}
	if(l2==0){
	    if(l1%2)	return n1[l1/2];
	    else	return (n1[l1/2-1]+n1[l1/2]+0.0)/2;
	}

	int c1,c2;
	int mr;
	int ml;
	for(int i =0;i<=((l1+l2)/2);i++){
	    c1 = i;
	    c2 = (l1 + l2)/2 - i ;
	    if(c2<0 || c2>l2) continue;
	    else {
		if(c1==0) ml=n2[c2-1];
		else if(c2==0) ml=n1[c1-1];
		else ml=max(n1[c1-1],n2[c2-1]);

		if(c1==l1) mr = n2[c2];
		else if(c2==l2) mr = n1[c1];
		else mr=min(n1[c1],n2[c2]);
		if(ml<=mr)  break;
		}
	}
	if((l1+l2)%2)
	    if(c2==l2)	return n1[c1];
	    else    return min(n1[c1],n2[c2]);
	else
	    return (ml+mr+0.0)/2;
    }
};
