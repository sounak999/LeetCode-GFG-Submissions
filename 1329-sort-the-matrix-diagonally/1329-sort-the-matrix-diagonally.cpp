class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> res(row, vector<int> (col));
        
        for(int i=0; i<col; i++)
        {
            vector<int> cols;
            int j = 0, k = i;
            
            while(j < row && k < col)
            {
                cols.push_back(mat[j][k]);
                j++;
                k++;
            }
            
            j = 0, k = i;
            int idx = 0;
            sort(cols.begin(), cols.end());
            
            while(j < row && k < col && idx < cols.size())
            {
                res[j][k] = cols[idx];
                j++;
                k++;
                idx++;
            }
        }
        
        for(int i=1; i<row; i++)
        {
            vector<int> rows;
            int j = i, k = 0;
            
            while(j < row && k < col)
            {
                rows.push_back(mat[j][k]);
                j++;
                k++;
            }
            
            j = i, k = 0;
            int idx = 0;
            sort(rows.begin(), rows.end());
            
            while(j < row && k < col && idx < rows.size())
            {
                res[j][k] = rows[idx];
                j++;
                k++;
                idx++;
            }
        }
        
        return res;
    }
};