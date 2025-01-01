class Solution {
public:

    bool check(vector<vector<char>>& board, int a, int b, char x) {
        for(int i = 0; i<9; i++) 
            if(board[i][b] == x) return false;

        for(int j = 0; j<9; j++)
            if(board[a][j] == x) return false;
        
        int r = (a/3)*3;
        int c = (b/3)*3;
        for(int i = 0; i<3; i++)
            for(int j = 0; j<3; j++) 
                if(board[r+i][c+j] == x) return false;
        
        return true;
    }

    bool generate(vector<vector<char>>& board, int i, int j) {
        if(i == 8 &&  j == 9) return true;
        if(j == 9) return generate(board, i+1, 0);
        if(board[i][j] != '.') return generate(board, i, j+1);

        for(char ch = '1'; ch <= '9'; ch++) {
            if(check(board, i, j, ch))  {
                board[i][j] = ch;
                if(generate(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        generate(board, 0, 0);
    }
};