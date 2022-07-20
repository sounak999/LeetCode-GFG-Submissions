class Solution {
    
    bool isSub(string& s, string b) {
        int i = 0, j = 0;
        int m = s.length(), n = b.length();
        
        while(i<m && j<n) {
            if(s[i] == b[j]) 
            {
                i++;
                j++;
            }
            else
                i++;
        }
        
        return (j == n);
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> mp;
        
        for(int i=0; i<words.size(); i++)
            mp[words[i]]++;
        
        for(auto it=mp.begin(); it != mp.end(); it++) 
        {
            if(isSub(s, it->first))
                ans += it->second;
        }
        
        return ans;
    }
};