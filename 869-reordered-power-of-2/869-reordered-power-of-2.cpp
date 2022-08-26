class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        for(int i=0; i<32; i++)
        {
            int val = 1<<i;
            string s1 = to_string(val), s2 = to_string(n);
            sort(s1.begin(), s1.end()), sort(s2.begin(), s2.end());
            if(s1==s2) 
                return true;
        }
        
        return false;
    }
};