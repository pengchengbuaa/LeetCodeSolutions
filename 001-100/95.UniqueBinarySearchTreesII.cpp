#include<vector>
using namespace std;
    /**
 * Definition for a binary tree node.
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



void makeTrees(vector<vector<int>> &  trees,vector<int> init ,int a,int b,int st){
    if(a==b)	trees.push_back(init);
    for(int i=a;i<=b;i++){
	init[st]=i;
	makeTrees(trees,init,a+1,b,st+1);
    }
}

TreeNode* getT(vector<int> t,int st,int en){

    int r=t[0];
    

    //todo 
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
	vector<vector<int>> trees;
	vector<int>t;
	vector<int> init(n,0);
	makeTrees(trees,init,1,n,0);
	vector<TreeNode*> Trees;
	for(int i=0;i<(int)trees.size();i++){
	    Trees.push_back(getT(trees[i],0,n));
	}
	return Trees;
    }
};
