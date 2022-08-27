class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size(), res = INT_MIN;
        
        for(int colStart = 0; colStart < cols; colStart++)
        {
            vector<int> dp(rows, 0);
            for(int colEnd = colStart; colEnd < cols; colEnd++)
            {
                // taking 1D array of row size to store column Sum
                for(int rowIdx = 0; rowIdx < rows; rowIdx++)
                {
                    // for(int col = colStart; col <= colEnd; col++)
                    // {
                        dp[rowIdx] += matrix[rowIdx][colEnd];
                    // }
                }
                
                // kadane's algo on dp array to find
                // maximum sum no larger than k
                int currSum = 0, currMax = INT_MIN;
                set<int> st = {0};
                for(auto x: dp)
                {
                    currSum += x;
                    auto it = st.lower_bound(currSum - k);
                    
                    if(it != st.end())
                        currMax = max(currMax, currSum - *it);
                    
                    st.insert(currSum);
                }
                
                res = max(res, currMax);
            }
        }
        
        return res;
    }
};