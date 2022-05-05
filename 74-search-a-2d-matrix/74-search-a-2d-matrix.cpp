class Solution {
    bool binarySearch(vector<vector<int>>& matrix, int target, int row, int s, int e)
    {
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            if(target == matrix[row][mid])
                return true;
            else if(target < matrix[row][mid])
                e = mid-1;
            else
                s = mid+1;
        }
        
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int s = 0, e = row-1;
        while(s <= e)
        {
            int mid = s+(e-s)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][col-1])
            {
                return binarySearch(matrix, target, mid, 0, col-1);
            }
            else if(target < matrix[mid][0])
                e = mid-1;
            else
                s = mid+1;
        }
        
        return false;
    }
};