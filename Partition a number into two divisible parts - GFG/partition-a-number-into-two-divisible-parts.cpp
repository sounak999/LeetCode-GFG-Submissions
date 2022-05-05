// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        for(int i=0; i<S.size()-1; i++)
        {
            string first = S.substr(0, i+1), second = S.substr(i+1);
            if(stoi(first)%a == 0 && stoi(second)%b == 0)
            {
                return first + " " + second;
            }
        }
        
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends