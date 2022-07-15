class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        
        return 1 + solve(grid, i-1, j, n, m) + solve(grid, i+1, j, n, m) + solve(grid, i, j-1, n, m) + solve(grid, i, j+1, n, m);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1)
                    ans = max(solve(grid, i, j, n, m), ans);
            }
        }
        
        return ans;
    }
};