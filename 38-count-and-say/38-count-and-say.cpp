class Solution {
    string solve(string str, int index, int n)
    {
        if(index == n)
        {
            return str;
        }
        
        
        int i = 0;
        char ch = str[i];
        int cnt = 0;
        string ans = "";
        
        while(i < str.length())
        {
            if(ch == str[i])
            {
                cnt++;
            }
            else 
            {
                ans = ans + char(cnt + '0') + ch;
                cnt = 1;
                ch = str[i];
            }
            
            i++;
        }
        
        ans = ans + char(cnt + '0') + ch;
        return solve(ans, index+1, n);
    }
public:
    string countAndSay(int n) {
        return solve("1", 1, n);
    }
};