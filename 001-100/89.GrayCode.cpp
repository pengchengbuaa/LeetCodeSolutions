#include<iostream>
#include<vector>

using namespace std;

/*
    000 000
    001 001
    011 010
    010 011
    110 100
    111 101
    101 110
    100 111
    
    */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> tmp2 ;
        for ( int  num = 0; num<(1<<n); num++){
            int ans =0;
            int  t=0;
            for (int bit = 0; bit< n;bit++){
                t = (num>>bit)%4;
                if (t ==1|| t ==2){
                    ans += 1<< bit;
                }
            }
            tmp2.push_back(ans);
        }
        return tmp2;
        
    }
};




int main(){
    Solution s=Solution();

    vector<int> ans;
    ans =s.grayCode(4);
    //watch ans when debugging in variables
    return 0;

    
}