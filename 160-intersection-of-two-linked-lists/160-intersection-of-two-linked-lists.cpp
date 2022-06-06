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
        int m = 0; // length of headA
        int n = 0; // length of headB
        
        ListNode* temp = headA, *temp2 = headB;
        while(temp)
        {
            m++;
            temp = temp->next;
        }
        
        while(temp2)
        {
            n++;
            temp2 = temp2->next;
        }
        
        int dif = abs(n-m);
        temp = headA, temp2 = headB;
        if(m > n)
        {
            while(dif)
            {
                temp = temp->next;
                dif--;
            }
        }
        else
        {
            while(dif)
            {
                temp2 = temp2->next;
                dif--;
            }
        }
        
        while(temp && temp2)
        {
            if(temp == temp2)
                return temp;
            
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return NULL;
    }
};