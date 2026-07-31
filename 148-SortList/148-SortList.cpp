// Last updated: 7/31/2026, 11:21:54 PM
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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val <= h2->val) {
                tail->next = h1;
                tail = tail->next;

                h1 = h1->next;
            } else {
                tail->next = h2;
                tail = tail->next;

                h2 = h2->next;
            }
        }

        while(h1){
            tail->next = h1;
            tail = tail->next;

            h1 = h1->next;
        }

        while(h2){
             tail->next = h2;
            tail = tail->next;

                h2 = h2->next;
        }

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        // finding mid
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* nextHead = slow;

        head = mergeSort(head);
        nextHead = mergeSort(nextHead);
        return merge(head, nextHead);
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        return mergeSort(head);
    }
};