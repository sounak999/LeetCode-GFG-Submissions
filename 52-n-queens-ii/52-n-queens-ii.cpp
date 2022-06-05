class Solution {
    
    int solve(int col, vector<vector<int>> &board, vector<int> leftRow, vector<int> upperDiagonal, vector<int> lowerDiagonal, int n)
    {
        if(col == n)
            return 1;
        
        int cnt = 0;
        for(int row = 0; row < n; row++)
        {
            if(!leftRow[row] && !lowerDiagonal[row+col] && !upperDiagonal[n-1 + col-row])
            {
                board[row][col] = 1;
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                cnt += solve(col+1, board, leftRow, upperDiagonal, lowerDiagonal, n);
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
        
        return cnt;
    }
    
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        int col = 0;
        return solve(0, board, leftRow, upperDiagonal, lowerDiagonal, n);
    }
};