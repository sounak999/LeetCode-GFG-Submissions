// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        long long cnt = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            if(A[i]%K == 0 and mp.count(0))
                cnt += mp[0];
            else if(mp.count(K-A[i]%K))
                cnt += mp[K-A[i]%K];
                
            mp[A[i]%K]++;
            // cout<<A[i]<<" mod K-> "<<A[i]%K<<" cnt -> "<<cnt<<" freq -> "<<mp[A[i]%K]<<endl;
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends