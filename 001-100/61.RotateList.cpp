#include<iostream>
#include<string>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
    ListNode (int x ,ListNode* n ):val(x),next(n) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int nH = 1;
        int nT = 1;
        // return head;
        ListNode* pH = head;
        ListNode* pT = head;
        while(pT->next !=NULL){
            nT++;
            if(nT - nH == k+1){
                nH ++;
                pH =pH->next;
            }
            pT=pT->next;
        }

        if(nT-nH < k) k=k%nT;
        while(nT-nH !=k){
            nH++;
            pH=pH->next;
        }

        pT->next= head;
        ListNode * ans  = pH->next;

        pH->next =NULL;
        return ans;

    }
};


string listToSting(ListNode* l){
    string  s;
    if (l==NULL){
        return NULL;
    }
    while(l!=NULL){
        s.append( to_string(l->val));
        s.append(",");
        l=l->next;
    }
    return s;
}


int main(){
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3,NULL)));
    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(3,NULL)));
    ListNode* list3 = new ListNode(1, new ListNode(2, new ListNode(3,NULL)));
    ListNode* list4 = new ListNode(1, new ListNode(2, new ListNode(3,NULL)));
    ListNode* list5 = new ListNode(1, new ListNode(2, new ListNode(3,NULL)));
    ListNode* list6 = new ListNode(1, new ListNode(2, new ListNode(3,NULL)));

    // int a[]  = {0x48, 0x61, 0x70, 0x70, 0x79 ,0x20 ,0x31, 0x30 ,0x32 ,0x34 ,0x20 ,0x50, 0x72,
//    0x6f,0x67,0x72,0x61,0x6d,0x6d,0x65,0x72,0x27,0x73,0x20,0x44,0x61,0x79,0x21};

    // for (int i=0;i<30;i++){
    //     cout<< char(a[i]);
    // }
    // cout<<endl;
    Solution s = Solution();
    cout<< listToSting(s.rotateRight(list1,2))<<endl;
    cout<< listToSting(s.rotateRight(list2,3))<<endl;
    cout<< listToSting(s.rotateRight(list3,0))<<endl;
    cout<< listToSting(s.rotateRight(list4,1))<<endl;
    cout<< listToSting(s.rotateRight(list5,200))<<endl;
    
    return 0;
} 