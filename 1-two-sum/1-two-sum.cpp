class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pr;
        for(int i=0; i<nums.size(); i++) {
            pr.push_back({nums[i], i});
        }
            
        sort(pr.begin(), pr.end());
        int s = 0, e = pr.size()-1;
        while(s < e) 
        {
            int sum = pr[s].first + pr[e].first;
            if(sum == target)
            {
                return {pr[s].second, pr[e].second};
            }
            else if(sum > target) {
                e--;
            } else {
                s++;
            }
        }
        
        return {};
    }
};