class Solution {
    void solve(string &tiles, unordered_map<int, int> &vis, string &output, unordered_set<string> &res)
    {
        for(int i=0; i<tiles.length(); i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                output.push_back(tiles[i]);
                res.insert(output);
                solve(tiles, vis, output, res);
                
                vis[i] = 0;
                output.pop_back();
            }
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        string output = "";
        unordered_map<int, int> vis;
        unordered_set<string> res;
        
        solve(tiles, vis, output, res);
            
        return res.size();
    }
};