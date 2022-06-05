// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(long T, long L, long S[], long A[], long N, long M){

        long ans = 0;

        for(int i=0;i<N; i++){

            long x = S[i]+A[i]*T;

            ans += (x>=L ? x : 0);

        }

        return ans >= M;

    }

    long buzzTime(long N, long M, long L, long H[], long A[])

    {

        // code here

        long low,high,mid;

        low = 0,high  = M;

        

        while(low<high){

            mid = low +(high-low)/2;

            if(check(mid, L, H,A, N,M))

                high = mid;

            else

                low = mid+1;

        }

        return high;

    }


};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends