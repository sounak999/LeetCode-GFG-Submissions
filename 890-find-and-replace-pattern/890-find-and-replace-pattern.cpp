class Solution {
    bool fun(string &w1, string &w2)
    {
        unordered_map<char, char> mp;
        for(int i=0; i<w1.length(); i++)
        {
            if(!mp.count(w1[i]))
                mp[w1[i]] = w2[i];
            else if(mp[w1[i]] != w2[i])
                return false;
        }
        
        vector<bool> visited(26, 0);
        for(auto i: mp)
        {
            if(visited[i.second - 'a'])
                return false;
            else
                visited[i.second - 'a'] = true;
        }    
        
        return true;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto &w: words)
            if(fun(w, pattern))
                ans.push_back(w);
        
        return ans;
    }
};