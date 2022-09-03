class Solution {
    void solve(int num, int idx, int n, int k, vector<int> &res)
    {
        if(idx == n)
        {
            res.push_back(num);
            return ;
        }
        
        for(int i=0; i<10; i++)
        {
            int ld = num%10;
            int diff = abs(ld - i);
            if(diff == k)
            {
                solve(num*10 + i, idx+1, n, k, res);
            }
        }
    }
        
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        
        for(int i=1; i<10; i++)
        {
            // no. of digits
            int no = 1;
            solve(i, no, n, k, res);
        }
        
        return res;
    }
};