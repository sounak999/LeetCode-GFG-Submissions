class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+1, 0);
        
        for(int i=1; i<=n; i++)
        {
            dp[i] = nums[i-1] + dp[i-1];
        }
        
    }
    
    int sumRange(int left, int right) {
        left++;
        right++;
        
        return dp[right] - dp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */