// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        string res="", st="";
        
        for(auto ch: s) 
        {
            if(ch == ' ') 
            {
                reverse(st.begin(), st.end());
                res += st;
                res += ' ';
                st.clear();
            }
            else st+=ch;
        }

        reverse(st.begin(), st.end());
        res += st;
        
        return res;
    }
};
