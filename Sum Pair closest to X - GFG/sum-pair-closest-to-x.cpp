// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        vector<int> ans;
        int n = arr.size();
        int i = 0, j = n-1, minAbs = INT_MAX;
        while(i < j)
        {
            int sum = arr[i] + arr[j];
            int diff = abs(sum - x);
            
            if(diff < minAbs)
            {
                minAbs = diff;
                if(ans.empty())
                {
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                }
                else
                {
                    ans.pop_back();
                    ans.pop_back();
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                }
            }
            
            if(sum > x)
                    j--;
                else
                    i++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends