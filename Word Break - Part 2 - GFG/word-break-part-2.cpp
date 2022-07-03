// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    unordered_map<string, int> freq;
    vector<string> ans;
    
    void solve(string s, vector<string>& dict, int n, string curr)
    {
        if(s.length() == 0)
        {
            curr.pop_back();
            ans.push_back(curr);
            return ;
        }
        
        for(int i=0; i<s.length(); i++) 
        {
            string temp = s.substr(0, i+1);
            if(freq[temp])
            {
                temp += " ";
                solve(s.substr(i+1), dict, n, curr+temp);
            }
        }
    }
    
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        for(auto i: dict)
            freq[i]++;
            
        solve(s, ans, n, "");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends