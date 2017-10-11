/*
 *参考答案：
 递归方式，将后面的排好序之后，把前面的挪到后面去
 * public ListNode reverseKGroup(ListNode head, int k) {
    ListNode curr = head;
    int count = 0;
    while (curr != null && count != k) { // find the k+1 node
        curr = curr.next;
        count++;
    }
    if (count == k) { // if k+1 node is found
        curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
        // head - head-pointer to direct part,
        // curr - head-pointer to reversed part;
        while (count-- > 0) { // reverse current k-group:
            ListNode tmp = head.next; // tmp - next head in direct part
            head.next = curr; // preappending "direct" head to the reversed list
            curr = head; // move head of reversed part to a new node
            head = tmp; // move "direct" head to the next node in direct part
        }
        head = curr;
    }
    return head;
}
*/

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
    ListNode * next;
    ListNode(int x): val(x),next(NULL) {}
};
class Solution {
    public :
	ListNode *  findkth(ListNode* head,int k){
	    while( k>0 && head->next!=NULL ){
		head=head->next;
		k--;
	    }
	    if(k!=0)	return NULL;
	    else	return head;
	}

	void rever (ListNode* bh, ListNode* last){
	    ListNode* c=bh->next;
	    ListNode* bef=bh;
	    ListNode* aft;//=c->next;
	    ListNode* firstele=bh->next;
	    while(c!=last){
		aft=c->next;
		c->next=bef;
		bef=c;
		c=aft;
	    }
	    firstele->next=c->next;
	    bh->next=c;
	    c->next=bef;
	}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
	if(k==1|| k==0)    return head;
	ListNode * l;
	l= new ListNode (0);
	l->next=head;
	ListNode * rawbh=l;
	ListNode* last = findkth(l,k);
	while(last!=NULL){
	    ListNode* nl=l->next;//注意 reverse之后 l,last 变化了，需要rever之前存下Head Node 之前的Node
	    rever(l,last);
	    l=nl;
	    last=findkth(l,k);
	}
	return rawbh->next;
    }
};
