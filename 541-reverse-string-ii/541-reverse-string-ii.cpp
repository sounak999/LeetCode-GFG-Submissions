class Solution {
    void reverse(string &s, int i, int j)
    {
        while(i < j)
        {
            swap(s[i++], s[j--]);
        }
    }
public:
    string reverseStr(string s, int k) {
        
        bool flag = 1;
        for(int i=0; i<s.length(); i+=k)
        {
            int j = i+k-1;
            if(j >= s.length())
                j = s.length()-1;
            
            if(flag) {
                reverse(s, i, j);
                flag = false;
            }
            else
                flag = true;
        }
        
        return s;
    }
};