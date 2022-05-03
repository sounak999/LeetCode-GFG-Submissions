class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans = 0;  
        
        // Two pointers
        int i = 0;
        int j = nums.size() - 1;

        int curr_min=INT_MAX;
        int curr_max=INT_MIN;
        
        int start=0,end=-1;
        
        while(j >= 0){
            if(nums[i] >= curr_max) curr_max = nums[i];
            else end = i;
            
            if(nums[j] <= curr_min) curr_min = nums[j];
            else start = j;

            ++i;
            --j;
        }
        
        return end - start + 1;
    }
};