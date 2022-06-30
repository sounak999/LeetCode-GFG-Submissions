class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        
        int num = n, x = 0;
        while(num)
        {
            x |= 1;
            num >>= 1;
            
            if(num != 0)
                x <<= 1;
        }
        
        return n^x;
    }
};