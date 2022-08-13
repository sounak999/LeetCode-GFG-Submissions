class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[i - nums[i]]++;
        }
        
        long long total = n * 1LL * (n-1) / 2;
        long long good = 0;
        for(auto it: mp)
        {
            if(it.second > 1)
            {
                int freq = it.second;
                good += (freq * 1LL * (freq - 1)) /2;
            }
        }
        
        return total - good;
    }
};