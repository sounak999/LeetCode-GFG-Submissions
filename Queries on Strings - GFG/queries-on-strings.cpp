// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    vector<int> ans;    
	    for(int i=0; i<Query.size(); i++)
	    {
	        unordered_set<char> st;
	        int start = Query[i][0]-1, end = Query[i][1]-1; 
	        
	        for(int j=start; j<=end; j++)
	        {
	            st.insert(str[j]);
	        }
	        int size = st.size();
	        ans.push_back(size);
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends