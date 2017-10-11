#include<vector>
#include<map>
#include<string>
using namespace std;



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<string, vector<string>* > m;
	string key;
	map<string,vector<string>*>::iterator t;
	for(int i=0;i<(int)strs.size();i++){
	    key=strs[i];
	    sort(key.begin(),key.end());
	    t=m.find(key);
	    if(t!=m.end())  t->second->push_back(strs[i]);
	    else{
		vector<string> *  v=new vector<string>;
		v->push_back(strs[i]);
		m.insert(make_pair(key,v));
	    }
	}
	vector<vector<string>> ans;

	for(map<string ,vector<string>*>::iterator i=m.begin();i!=m.end();i++){
	    vector<string> group;
	    for(int j=0;j<(int) (*(i->second)).size() ;j++){
		group.push_back((*(i->second))[j]);
	    }
	    ans.push_back(group);
	}
	return ans;
        
    }
};
