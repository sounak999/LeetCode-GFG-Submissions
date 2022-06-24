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
    int getLength(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;
        
        int n = getLength(head);
        k = k%n;
        
        if(k == 0)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        int t = n-k;
        while(t--)
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = NULL;
        
        ListNode* tail = curr;
        while(tail->next != NULL)
            tail = tail->next;
        
        tail->next = head;
        return curr;
    }
};