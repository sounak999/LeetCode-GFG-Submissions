// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
void seive(vector<int> &store_prime ,int n)
{
    vector<bool> is_prime(n + 1, true);
    
    for(int i = 2; i * i <= n; i ++)
    {
        if(is_prime[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    
    for(int i = 2; i <= n; i ++)
    {
        if(is_prime[i])
        {
            store_prime.push_back(i);
        }
    }
}
	
	int superPrimes(int n)
	{
	    vector<int> store_prime;
    
        seive(store_prime , n);
    
        set<int> s1;
    
        int count = 0;
    
        for(int i = 1; i < store_prime.size(); i ++)
        {
            if(s1.find(store_prime[i] - store_prime[i - 1]) != s1.end())
            {
                count ++;
            }
        
            s1.insert(store_prime[i - 1]);
        }
    
        return count;

	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends