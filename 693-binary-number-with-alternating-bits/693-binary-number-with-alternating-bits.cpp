class Solution {
public:
    bool hasAlternatingBits(int n) {
        int ld = n&1;
        
        while((n&1) == ld)
        {
            ld = 1-ld;
            n >>= 1;
        }
        
        return (n == 0);
    }
};