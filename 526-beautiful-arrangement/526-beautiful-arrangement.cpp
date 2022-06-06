class Solution {
    int solve(vector<int> &perm, vector<bool> &vis, int index, int n)
    {
        if(index == n+1)
        {
            return 1;
        }
        
        int cnt = 0;
        for(int i=0; i<perm.size(); i++)
        {
            if(!vis[perm[i]] && (perm[i] % index == 0 || index % perm[i] == 0))
            {
                vis[perm[i]] = 1;
                cnt += solve(perm, vis, index+1, n);
                vis[perm[i]] = 0;
            }
        }
        
        return cnt;
    }
public:
    int countArrangement(int n) {
        vector<int> v;
        for(int i=1; i<=n; i++)
            v.push_back(i);
        
        vector<bool> vis(n+1, false);
        
        return solve(v, vis, 1, n);
    }
};