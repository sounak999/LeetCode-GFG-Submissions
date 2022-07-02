// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void dfs(vector<vector<int>> &adj, int& cnt, vector<bool> &visited, int s, int d)
    {
        if(s == d)
        {
            cnt++;
            return ;
        }
        
        visited[s] = true;
        for(auto i: adj[s])
            dfs(adj, cnt, visited, i, d);
            
        visited[s] = false;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<bool> visited(n, false);
	    int cnt = 0;
	    vector<vector<int>> adj(n);
	    for(auto i: edges)
	        adj[i[0]].push_back(i[1]);
	        
	    dfs(adj, cnt, visited, s, d);
	    return cnt;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends