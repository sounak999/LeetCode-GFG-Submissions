class Solution {
    bool isSafe(int row, int col, vector<vector<char>>& board, char val)
    {
        for(int i=0; i<board.size(); i++)
        {
            // row
            if(board[row][i] == val)
                return false;
            
            // col
            if(board[i][col] == val)
                return false;
            
            // sub-grid of 3x3
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        int n = board[0].size();
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(board[row][col] == '.')
                {
                    for(int val=1; val<=9; val++)
                    {
                        char ch = val + '0'; 
                        if(isSafe(row, col, board, ch))
                        {
                            board[row][col] = ch;
                            if(solve(board))
                                return true;
                            else
                                board[row][col] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};