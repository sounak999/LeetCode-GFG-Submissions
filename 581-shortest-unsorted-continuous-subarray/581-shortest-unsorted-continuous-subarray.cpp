class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int ans = 0, n = nums.size();  
        
        // Two pointers
        int i = 0;
        int j = n - 1;

        int curr_min = INT_MAX; // from right we'll find the min element
        int curr_max = INT_MIN; // from left we'll find the max element
        
        // Initialize end to -1, if we have all sorted in ascending order, then end-start+1 = -1+0+1 = 0 
        // "end" for left, "start" for right
        int start = 0, end = -1;
        
        while(j >= 0 && i < n){
            // Check if the "num[start]" is greater than the minimum element so far
            if(nums[i] >= curr_max) 
                curr_max = nums[i];
            else 
                end = i; // if the curr_max isn't updating, we'll store that index in "end"

            // Check if the "num[end]" is less than the maximum element so far
            if(nums[j] <= curr_min) 
                curr_min = nums[j];
            else 
                start = j; // if the curr_min isn't updating, we'll store that index in "start"

            ++i;
            --j;
        }
        
        // defining the number of elements
        return end - start + 1;
    }
};