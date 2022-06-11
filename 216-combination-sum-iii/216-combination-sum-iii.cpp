class Solution {
    void solve(vector<int>& arr, vector<vector<int>>& ans, vector<int>& output, int k, int n, int index)
    {
        if(n == 0)
        {
            if(output.size() == k)
                ans.push_back(output);
            
            return; 
        }
        
        if(output.size() > k || n < 0)
            return ;
        
        for(int i=index; i<arr.size(); i++)
        {
            output.push_back(arr[i]);
            solve(arr, ans, output, k, n-arr[i], i+1);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<int> arr;
        
        for(int i=1; i<=9; i++)
            arr.push_back(i);
        
        solve(arr, ans, output, k, n, 0);
        return ans;
    }
};