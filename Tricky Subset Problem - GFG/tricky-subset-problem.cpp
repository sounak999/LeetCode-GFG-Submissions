// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        long long sum = S;
        long long idx = N-1;
        for(long long i = 0; i < N; i++)
        {
            A[i] += sum;
            sum += A[i];
            if(A[i] >= X)
            {
                idx = i;
                break;
            }
        }
        
        while(idx >= 0)
        {
            if(X >= A[idx])
                X-=A[idx];
                
            --idx;
        }
        
        if(X == 0 || X == S) 
            return 1;
        
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends