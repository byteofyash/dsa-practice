// Last updated: 7/7/2026, 7:56:11 PM
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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr|| head->next==nullptr) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* first= dummy;
        ListNode* second = dummy;
        int count = 0;
        while(count<n+1){
                first = first->next;
                count++;
        }

        while(first!=nullptr){
            first = first->next;
            second = second->next;
        }

        second->next =  second->next->next;

        return dummy->next;
 


        
    }
};