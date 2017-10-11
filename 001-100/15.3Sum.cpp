//Mysolution and comment 

class Solution {
    private:
	vector<vector<int>> find_equal(vector<int> & n,int target){
	    vector<vector<int>> n2;
	    vector<int>::iterator start = n.begin();
        vector<int>::iterator end = n.end();

	    while(start!=end-1){
            int sum = *start+*(end-1);
            if(sum==target){
                vector<int> v;
                v.push_back(-target);
                v.push_back(*start);
                v.push_back(*(end-1));
                n2.push_back(v);
                while(start<end-2&&(*start) == *(start+1)){
                    start++;
                }
                start++;
            }
            else if (sum<target){
                while(start<end-2&&(*start) == *(start+1)){
                    start++;
                }
                start++;
            }
            else if(sum>target){
                while(start<end-2 && *(end-1) == *(end-2)){
                    end--;
                }
                end--;
            }
	    }
        /*while loop refine::
        while(start!=end -1){
            if(*start+*(end-1)==target){
                **push_back**
                //在找到想要的对后再去重复，反例： -1，-1，2，3，4，5  target = 2
                //如果先去重，则 -1，-1 丢掉了
                while(start<end-1 && *start==(start+1) start++;
                while(start<end-1 && *(end-1)==*(end-2) end--;
                start++,end--//如果相等之后，去重，下个等式一定是两边都变化了
            }
            else if (sum>target) ......
            else .......
        }
        
        while (lo < hi) {
                if (num[lo] + num[hi] == sum) {
                    res.add(Arrays.asList(num[i], num[lo], num[hi]));
                    while (lo < hi && num[lo] == num[lo+1]) lo++;
                    while (lo < hi && num[hi] == num[hi-1]) hi--;
                    lo++; hi--;
                } else if (num[lo] + num[hi] < sum) lo++;
                else hi--;
                
                */
	    return n2;
	}
    

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int l=nums.size();
        if(l==3){
            if (!(nums[0]+nums[1]+nums[2])){
		vector<int>  vv;
		vv.push_back(nums[0]);
		vv.push_back(nums[1]);
		vv.push_back(nums[2]);
		v.push_back(vv);
	    }
	}
	else if (l>3){
        vector<int>::iterator start = nums.begin();
		vector<int>::iterator end = nums.end();
	    for(;start<end-2;start++){

            vector<int>subv= vector<int> (start+1,end);    
            vector< vector<int>> ans = find_equal(subv,-(*start));
            v.insert(v.end(),ans.begin(),ans.end());
            
            while(*(start+1)==*start&&start<end-3){
                start++;
            }//可以将这个过程加入到  循环判断中自动过滤,也就是复用start++ 这一句
            
            
	    }
        /*
        *   for(;start<end-2;start++){
        *       if(start==0 || start>0 && *(start+1)!=*start)
        *   }
        *
        *
        *
        *
        *
            
            
        */
	}
	return v;
    }
};


//ref answer in Java :
//public List<List<Integer>> threeSum(int[] num) {
//
//
//
//
//Hi guys!
//
//The idea is to sort an input array and then run through all indices of a possible first element of a triplet. For each possible first element we make a standard bi-directional 2Sum sweep of the remaining part of the array. Also we want to skip equal elements to avoid duplicates in the answer without making a set or smth like that.
    Arrays.sort(num);
    List<List<Integer>> res = new LinkedList<>(); 
    for (int i = 0; i < num.length-2; i++) {
        if (i == 0 || (i > 0 && num[i] != num[i-1])) {
            int lo = i+1, hi = num.length-1, sum = 0 - num[i];
            while (lo < hi) {
                if (num[lo] + num[hi] == sum) {
                    res.add(Arrays.asList(num[i], num[lo], num[hi]));
                    while (lo < hi && num[lo] == num[lo+1]) lo++;
                    while (lo < hi && num[hi] == num[hi-1]) hi--;
                    lo++; hi--;
                } else if (num[lo] + num[hi] < sum) lo++;
                else hi--;
           }
        }
    }
    return res;
}
