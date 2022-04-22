// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        int carry = 0, ans = 0, pwr = 0;
        while(a > 0 || b > 0 || carry != 0)
        {
            int lb_a = a&1, lb_b = b&1;
            int sum = (lb_a + lb_b + carry);
            if(sum >= 2)
            {
                if(sum == 3)
                {
                    ans += pow(2, pwr);
                }
                
                carry = 1;
            }    
            else if(sum == 1)
            {
                ans += pow(2, pwr);
                if(carry == 1)
                    carry = 0;
            }
            pwr++;
            a >>= 1;
            b >>= 1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends