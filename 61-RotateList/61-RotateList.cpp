// Last updated: 7/31/2026, 11:23:33 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    using llnode = ListNode*;

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        
        int count = 0 ;
        llnode curr = head;
        while(curr->next!=nullptr){count++; curr = curr->next;}
        int N = count+1;
        llnode oldTail  = curr;

        //form a ring
        oldTail->next = head;
        k = k %N;
        int toWalk = N-k-1;
        llnode newTail = head;
        while(toWalk!=0){
            newTail = newTail->next;
            toWalk--;
        }

        llnode newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
        





    }
};