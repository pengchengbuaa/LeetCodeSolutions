#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/* better answer:

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
       
        //
        //
        // STRATEGY:
        // For an array with only -ve numbers:
        // pick max number, thats the answer.
        //
        // For an array with mix of +ve and -ve numbers:
        // you want to incluce a -ve number in the sub-array iff 
        // the numbers next to it negate the effect out. Doing this 
        // works as long as sum of the sub array does not dip below 0,
        // otherwise no matter how big the number to its right
        // may be - it would stand better on it own instead of being
        // included in the sub array.
        //
        //example 10000, -1,-1,-1,100000 

        子串小于0 就没有用处
                
        if (nums.size() < 1)
            return 0;

        int positiveSum = max(0, nums[0]);
        
        int maxPositiveSum = positiveSum;
        
        int minNegativeNo = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            positiveSum = max(0, nums[i] + positiveSum);
            
            maxPositiveSum = max(maxPositiveSum, positiveSum);  
            
            minNegativeNo = max(minNegativeNo, nums[i]);
        }
                    
        int maxSum;
        
        if (minNegativeNo < 1)
        {
            maxSum = minNegativeNo;
        }
        else
        {
            maxSum = maxPositiveSum;
        }
        
        return maxSum;
    }
};

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len ==1){
            return nums[0];
        }
        vector<int> before =vector<int> (nums.begin(),nums.begin()+ len/2);
        vector<int> after=vector<int> (nums.begin()+len/2,nums.end());

        int maximum = max (maxSubArray(before), maxSubArray(after));
        vector<int>::iterator fstIter =nums.begin()+ len/2 -1;
        vector<int>::iterator sndtIter  = nums.begin() + len/2;
        int  tmpsum = *fstIter + *sndtIter;
        int tmpmax  = tmpsum;

        fstIter--;
        sndtIter++;
        while ( fstIter != nums.begin() -1){
            tmpsum= tmpsum + *fstIter;
            if (tmpsum> tmpmax) tmpmax = tmpsum;
            fstIter--;
        }

        tmpsum = tmpmax;
        while( sndtIter != nums.end()){
            tmpsum = tmpsum  + *sndtIter;
            if ( tmpsum> tmpmax) tmpmax = tmpsum;
            sndtIter ++;
        }
        return max(maximum,tmpmax);
    }
};


int main(){

    vector<int> v {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v2 {-2,-1,-5}; // corner case: all minus
    vector<int> v3 {-2,1,-3,4,-1,2,1,-5,4};

    Solution s =Solution();

    cout<<  s.maxSubArray(v) <<endl;
    cout<<  s.maxSubArray(v2) <<endl;
    cout<<  s.maxSubArray(v3) <<endl;


    int n =  -INT32_MAX/2;
    cout<< n<<endl;
    return 0;
}


