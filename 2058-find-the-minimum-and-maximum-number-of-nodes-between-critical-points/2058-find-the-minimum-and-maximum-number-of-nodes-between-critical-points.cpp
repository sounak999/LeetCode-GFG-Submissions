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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL)
            return {-1, -1};
        
        int totalCp = 0, Cp = -1;
        int minDistance = INT_MAX, maxDistance = INT_MIN;
        int first = INT_MAX, last = INT_MIN;
        int index = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr->next)
        {
            // local minima
            if(curr->val < prev->val && curr->val < curr->next->val)
            {
                first = min(first, index);
                last = max(last, index);
                
                if(Cp != -1)
                    minDistance = min(minDistance, index-Cp);
                    
                Cp = index;
                totalCp++;
                
            }
            else if(curr->val > prev->val && curr->val > curr->next->val)
            {
                first = min(first, index);
                last = max(last, index);
                
                if(Cp != -1)
                    minDistance = min(minDistance, index-Cp);
                    
                Cp = index;
                totalCp++;
            }
            
            index++;
            prev = curr;
            curr = curr->next;
        }
        
        if(totalCp < 2)
            return {-1, -1};
        
        maxDistance = last - first;
        
        return {minDistance, maxDistance};
    }
};