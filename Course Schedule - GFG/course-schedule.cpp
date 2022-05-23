// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    bool executeTask(vector<vector<int>>& adjList, vector<int>& result, vector<int>& visited, unordered_set<int>& parents, int src)
    {
        if (visited[src])
            return true;
        
        parents.insert(src);
        for (auto& dependency : adjList[src])
        {
            if (parents.find(dependency) != parents.end())
                return false;
            if (!executeTask(adjList, result, visited, parents, dependency))
                return false;
        }
        parents.erase(src);
        visited[src] = true; result.push_back(src);
        return true;
    }
    
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> adjList(n, vector<int>());
        for (auto& dependency : prerequisites)
            adjList[dependency[0]].push_back(dependency[1]);
        vector<int> result;
        vector<int> visited(n, false);
        unordered_set<int> parents;
        for (int i = 0; i < n; ++i)
        {
            if (!executeTask(adjList, result, visited, parents, i))
                return {};
        }
        return result;
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends