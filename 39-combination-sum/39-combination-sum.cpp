class Solution {
    void solve(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &output, int curSum, int target, int index)
    {
        if(curSum >= target)
        {
            if(curSum == target)
                ans.push_back(output);
            
            return;
        }
        
        for(int i=index; i<candidates.size(); i++)
        {
            curSum += candidates[i];
            output.push_back(candidates[i]);
            solve(candidates, ans, output, curSum, target, i);
            curSum -= candidates[i];
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, ans, output, 0, target, 0);
        return ans;
    }
};