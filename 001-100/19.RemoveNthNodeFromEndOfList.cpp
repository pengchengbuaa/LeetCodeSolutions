/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 *For example,
 *
 *  Given linked list: 1->2->3->4->5, and n = 2.
 *
 *  After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 *Try to do this in one pass.
 */

// 2017-9-4






/*
 * ref anser in java :
 * A one pass solution can be done using pointers. Move one pointer fast --> n+1 places forward, to maintain a gap of n between the two pointers and then move both at the same speed. Finally, when the fast pointer reaches the end, the slow pointer will be n+1 places behind - just the right spot for it to be able to skip the next node.

Since the question gives that n is valid, not too many checks have to be put in place. Otherwise, this would be necessary.


public ListNode removeNthFromEnd(ListNode head, int n) {
    
    ListNode start = new ListNode(0);
    ListNode slow = start, fast = start;
    slow.next = head;//开始，start ，fast，slow 相同？？？？？不懂
    
    //Move fast in front so that the gap between slow and fast becomes n
    for(int i=1; i<=n+1; i++)   {
        fast = fast.next;
    }
    //Move fast to the end, maintaining the gap
    while(fast != null) {
        slow = slow.next;
        fast = fast.next;
    }
    //Skip the desired node
    slow.next = slow.next.next;
    return start.next;
}
 */
#include <vector>
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
//ListNode 没有空头节点
//但可以像答案一样自己做一个
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *tail=head;
	ListNode * movinghead = head;
	for(int i=0;i<n;i++){
	    tail = tail->next;
	}
	if(tail == NULL){
	    return head->next;
	}
	while(tail->next!=NULL){
	    tail = tail->next ;
	    movinghead  = movinghead->next;
	}
	movinghead->next = movinghead->next->next;
	movinghead -> next=NULL;
	return head;
    }
};
