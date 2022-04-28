// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    int find_min(int candies[], int N, int k)
   {
       int start = 0;
       int end = N - 1;
       int res = 0;
       
       while(start <= end)
       {
           res += candies[start];
           start++;
           end -= k;
       }
       return res;
   }
   
   int find_max(int candies[], int N, int k)
   {
       int start = N - 1;
       int end = 0;
       int res = 0;
       
       while(start >= end)
       {
           res += candies[start];
           start--;
           end += k;
       }
       return res;
   }
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int mini = 0,maxi = 0;
        
        mini = find_min(candies,N,K);
        maxi = find_max(candies,N,K);
        
        return {mini,maxi};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends