// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        sort(arr,arr+n);
        long long int pow1 = 1, pow2 = 1, sum1 = 0, sum2 = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if((i+1)%2 == 0){
                sum1 += arr[i] * pow1;
                pow1 *= 10;
            } else {
                sum2 += arr[i] * pow2;
                pow2 *= 10;
            }
        }
        
        long long int sum = sum1+sum2;
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends