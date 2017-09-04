//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
#include<vector>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
int  minNode(vector<ListNode *> v){
    int minval=v[0]->val;
    int index =0;
    for(int i =0 ;i<(int) v.size();i++){
	if(v[i]->val<minval){
	    minval = v[i] ->val;
	    index = i;
	}
    }
    return index;
}
	
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	vector<ListNode*> heads = lists;
	ListNode  * newhead = new ListNode(0);
	ListNode *  newtail = newhead;
	for(int i=(int)heads.size()-1;i>=0;i--){
	    if(heads[i]==NULL){
		heads.erase(heads.begin()+i);
		//erase in reverse order to avoid missing empty head 逆序删除
	    }
	}
	while(heads.size()){
	    int index = minNode(heads);
	    newtail->next = heads[index];
	    newtail = newtail->next;
	    heads[index] = heads[index]->next;
	    if(heads[index]==NULL){
		for(int i= 0;i<(int)heads.size();i++){
		    if(heads[i]==NULL){
			heads.erase(heads.begin()+i);
		    }
		}
	    }
	}
	newtail->next = NULL;
	return newhead ->next;
    }
};
