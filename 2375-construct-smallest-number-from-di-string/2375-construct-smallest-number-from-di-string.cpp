class Solution {
public:
    bool check(string s, string pattern)
    {
        for(int i=0; i<pattern.size(); i++)
        {
            if(pattern[i] == 'I' && s[i+1] > s[i])
                continue;
            else if(pattern[i] == 'D' && s[i+1] < s[i])
                continue;
            
            return false;
        }
        
        return true;
    }
    
    string smallestNumber(string pattern) {    
        string str;
        int n = pattern.size();
        
        for(int i=1; i<=n+1; i++)
        {
            str.push_back(i + '0');
        }
        
        while(1)
        {
            if(check(str, pattern))
            {
                return str;
            }
            
            next_permutation(str.begin(), str.end());
        }  
        
        // this part never gonna execute
        return "";
    }
};