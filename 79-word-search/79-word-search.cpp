class Solution {
    bool solve(vector<vector<char>>& board, int i, int j, int index, string& word)
    {
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] == '.' || board[i][j] != word[index])
            return false;
        
        if(index == word.length()-1)
            return true;
        
        char ch = board[i][j];
        board[i][j] = '.';
        index += 1;
        
        bool left = solve(board, i, j-1, index, word);
        bool right = solve(board, i, j+1, index, word);
        bool up = solve(board, i-1, j, index, word);
        bool down = solve(board, i+1, j, index, word);
        
        board[i][j] = ch;
        index -= 1;
        
        return (left || right || up || down);
    }
        
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(solve(board, i, j, 0, word))
                    return true;
            }
        }
        
        return false;
    }
};