class Solution {
    void solve(vector<string> &ans, int currOpen, int currClose, int remOpen, int remClose, int n, string &output)
    {
        if(remOpen == 0 && remClose == 0)
        {
            ans.push_back(output);
            return ;
        }
        
        if(remOpen > 0)
        {
            output.push_back('(');
            solve(ans, currOpen+1, currClose, remOpen-1, remClose, n, output);
            output.pop_back();
        }
        
        if(remClose > 0 && currOpen > currClose)
        {
            output.push_back(')');
            solve(ans, currOpen, currClose+1, remOpen, remClose-1, n, output);
            output.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "(";
        int currOpen = 1, currClose = 0, remOpen = n-1, remClose = n;
        solve(ans, currOpen, currClose, remOpen, remClose, n, output);
        return ans;
    }
};