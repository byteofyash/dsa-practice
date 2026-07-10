// Last updated: 7/11/2026, 2:55:27 AM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* d = new ListNode();
        ListNode* pointer = d;
        while(l1!=nullptr || l2!=nullptr||carry!=0){
                int val1 = 0 , val2 = 0 ;
                 if(l1!=nullptr)val1 = l1->val;
                 if(l2!=nullptr)val2 = l2->val;
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* d_new = new ListNode(digit);
            pointer->next = d_new;
            pointer = d_new;
            if(l1!=nullptr)l1 = l1->next;
            if(l2!=nullptr)l2 = l2->next;
        }
        return d->next;
        
    }
};