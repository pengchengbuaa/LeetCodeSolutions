#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countBra(string s, bool isleft){
        string::iterator iter = s.begin();
        int cnt=0;
        while (iter!=s.end()){

            if (isleft && *iter =='(' || !isleft && *iter == ')')
             cnt++;
            iter ++;
        }
        return cnt;
    }

    void  dfs (string already, vector<string>&  ans,int n){
        if (already.length()==2*n){
            ans.push_back(already);
            return ;
        }
        if(countBra(already, true) <n){
            dfs(already+'(', ans,n);
        }

        if (countBra(already ,true) > countBra(already, false))
        dfs(already+ ')', ans,n);
        return ;

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        dfs ("", ans,n);
        return ans;
    }
};



int main(){

    Solution s = Solution();
    vector<string> ans =s.generateParenthesis(3);
    cout<< ans.size()<<endl;
    cout<< s.countBra("",true)<<endl;
    cout<< s.countBra("(((((",true)<<endl;
    cout<< s.countBra("))))",true)<<endl;
    return 0;
}