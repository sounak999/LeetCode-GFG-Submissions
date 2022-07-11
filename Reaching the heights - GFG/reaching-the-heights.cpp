// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int arr[]) {
    bool flag = true;
    for(int i=1; i<n; i++)
    {
        if(arr[i] != arr[i-1])
            flag = false;
    }
    
    if(flag && n > 1) return {-1};
    
    sort(arr, arr+n, greater<int>());
    
    vector<int> ans(n, -1);
    int i = 0, j = n-1;
    for(int k=0; k<n; k++)
    {
        if(k&1)
        {
            ans[k] = arr[j--];
        }
        else
        {
            ans[k] = arr[i++];
        }
    }
    
    return ans;
}
