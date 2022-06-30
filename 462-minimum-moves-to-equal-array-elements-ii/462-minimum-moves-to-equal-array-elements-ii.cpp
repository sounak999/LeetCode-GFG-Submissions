class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), count = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n/2; i++)
        {
            count += nums[n-1-i] - nums[i];
        }
        
        return count;
    }
};