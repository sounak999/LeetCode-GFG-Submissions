class Solution {
    int solveMem(vector<int>& nums, int t, vector<int>& dp)
    {
        if(t < 0)
            return 0;
        if(t == 0)
            return 1;
        if(dp[t] != -1)
            return dp[t];
            
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
            ans += solveMem(nums, t-nums[i], dp);
        
        dp[t] = ans;
        return dp[t];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solveMem(nums, target, dp);
    }
};