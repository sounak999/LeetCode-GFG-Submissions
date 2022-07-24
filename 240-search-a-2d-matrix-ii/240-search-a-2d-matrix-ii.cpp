class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int i=0, j=n-1;
        while(i < m && j >= 0)
        {
            int ele = matrix[i][j];
            if(ele == target)
                return true;
            
            if(target < ele)
                j--;
            else
                i++;
        }
        
        return false;
    }
};