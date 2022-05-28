class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPresent(n+1, false);
        for(auto x: nums)
        {
            isPresent[x] = true;
        }
        
        for(int i=0; i<=n; i++)
        {
            if(!isPresent[i])
                return i;
        }
            
        return -1;
    }
};