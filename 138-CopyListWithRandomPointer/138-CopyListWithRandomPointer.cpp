// Last updated: 7/31/2026, 11:22:14 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    using llnode = Node*;

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;
        llnode curr = head;

        // weave
        while (curr != nullptr) {
            llnode clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // link
        curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->random != nullptr)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        llnode copyHead = head->next;
        llnode tailcopy = copyHead;

        llnode orgHead = head;
        llnode tail = head;
        // unweave
        while (tail != nullptr && tail->next != nullptr) {
            tail->next = tail->next->next;
            tail = tail->next;

            if (tailcopy != nullptr && tailcopy->next != nullptr) {
                tailcopy->next = tailcopy->next->next;
                tailcopy = tailcopy->next;
            }
        }

        return copyHead;
    }
};