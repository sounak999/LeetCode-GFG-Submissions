class Solution {
    void bfs(vector<int> adj[], vector<bool> &vis, int node)
    {
        queue<int> q;
        q.push(node);
        vis[node] = true;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto nei: adj[front])
            {
                if(!vis[nei])
                {
                    q.push(nei);
                    vis[nei] = true;
                }
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(), cnt = 0;
        vector<int> adj[V];
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(i != j && isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
            
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                bfs(adj, vis, i);
                cnt++;
            }
        }
        
        return cnt;
    }
};