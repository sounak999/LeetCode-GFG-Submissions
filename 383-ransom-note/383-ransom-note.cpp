class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for(char c: ransomNote)
            freq[c - 'a']++;
        
        for(char c: magazine)
            if(freq[c-'a'])
                freq[c - 'a']--;
        
        for(int x: freq)
            if(x != 0)
                return false;
        
        return true;
    }
};