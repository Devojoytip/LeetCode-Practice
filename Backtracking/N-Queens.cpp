// https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool isValid(int n, vector<string> &board, int row, int col) 
    {
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q') return 0; // check the column
            // if(board[row][i]=='Q') return 0; // check the row but not needed
        }  

        int i=row, j=col;
        while(i!=0 and j!=0) // diagonal
        {
            i--; 
            j--;
            if(board[i][j]=='Q') return 0;
        }

        i=row, j=col;
        while(i!=0 and j!=n-1) // anti-diagonal
        {
            i--; 
            j++;
            if(board[i][j]=='Q') return 0;
        }

        return 1;
    }

    void recur(int n, vector<vector<string>> &res, vector<string> &board, int row, int cnt) 
    {
        if(cnt==n)    
        {
            res.push_back(board);
            return;
        }

        if(row==n) return;

        for(int i=0;i<n;i++)
        {
            if(isValid(n,board,row,i))
            {
                board[row][i]='Q';
                recur(n,res,board,row+1,cnt+1);
                board[row][i]='.'; // back-tracking
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> board;
        string s="";
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++) board.push_back(s);
        
        recur(n,res,board,0,0);

        return res;
    }
};
