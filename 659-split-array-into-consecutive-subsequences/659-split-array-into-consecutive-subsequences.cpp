class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, endsWith;
        
        for(int i: nums)
            cnt[i]++;
        
        for(int i: nums)
        {
            if(cnt[i] == 0)
                continue;
            
            if(endsWith[i-1] > 0)
            {
                endsWith[i-1]--;
                endsWith[i]++;
            }
            else if(cnt[i+1] && cnt[i+2])
            {
                cnt[i+1]--;
                cnt[i+2]--;
                endsWith[i+2]++;
            }
            else
                return false;
            
            cnt[i]--;
        }
        
        return true;
    }
};