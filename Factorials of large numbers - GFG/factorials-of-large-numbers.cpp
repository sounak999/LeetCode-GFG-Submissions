// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
    vector<int> multiply(int ind, vector<int> ans)
    {
        int carry = 0;
        for(int i=0; i<ans.size(); i++)
        {
            int val = ind * ans[i] + carry;
            int digit = val%10;
            ans[i] = digit;
            carry = val/10;
        }
        
        while(carry)
        {
            int val = carry%10;
            ans.push_back(val);
            carry /= 10;
        }
        
        return ans;
    }
public:
    vector<int> factorial(int N){
        vector<int> ans(1, 1);
        
        for(int i=1; i<=N; i++)
        {
            ans = multiply(i, ans);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends