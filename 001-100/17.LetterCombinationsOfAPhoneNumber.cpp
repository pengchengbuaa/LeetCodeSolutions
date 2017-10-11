#include<vector>
#include <queue>
#include<string>
using namespace std;
/* just use queue
 *
 */
class Solution {
string tables [8] = {
    "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
	vector <string > v;
	queue<string> q;
	q.push(digits);
	while(q.size()){
	    string s= q.front();
	    if (s.length() && isdigit(s[0])){
		int n = s[0]-'2';
		string addstr = tables [n];
		for(int i=0; i < (int )addstr.size();i++){
		    q.push(s.substr(1,s.length()-1)+addstr[i]);
		}
		q.pop();
	    }
	    else
	    {
		while(q.size()){
		    if(q.front().length()) v.push_back(q.front());
		    q.pop();
		}
	    }
	}
	return v;
    }
};
