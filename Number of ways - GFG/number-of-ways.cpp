// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int N){
        
        if(N <= 3)
            return 1;
        if(N == 4)
            return 2;
            
        vector<long long int> dp(N+1, -1);
        dp[1] = 1LL, dp[2] = 1LL, dp[3] = 1LL, dp[4] = 2LL;
        
        for(int i=5; i<=N; i++)
        {
            dp[i] = dp[i-1] + dp[i-4];
        }
        
        return dp[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends