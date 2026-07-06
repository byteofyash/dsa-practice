// Last updated: 7/7/2026, 2:41:23 AM
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
    ListNode* reverseList(ListNode* head) {
        // maintain 3 pointers: prev, curr, front
        // first curr points at head; front = curr->next ; prev = nullptr
        // after moving front to curr->next ; increment prev and curr by 1 position
        // prev = curr
        // curr = front

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* front = nullptr;

        while(curr!=nullptr){

            front = curr->next; // save the rest of the link
            curr->next = prev; // reverse the link ( this is where magic happens)

            // increment prev and curr pointers by 1 position
            prev = curr;
            curr = front;
        }
        
        return prev;



        
    }
};