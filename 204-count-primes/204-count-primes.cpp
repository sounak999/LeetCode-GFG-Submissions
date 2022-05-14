class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n+1, true);
        sieve[0] = sieve[1] = false;
        
        int cnt = 0;
        for(int i=2; i<n; i++)
        {
            if(sieve[i])
            {
                cnt++;
                for(int j=i*2; j<=n; j+=i)
                    sieve[j] = false;
            }
            
        }
        
        return cnt;
    }
};

