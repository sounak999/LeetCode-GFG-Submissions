class Solution {
public:
    int dp[102][102][22];
    int solve(vector<int>&h,vector<vector<int>>&cost ,int m,int n,int target,int i,int prev_col)
    {
        // base case
       
        if(i == m && target == 0)
            return 0;
        
        if(i >= m || target < 0)
            return INT_MAX;
        
       if(dp[i][target][prev_col] != -1)
           return dp[i][target][prev_col];
        // if the house is already colored you have two scenes : 
        //1. the color of the house is same as the color you have colored the prev house
        //2. the color is not the same
        
        if(h[i] != 0)
        {
            if(h[i] == prev_col)
                return solve(h,cost,m,n,target,i+1,h[i]);
            else
                return solve(h,cost,m,n,target-1,i+1,h[i]);
        }
        
             int ans = INT_MAX;
        // if the color i have to do 
        //1 . if the prev color and current color that i am choosing are same 
        // then they will be neighbours
        // 2 . else they will be not the neighbours decrease the target by 1
        if(h[i] == 0)
        {
            for(int j = 0 ; j  < n ; j++)
            {
                //since col j is from 1 to  n
                if(prev_col == j + 1)
                {
                   int val = solve(h,cost,m,n,target,i+1,j+1); 
                    if(val !=INT_MAX){
                    ans = min(ans,val + cost[i][j] );
                        
                    }
                }
                else
                {
                    int val = solve(h,cost,m,n,target-1 , i+1,j+1);
                    if(val!=INT_MAX){
                    ans = min(ans , val + cost[i][j] );
                       
                    }
                }
            }
        }
        return dp[i][target][prev_col] = ans;
    }
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target) {
        int s = h.size();
        memset(dp , -1, sizeof(dp));
        int p = solve(h,cost,m,n,target,0,0);
        
        return p == INT_MAX ? -1 : p;
    }
};