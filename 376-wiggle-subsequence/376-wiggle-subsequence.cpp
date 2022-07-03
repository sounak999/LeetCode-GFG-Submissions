class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int prevDiff = nums[1] - nums[0];
        int total = 0;
        
        if(prevDiff != 0)
        {
            total = 2;
        }
        else
        {
            total = 1;
        }
        
        for(int i=2; i<nums.size(); i++)
        {
            int currDiff = nums[i]-nums[i-1];
            if((prevDiff <= 0 && currDiff > 0) || (prevDiff >= 0 && currDiff < 0))
            {
                total++;
                prevDiff = currDiff;
            }
            
        }
        
        return total;
    }
};