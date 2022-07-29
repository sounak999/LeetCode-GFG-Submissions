class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        
        for(int i=0; i<s.length(); i++) 
        {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
            
            else if(mp[s[i]] != t[i])
                return false;
        }
        
        vector<bool> visited(256, false);
        for(auto it: mp)
        {
            if(!visited[it.second])
                visited[it.second] = true;
            else
                return false;
        }
        
        return true;
    }
};