class Solution {
    bool allSubstringsPossible(string& s, int index, map<string, int> mp, int eachWord, int wholeWords)
    {
        int len = s.length();
        int workingLen = len - index;
        if(wholeWords > workingLen)
            return false;
        
        int i = index;
        while(i < (index + wholeWords))
        {
            string word = s.substr(i, eachWord);
            if(mp[word] == 0)
                return false;
                
            mp[word]--;
            i +=  eachWord;    
        }
        
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int eachWord = words[0].length();
        int totalWords = words.size();
        int wholeWords = eachWord * totalWords;
        map<string, int> mp;
        
        if(wholeWords > s.length())
            return ans;
        
        for(auto s: words)
            mp[s]++;
        
        for(int i=0; (i + wholeWords - 1)<s.length(); i++)
        {
            if(allSubstringsPossible(s, i, mp, eachWord, wholeWords))
                ans.push_back(i);
        }
        
        return ans;
    }
};