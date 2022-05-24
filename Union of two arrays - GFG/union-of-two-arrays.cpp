// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int arr1[], int n1, int arr2[], int n2)  {
        vector<int> ans;
        sort(arr1, arr1 + n1);
        sort(arr2, arr2 + n2);
        
        int i = 0, j = 0, res = 0, last;
        while(i < n1 && j < n2)
        {
            if(arr1[i] < arr2[j])
            {
                // if(ans.empty() || ans.back() != arr1[i])
                //     ans.push_back(arr1[i]);
                if(i == 0 || (i>0 && last != arr1[i]))    
                {
                    last = arr1[i];
                    res++;
                }
                
                i++;
            }
            else if(arr2[j] < arr1[i])
            {
                // if(ans.empty() || ans.back() != arr2[j])
                //     ans.push_back(arr2[j]);
                if(j == 0 || (j>0 && last != arr2[j]))    
                {
                    last = arr2[j];
                    res++;
                } 
                    
                j++;
            }
            else
            {
                // if(ans.empty() || ans.back() != arr1[i])
                //     ans.push_back(arr1[i]);
                if(i == 0 || (i>0 && last != arr1[i]))    
                {
                    last = arr1[i];
                    res++;
                }
                    
                i++;
                j++;
            }
        }
        
        while(i < n1)
        {
            // if(ans.back() != arr1[i])
            //         ans.push_back(arr1[i]);
            if(i == 0 || i>0 && last != arr1[i])
            {
                last = arr1[i];
                res++;
            }   
            
            i++;
        }
        
        while(j < n2)
        {
            // if(ans.back() != arr2[j])
            //         ans.push_back(arr2[j]);
            if(j==0 || j>0 && last != arr2[j])
            {
                last = arr2[j];
                res++;
            } 
                    
            j++;
        }
        
        // for(int x: ans)
        //     cout<<x<<" ";
        // cout<<endl;
            
        // return ans.size();
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends