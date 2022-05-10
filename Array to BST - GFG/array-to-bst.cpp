// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void convertToBST(vector<int> &nums, int start, int end, vector<int> &pre)
    {
        if(start > end) return ;
        int mid = start + (end-start)/2;
        pre.push_back(nums[mid]);
        convertToBST(nums, start, mid-1, pre);
        convertToBST(nums, mid+1, end, pre);
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> preorder;
        int size = nums.size();
        convertToBST(nums, 0, size-1, preorder);
        return preorder;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends