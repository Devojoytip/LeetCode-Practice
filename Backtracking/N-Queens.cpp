// https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool check(int n,int x,int y,vector<string> &board) 
    {
        for(int i=0;i<n;i++) 
        {
            if(board[x][i]=='Q' or board[i][y]=='Q') return 0;
        }

        int i=x,j=y;

        while(i>=0 and j>=0)
        {
            if(board[i][j]=='Q') return 0;
            i--;j--;
        }

        i=x,j=y;

        while(i>=0 and j<n)
        {
            if(board[i][j]=='Q') return 0;
            i--;j++;
        }

        return 1;
    }

    void dfs(int n,int row,int cnt,vector<vector<string>> &res,vector<string> &board) 
    {
        if(cnt==n)
        {
            res.push_back(board);
            return;
        }

        if(row>=n) return;

        for(int i=0;i<n;i++)
        {
            if(check(n,row,i,board)) 
            {
                board[row][i]='Q';
                dfs(n,row+1,cnt+1,res,board);
                board[row][i]='.';
            }    
        }      
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board;
        vector<vector<string>> res;
        string s;
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++) board.push_back(s);
        dfs(n,0,0,res,board);
        return res;       
    }
};
