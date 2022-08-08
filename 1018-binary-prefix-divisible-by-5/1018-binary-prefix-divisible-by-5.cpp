class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        long long num = 0;
        
        for(int x: nums)
        {
            num = (num*2 + x)%5;
            
            if(num == 0)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};