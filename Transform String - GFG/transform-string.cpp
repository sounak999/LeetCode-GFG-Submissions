// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        unordered_map<char, int> m;
        for(auto c: A)
            m[c]++;
            
        for(auto c: B)
            m[c]--;
            
        for(auto i: m)
            if(i.second != 0)
                return -1;
           
        int cnt = 0, i = A.length()-1, j = B.length()-1;     
        
        while(i >= 0 && j >= 0)
        {
           if(A[i] == B[j])
           {
               i--;
               j--;
           }
           else
           {
               while(A[i] != B[j] && i >= 0 && j >= 0)
               {
                   i--;
                   cnt++;
               }
           }
       }
       
       return cnt;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends