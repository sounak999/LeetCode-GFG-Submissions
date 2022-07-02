class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cand1 = -1, cand2 = -1, votes1 = 0, votes2 = 0, n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == cand1)
                votes1++;
            else if(nums[i] == cand2)
                votes2++;
            else if(votes1 == 0)
            {
                cand1 = nums[i];
                votes1 = 1;
            }
            else if(votes2 == 0)
            {
                cand2 = nums[i];
                votes2 = 1;
            }
            else
            {
                votes1--;
                votes2--;
            }
        }
        
        votes1 = votes2 = 0;
        for(auto i: nums)
        {
            if(cand1 == i)
                votes1++;
            else if(cand2 == i)
                votes2++;
        }
        
        if(votes1 > n/3)
            ans.push_back(cand1);
        
        if(votes2 > n/3)
            ans.push_back(cand2);
        
        return ans;
    }
};