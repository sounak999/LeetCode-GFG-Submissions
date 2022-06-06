class Solution {
    void solve(vector<bool> &vis, int index, int &ans)
    {
        if(index == vis.size())
        {
            ans++;
            return ;
        }
        
        for(int i=1; i<vis.size(); i++)
        {
            if(!vis[i] && (index%i == 0 || i%index == 0))
            {
                vis[i] = 1;
                solve(vis, index+1, ans);
                vis[i] = 0;
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<bool> vis(n+1, false);
        int ans = 0;
        solve(vis, 1, ans);
        return ans;
    }
};