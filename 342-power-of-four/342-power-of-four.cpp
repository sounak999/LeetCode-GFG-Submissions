class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) 
            return true;
        
        if(n < 1)
            return false;
        
        int isDiv = n%4;
        bool solve = isPowerOfFour(n/4);
        
        return (isDiv == 0 && solve);
    }
};