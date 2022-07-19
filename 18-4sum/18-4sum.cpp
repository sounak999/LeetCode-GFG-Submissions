class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i <nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                long long temp = nums[i] + nums[j];
                long long t = target - temp;
                int front = j+1, back = nums.size() - 1;
                
                while(front < back) {
                    long long sum = nums[front] + nums[back];
                    
                    if(sum < t)
                        front++;
                    else if(sum > t)
                        back--;
                    else {
                        res.push_back({nums[i], nums[j], nums[front], nums[back]});
                        
                        while(front < back && nums[front] == nums[front+1])
                            front++;
                        
                        while(front < back && nums[back] == nums[back-1])
                            back--;
                        
                        front++;
                        back--;
                    }
                }
                
                while(j+1 < nums.size() && nums[j+1] == nums[j])
                    j++;
            }
            
            while(i+1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        
        return res;
    }
};