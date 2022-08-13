class Solution {
    bool allSubstringsPossible(string& str, int s, int e, unordered_map<string, int> mp, int eachWord)
    {
        string temp = "";
        for(int i=s; i<=e; i+=eachWord)
        {
            temp = str.substr(i, eachWord);
            if(mp[temp] == 0)
                return false;
            
            mp[temp]--;
            temp = "";
        }
        
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int eachWord = words[0].length();
        int totalWords = words.size();
        int wholeWords = eachWord * totalWords;
        unordered_map<string, int> mp;
        
        for(auto s: words)
            mp[s]++;
        
        for(int i=0; (i + wholeWords - 1)<s.length(); i++)
        {
            if(allSubstringsPossible(s, i, (i + wholeWords - 1), mp, eachWord))
                ans.push_back(i);
        }
        
        return ans;
    }
};