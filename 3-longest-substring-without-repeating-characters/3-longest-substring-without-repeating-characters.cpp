class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=s.length();
        int res = 0;
        unordered_set<char> st;
        
        while(i < n && j < n)
        {
            if(st.find(s[j]) == st.end())
            {
                st.insert(s[j++]);
                res = max(res, j-i);
            }
            else
            {
                st.erase(s[i++]);
            }
        }
        
        return res;
    }
};