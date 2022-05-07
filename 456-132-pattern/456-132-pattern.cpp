class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        // creating a vector for storing minimum at every index
        vector<int> mini(n);
        
        mini[0] = nums[0];
        // updating minimum in every elements
        for(int i=1; i<n; i++)
            mini[i] = min(mini[i-1], nums[i]);
        
        stack<int> st; // creating stack for s3
        for(int i=n-1; i>=0; i--) { // this elements will be s2
            if(mini[i] < nums[i]) // ensuring s1 < s2
            {
                while(!st.empty() && st.top() <= mini[i]) // maintaining s1 < s3
                    st.pop();
                
                while(!st.empty() && st.top() < nums[i]) // s3 < s2
                    return true;
                    
                st.push(nums[i]);
            }
        }
        
        return false;
    }
};