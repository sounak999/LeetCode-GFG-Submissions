class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vis(26, 0);
        int ans = -1;
        
        for(int i=0; i<s.length(); i++)
        {
            int idx = s[i] - 'a';
            vis[idx] += 1;
        }
        
        for(int i=0; i<s.length(); i++)
        {
            int idx = s[i] - 'a';
            if(vis[idx] == 1)
            {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};