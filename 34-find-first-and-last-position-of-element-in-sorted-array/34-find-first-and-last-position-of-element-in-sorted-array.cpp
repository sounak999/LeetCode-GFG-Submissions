class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        
        if(left < right)
        {
            int firstOcc = left - nums.begin();
            right--;
            int lastOcc = right - nums.begin();
            return {firstOcc, lastOcc};
        }
        
        return {-1, -1};
    }
};