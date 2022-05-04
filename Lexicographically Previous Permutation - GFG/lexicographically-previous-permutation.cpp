// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string prevPermutation(string s) {
        int n = s.length(), k, l;
        
        for(k=n-2; k>=0; k--)
        {
            if(s[k] > s[k+1])
                break;
        }
        
        if(k < 0)
            return "None";
            
        for(l=n-1; l>k; l--)
        {
            if(s[k] > s[l])
                break;
        }
        
        swap(s[k], s[l]);
        reverse(s.begin()+k+1, s.end());
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout<<ob.prevPermutation(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends