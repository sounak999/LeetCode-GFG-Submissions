class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c - 'a']++;
        
        int dltCnt = 0;
        unordered_set<int> look;
        
        for(int i=0; i<26; i++) {
            
            while(freq[i] && look.find(freq[i]) != look.end())
            {
                freq[i]--;
                dltCnt++;
            }
                
            look.insert(freq[i]);
        }
        
        return dltCnt;
    }
};