class Solution {
    void solve(vector<vector<int>>& ans, vector<int>& output, int k, int n, int num)
    {
        if((n == 0) && (k == 0))
        {
            ans.push_back(output);
            return; 
        }
        
        if(k < 0 || n < 0)
            return ;
        
        for(int i=num; i<10; i++)
        {
            output.push_back(i);
            solve(ans, output, k-1, n-i, i+1);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(ans, output, k, n, 1);
        return ans;
    }
};