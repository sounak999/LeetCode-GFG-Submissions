class Solution {
    void solve(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &output, int index, int target)
    {
        if(target == 0)
        {
            ans.push_back(output);
            return ;
        }
        
        if(target < 0 || index >= candidates.size())
            return ;
        
        // exclude
        solve(candidates, ans, output, index+1, target);
        
        // include
        output.push_back(candidates[index]);
        solve(candidates, ans, output, index, target-candidates[index]);
        output.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(candidates, ans, output, index, target);
        return ans;
    }
};