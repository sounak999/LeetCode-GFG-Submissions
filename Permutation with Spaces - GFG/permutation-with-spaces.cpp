// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
vector<string> res;
public:
    vector<string> rec(string s1, string s2){
        if(s2 == ""){
            res.push_back(s1);
            return res;
        }
        int n = s2.length();
        
        for(int i=0;i<n;i++){
            string str1 = s2.substr(0, i+1), str2 = s2.substr(i+1, n);
            res = rec(s1+" "+str1, str2);
        }
        return res;
    }
    
    vector<string> permutation(string S){
        // Code Here
        int n = S.length();
        for(int i=0;i<n;i++){
            string s1 = S.substr(0, i+1), s2 = S.substr(i+1, n);
            res = rec(s1, s2);
        }
        return res;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends