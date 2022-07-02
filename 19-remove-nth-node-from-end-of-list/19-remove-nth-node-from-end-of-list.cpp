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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, *fast = head;
        int k = n;
        while(k--)
            fast = fast->next;
        
        if(!fast)
            return slow->next;
        
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* next = slow->next;
        slow->next = slow->next->next;
        next->next = NULL;
        return head;
    }
};