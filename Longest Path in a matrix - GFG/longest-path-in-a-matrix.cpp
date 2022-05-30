// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        vector<vector<int>> pos={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=1;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int k=0;k<4;k++){
            int x = i + pos[k][0];
            int y = j + pos[k][1];
            
            if(x>=0 and x<n and y>=0 and y<m){
                if(matrix[i][j] < matrix[x][y]){
                    ans = max(ans,1+dfs(x,y,matrix,dp));
                }
            }
        }
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=0;
        
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(i,j,matrix,dp));
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends