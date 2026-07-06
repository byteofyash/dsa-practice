// Last updated: 7/7/2026, 2:43:17 AM
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
struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty() == true)
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> pq;
        for (auto head : lists) {
            if(head!=nullptr) pq.push(head);
        }

        ListNode dummy(0); // dummy was created on stack hence we return dummy.next instead of dummy->next
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr)
                pq.push(smallest->next);
        }

        return dummy.next;
    }
};