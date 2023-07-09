// https://leetcode.com/problems/sudoku-solver 

class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char c) 
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c) return 0;
            if(board[row][i]==c) return 0;
        }

        int X_Start=(row/3)*3, Y_Start=(col/3)*3;

        for(int i=0;i<9;i++)
        {
            int new_X=X_Start+(i/3);
            int new_Y=Y_Start+(i%3);

            if(board[new_X][new_Y]==c) return 0;
        }

        return 1;
    }

    bool recur(vector<vector<char>>& board) {

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c)) 
                        {
                            board[i][j]=c;
                            
                            if(recur(board)) return 1;
                            
                            board[i][j]='.';
                        }
                    }

                    return 0;
                }
            }
        }

        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        recur(board);
    }
};
