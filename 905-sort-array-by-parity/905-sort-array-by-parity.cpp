class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int st = 0, en = n-1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2==0)
                ans[st++] = nums[i];
            else
                ans[en--] = nums[i];
        }
        
        return ans;
    }
};