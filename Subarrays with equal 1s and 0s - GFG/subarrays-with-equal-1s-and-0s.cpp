// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        long long int cnt = 0;
        for(int i=0; i<n; i++)
            if(arr[i] == 0)
                arr[i] = -1;
                
        long long int pre = arr[0];
        unordered_map<long long int, int> mp;
        mp[arr[0]]++;
        for(int i=1; i<n; i++)
        {
            pre += arr[i];
            if(pre == 0)
                cnt++;
                
            cnt += mp[pre];
            mp[pre]++;
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends