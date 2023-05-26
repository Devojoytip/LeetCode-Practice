// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool valid(vector<vector<char>>& v,int row,int col,char ch)
    {
        if(v[row][col]=='.') return 1;
        
        for(int k=0;k<9;k++)
        {
            if(k!=row and v[k][col]==ch) return 0;

            if(k!=col and v[row][k]==ch) return 0;

            if(3*(row/3) + k/3!=row and 3*(col/3) + k%3!=col and v[3*(row/3) + k/3][3*(col/3) + k%3]==ch) return 0;
        }

        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& v) {
        vector<bool> vis(10,false);

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(!valid(v,i,j,v[i][j])) return 0;
            }
        }

        return 1;
    }
};
