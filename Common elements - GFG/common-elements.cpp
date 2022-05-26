// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector <int> ans;
            
            // finding intersection b/w first two arrays
            int i=0, j=0;
            while(i < n1 && j < n2)
            {
                if(A[i] < B[j])
                    i++;
                else if(B[j] < A[i])
                    j++;
                else
                {
                    // handling the duplicates and
                    // storing into the ans vector
                    if(ans.empty() || ans.back() != A[i])
                        ans.push_back(A[i]);
                    i++;
                    j++;
                }
            }
            
            vector<int> actualAns;
            
            // finding intersection b/w third 
            // array and the ans vector
            int k = 0, l = 0, n4 = ans.size();
            while(k < n3 && l < n4)
            {
                if(C[k] < ans[l])
                    k++;
                else if(ans[l] < C[k])
                    l++;
                else
                {
                    if(actualAns.empty() || actualAns.back() != C[k])
                        actualAns.push_back(C[k]);
                    k++;
                    l++;
                }
            }
            
            return actualAns;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends