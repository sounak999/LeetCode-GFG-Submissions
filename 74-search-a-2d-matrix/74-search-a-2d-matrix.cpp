class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int i = row-1, j = 0;
        while(j < col && i >= 0)
        {
            int ele = matrix[i][j];
            if(ele == target)
                return true;
            
            if(target < ele)
                i--;
            else
                j++;
        }
        
        return false;
    }
};