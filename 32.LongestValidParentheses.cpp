// concise reference answer
//Key Diff:stack 存的是index，最后可以得到 剩下的index  用减法可以得到长度
/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) longest = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};
The workflow of the solution is as below.

Scan the string from beginning to end.
If current character is '(',
push its index to the stack. If current character is ')' and the
character at the index of the top of stack is '(', we just find a
matching pair so pop from the stack. Otherwise, we push the index of
')' to the stack.
After the scan is done, the stack will only
contain the indices of characters which cannot be matched. Then
let's use the opposite side - substring between adjacent indices
should be valid parentheses.
If the stack is empty, the whole input
string is valid. Otherwise, we can scan the stack to get longest
valid substring as described in step 3.
 */




#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
	stack<string> stk;
	int slen = s.length();
	if(slen==0)
	    return 0;
	stk.push(s.substr(0,1));
	int a = 1;
	while(a<slen){
	    if(stk.empty()) stk.push(s.substr(a,1));
	    else if(s[a] == '('){
		stk.push("(");
	    }
	    else if(stk.top()[0]=='(' && s[a]==')'){
		string s_top = stk.top();
		int n;
		if(s_top.length()>1){
		    n = stoi(s_top.substr(1,s_top.length()-1),NULL,10);
		}
		else{
		    n =0;
		}
		n = n+ 2;
		stk.pop();

		if(stk.empty()){
		    stk.push(to_string(n));
		}
		else if(stk.top()[0] == ')'){
		    stk.push(to_string(n));
		}
		else if(stk.top()[0] =='('){
		    string s_second = stk.top();
		    int m;
		    if( s_second.length()>1){
			m = stoi(s_second.substr(1,s_second.length()-1),NULL,10);
		    }
		    else { 
			m=0;
		    }
		    stk.pop();//不能遗忘这个，一般注意检查，使用了top ，一般就需要pop掉
		    stk.push("("+to_string(m+n));
		}
		else{
		    int m = stoi( stk.top(),NULL,10);
		    stk.pop();
		    stk.push(to_string(m+n));
		}
	    }
	    else{
		stk.push(")");
	    }
	    a++;
	}

	int maxc =0;
	while (!stk.empty()){
	    string top = stk.top();
	    int v;
	    if(top[0]!='(' && top[0]!=')'){
		    v = stoi(top,NULL,10);
	    }
	    else if(top[0]=='(' &&  top.length()>1){
		v = stoi(top.substr(1,top.length()-1),NULL,10);
	    }
	    else {
		v=0;
	    }
	    maxc =  v>maxc? v:maxc;
	    stk.pop();
	}
	return maxc;
    }
};
