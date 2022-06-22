class Solution {
public:
    void reverseString(vector<char>& s, int i = 0) {
        int j = s.size()-1-i;
        
        if(i >= j)
            return ;
        
        swap(s[i], s[j]);
        reverseString(s, i+1);
    }
};