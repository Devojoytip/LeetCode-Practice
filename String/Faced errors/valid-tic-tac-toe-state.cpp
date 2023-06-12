// https://leetcode.com/problems/valid-tic-tac-toe-state

class Solution {
public:
    bool findWinner(vector<string>& v,string s)
    {
        for(int i=0;i<3;i++)
        {
            // horizontal
            if(v[i]==s) return 1;

            // vertical
            string temp="";
            temp = temp + v[0][i]+v[1][i]+v[2][i];
            if(temp==s) return 1;

             /* NOTE: Direct v[0][i]+v[1][i]+v[2][i] == s will not work as to compare the concatenation of characters from v with the string s, 
             you need to ensure that the concatenation operation is performed correctly. 
             One way to achieve this is by converting the characters to strings before concatenating them.
             */
        }

        string dia_1="";
        dia_1 = dia_1 + v[0][0]+v[1][1]+v[2][2];
        string dia_2="";
        dia_2+= dia_2 + v[0][2]+v[1][1]+v[2][0];

        if(dia_1==s) return 1;
        if(dia_2==s) return 1;

        return 0;
    }

    bool validTicTacToe(vector<string>& v) {

        int x_cnt=0,o_cnt=0;

        for(auto u:v)
        {
            for(auto it:u) 
            {
                if(it=='X') x_cnt++;
                if(it=='O') o_cnt++;
            }
        }

        bool X_winner=findWinner(v,"XXX");
        bool O_winner=findWinner(v,"OOO");

        if(X_winner and O_winner) return 0; // no 2 winners poss.

        if(X_winner) 
        {
            if(x_cnt==o_cnt+1) return 1;
            return 0;
        }

        if(O_winner) 
        {
            if(x_cnt==o_cnt) return 1;
            return 0;
        }

        if(x_cnt==o_cnt) return 1;

        return (x_cnt > o_cnt) and (x_cnt - o_cnt == 1);
    }
};
