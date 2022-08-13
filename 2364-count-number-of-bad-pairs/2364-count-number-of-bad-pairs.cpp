class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            cnt += mp[i - nums[i]]++;
        }
        
        long long total = n * 1LL * (n-1) / 2;
        return total - cnt;
    }
};