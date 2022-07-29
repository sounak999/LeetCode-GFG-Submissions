class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
            
            if(mp2.find(t[i]) == mp.end())
                mp2[t[i]] = s[i];
            
            if((mp[s[i]] != t[i]) || (mp2[t[i]] != s[i]))
                return false;
        }
        
        return true;
    }
};