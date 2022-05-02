class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int m[60] = {};
        int res = 0;
        
        for(auto x : time)
        {
            int t = x % 60;
            int y = (60 - t)%60;
            res += m[y];
            m[t]++;
        }
        
        return res;
    }
};