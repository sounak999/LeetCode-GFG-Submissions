class Solution {
    bool isSafe(int row, int col, vector<vector<int>> &board, int n)
    {
        int duprow = row, dupcol = col;
        // upper left diagonal
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 1)
                return false;
            
            row--;
            col--;
        }
        
        // left 
        row = duprow, col = dupcol;
        while(col >= 0)
        {
            if(board[row][col] == 1)
                return false;
            
            col--;
        }
        
        // lower left diagonal
        row = duprow, col = dupcol;
        while(row < n && col >= 0)
        {
            if(board[row][col] == 1)
                return false;
            
            row++;
            col--;
        }
        
        return true;
    }
    
    int solve(int col, vector<vector<int>> &board, int n)
    {
        if(col == n)
            return 1;
        
        int cnt = 0;
        for(int row = 0; row < board.size(); row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 1;
                cnt += solve(col+1, board, n);
                board[row][col] = 0;
            }
        }
        
        return cnt;
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        int col = 0;
        return solve(0, board, n);
    }
};