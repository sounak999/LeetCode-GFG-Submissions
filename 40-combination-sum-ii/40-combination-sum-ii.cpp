class Solution {
    void solve(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& output, int target, int index)
    {
        if(target == 0)
        {
            ans.push_back(output);
            return ;
        }
        
        if(target < 0 || index == candidates.size())
            return;
        
        for(int i=index; i<candidates.size(); i++)
        {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            
            if(candidates[i] > target)
                break;
            
            output.push_back(candidates[i]);
            solve(candidates, ans, output, target-candidates[i], i+1);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, ans, temp, target, 0);
        return ans;
    }
};