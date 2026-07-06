// Last updated: 7/7/2026, 2:40:40 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};