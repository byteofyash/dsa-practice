// Last updated: 7/7/2026, 7:55:30 PM
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
    ListNode* reverse(ListNode* node) {
        if (node == nullptr || node->next == nullptr)
            return node;
        ListNode* newHead = reverse(node->next);

        node->next->next = node;
        node->next = nullptr;

        return newHead;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int length = 0;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            length += 2;
            slow = slow->next;
        }
        ListNode* rev;
        if (length % 2 != 0) {
            rev = reverse(slow->next);
        } else
            rev = reverse(slow);

        while (rev !=nullptr) {
            if (head->val != rev->val)
                return false;
            head = head->next;
            rev = rev->next;
        }

        return true;
        ;
    }
};