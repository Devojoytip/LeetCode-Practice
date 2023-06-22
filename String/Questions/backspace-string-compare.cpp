// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    string processString(string s){
        int i = 0;
        int j = -1;
        int n =s.size();

        while(i < n)
       {
           if(s[i] == '#')
           {
            if(j != -1)
                j= j-1;
           }
           else{
               j++;
               s[j] = s[i];
           }
           i++;
       } 
       return j== -1? "" : s.substr(0, j+1);
    }

    bool backspaceCompare(string s, string t) 
    {
        return processString(s) == processString(t);    
;   }
};
