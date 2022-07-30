class Solution {
    vector<int> freq(string& word)
    {
        vector<int> fr(26, 0);
        for(auto &c: word)
            fr[c - 'a']++;
        
        return fr;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> maxFreq(26, 0);
        
        for(auto &s: words2)
        {
            vector<int> temp = freq(s);
            for(int i=0; i<26; i++)
                maxFreq[i] = max(maxFreq[i], temp[i]);
        }
        
        for(auto &s: words1)
        {
            vector<int> temp = freq(s);
            int i = 0; 
            while(i < 26)
            {
                if(temp[i] < maxFreq[i])
                    break;
                
                i++;
            }
                
            if(i == 26)
                ans.push_back(s);
        }
        
        return ans;
    }
};