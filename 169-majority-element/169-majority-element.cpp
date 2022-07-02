class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0], votes = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(cand == nums[i])
                votes++;
            else
                votes--;
            
            if(votes == 0)
            {
                cand = nums[i];
                votes = 1;
            }
        }
        
        return cand;
    }
};