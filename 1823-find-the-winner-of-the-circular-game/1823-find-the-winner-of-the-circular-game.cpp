class Solution {
    int solve(int n, int k)
    {
        if(n == 1)
            return 0;
        
        int rest = solve(n-1, k);
        return (k + rest) % n;
    }
public:
    int findTheWinner(int n, int k) {
        return solve(n, k) + 1;   
    }
};