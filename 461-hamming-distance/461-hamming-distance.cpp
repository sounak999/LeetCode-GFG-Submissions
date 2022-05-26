class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        
        while(x || y)
        {
            int first = x&1;
            int snd = y&1;
            ans += (first^snd);
            x >>= 1;
            y >>= 1;
        }
        
        return ans;
    }
};