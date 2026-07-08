// Last updated: 7/8/2026, 2:42:46 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return nullptr;
        ListNode* fast  = head;
        ListNode* slow = head; 
        ListNode* prev = nullptr;

        while(fast!=nullptr && fast->next!=nullptr){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = prev->next->next;
        return head;


        
    }
};