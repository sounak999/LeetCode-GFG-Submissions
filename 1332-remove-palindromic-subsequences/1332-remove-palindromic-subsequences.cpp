class Solution {
    bool isPal(string &s, int i, int j)
    {
        if(i >= j)
            return true;
        
        if(s[i] != s[j])
            return false;
        
        return isPal(s, i+1, j-1);
    }
    
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.length()-1;
        
        if(isPal(s, i, j))
            return 1;
        
        return 2;
    }
};