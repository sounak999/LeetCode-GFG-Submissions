class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0, pro = 1;
        bool flag = true;
        for(auto i: nums)
        {
            if(i == 0)
            {
                if(flag)
                   flag = false;
                
                zero++;
                continue;
            }
            
            pro *= i;
        }
            
        
        int n = nums.size();
        vector<int> v(n, 0);
        
        if(zero > 1)
            return v;
        
        v.resize(0);
        for(auto i: nums)
        {
            if(!flag)
            {
                if(i == 0)
                    v.push_back(pro);
                else
                    v.push_back(0);
                
                continue;
            }
                
            v.push_back(pro/i);
        }
        
        return v;
    }
};