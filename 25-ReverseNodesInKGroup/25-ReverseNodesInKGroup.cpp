// Last updated: 7/31/2026, 11:24:18 PM
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

    llnode revKGroup(llnode head, llnode nextNode) {
        llnode prev = nullptr;
        llnode curr = head;

        while (curr != nextNode) {
            llnode forward = curr->next;
            curr->next = prev;

            prev = curr;
            curr = forward;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        llnode dummy = new ListNode(0);
        dummy->next = head;

        llnode prevGroupTail = dummy;

        llnode currHead = dummy->next;
        llnode currTail = dummy;

        while (true) {
            //find kth node
            int n = k;
            while (n != 0) {
                currTail = currTail->next;
                if (currTail == nullptr)
                    return dummy->next;
                n--;
            }
            llnode nextNode = currTail->next;
            
            llnode reversedHead = revKGroup(currHead,nextNode);

            prevGroupTail->next = reversedHead;
            currHead->next=nextNode;

            prevGroupTail = currHead;
            currHead = nextNode;
            currTail = prevGroupTail;
        }

        return dummy->next;

       
    }
};