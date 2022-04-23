class Solution {
public:
    int reverse(int x) {
        int ans = 0, pwr = 0;
        while(x != 0)
        {
            int ld = x%10;
            if(ans < INT_MIN/10 || ans > INT_MAX/10)
                return 0;
            
            ans = ans*10 + ld; 
            x /= 10;
        }
        
        return ans;
    }
};