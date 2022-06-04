class Solution {
    bool isSafe(int row, int col, char val, vector<vector<char>>& board)
    {
        unordered_set<char> rows, cols, subGrid;
        for(int i=0; i<board.size(); i++)
        {
            // row check
            if(rows.find(board[row][i]) != rows.end())
                return false;
            
            if(board[row][i] != '.')
                rows.insert(board[row][i]);
            
            // col check
            if(cols.find(board[i][col]) != cols.end())
                return false;
            
            if(board[i][col] != '.')
                cols.insert(board[i][col]);
            
            // sub-grid check
            if(subGrid.find(board[3*(row/3) + i/3][3*(col/3) + i%3]) != subGrid.end())
                return false;
            
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] != '.')
                subGrid.insert(board[3*(row/3) + i/3][3*(col/3) + i%3]);
        }
        
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    cout<<board[i][j]<<" ";
                    if(!isSafe(i, j, board[i][j], board))
                        return false;
                }
            }
        }
        
        return true;
    }
};