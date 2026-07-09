// Last updated: 7/9/2026, 11:46:48 AM
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;

        ListNode* pointA  = headA;
        ListNode* pointB  = headB; 

        while(pointA!=pointB){
            pointA = ( pointA==nullptr )? headB : pointA->next;
            pointB = ( pointB==nullptr )? headA : pointB->next;
        }
        return pointA;

        
    }
};