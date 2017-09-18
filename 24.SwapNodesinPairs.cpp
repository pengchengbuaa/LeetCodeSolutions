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
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x),next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
	ListNode * c = head;

	if(head==NULL || head->next==NULL)  return head;
	ListNode* first = head;
	ListNode* second = head->next;

	head=second;
	first->next=second->next;
	second->next=first;

	c=first;
	while(c->next!=NULL && c->next->next != NULL){
	    first=c->next;
	    second=c->next->next;
	    c->next=second;
	    first->next=second->next;
	    second->next=first;
	    c=first;
	}
    return head;
    }
};
