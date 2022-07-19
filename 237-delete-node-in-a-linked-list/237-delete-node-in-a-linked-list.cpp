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
        ListNode* nexNext = node->next->next;
        node->val = node->next->val;
        node->next = nullptr;
        node->next = nexNext;
    }
};