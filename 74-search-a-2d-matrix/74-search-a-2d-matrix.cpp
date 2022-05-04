class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int i = 0, j = col-1;
        while(i < row && j >= 0)
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