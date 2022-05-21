// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        string ans = "";
        for(int i=0; i<S.size(); i++) {
            bool flag = true;
            for(int j=0; j<Q; j++) {
                if(i == index[j])
                {
                    if(S.substr(index[j], sources[j].length()) == sources[j])
                    {
                        ans += targets[j];
                        flag = false;
                        i = i + sources[j].length() - 1;
                    }
                }
            }
            if(flag) ans += S[i];
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends