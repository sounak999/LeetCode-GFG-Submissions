class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // creating min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // traversing through the array
        for (int x: nums) {
            pq.push(x);
            
            // if at any point size exceeds 'k', just pop the element
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // returning the top element
        return pq.top();
    }
};