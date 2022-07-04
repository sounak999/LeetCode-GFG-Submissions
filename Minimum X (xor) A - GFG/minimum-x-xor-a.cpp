// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int cntB = __builtin_popcount(b);
        
        
        // stack to store binary representation of a
        stack<int> s;
        while(a)
        {
            s.push(a&1);
            a >>= 1;
        }
        
        
        // vector to store the X 
        vector<int> ex;
        while(!s.empty())
        {
            if(s.top() == 1 && cntB)
            {
                ex.push_back(1);
                cntB--;
            }
            else
            {
                ex.push_back(0);
            }
            
            s.pop();
        }
        
        
        // this part will execute if there are unset bits
        // and cntB > 0
        int i = ex.size()-1;
        while(i >= 0 && cntB)
        {
            if(ex[i] == 0)
            {
                ex[i] = 1;
                cntB--;
            }
            
            i--;
        }
        
        
        // crating our res integer variable from the binary array
        int res = 0;
        i = ex.size() - 1;
        while(i >= 0)
        {
            int mask = 1 << (ex.size()-i-1);
            res += (ex[i]*mask);
            i--;
        }
        
        
        // if there are still extra bits remaining
        // updating our res by addding 1 at MSB
        int shift = ex.size();
        while(cntB--)
        {
            res += (1 << shift);
            shift++;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends