// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(int target, int n, int &ans)
    {
        // cout<<target<<" "<<n<<" "<<ans<<endl; 
        if(n == 1 && target > 0)
        {
            ans++;
            return ;
        }
        
        for(int i = 1; i < target; i++)
        {
            // cout<<i<<": ";
            solve(target-i, n-1, ans);
        }
    }
    
    long posIntSol(string s)
    {
        int n = 1;
        int target = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '+') 
                n++;
                
            if(s[i] == '=')
            {
                i++;
                while(i<s.length())
                {
                    target = target*10 + s[i]-'0';
                    i++;
                }
            }
        }
        
        // make target with n numbers
        if(target < n) return 0;
        if(target == n) return 1;
        int ans = 0;
        solve(target, n, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends