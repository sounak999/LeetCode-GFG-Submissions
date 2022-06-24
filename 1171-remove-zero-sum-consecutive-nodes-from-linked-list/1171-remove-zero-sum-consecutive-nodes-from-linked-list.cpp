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
    ListNode* solve(ListNode* &head, bool &flag)
    {
        if(head == NULL)
            return head;
        
        int sum = 0;
        ListNode* temp = head;
        
        while(temp)
        {
            sum += temp->val;
            if(sum == 0)
                break;
            
            temp = temp->next;
        }
        
        if(sum == 0)
        {
            flag = true;
            return temp->next;
        }
        
        head->next = solve(head->next, flag);
        return head;
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        while(true)
        {
            bool flag = false;
            head = solve(head, flag);
            if(flag == false || head == NULL)
                break;
        }
        
        return head;
    }
};