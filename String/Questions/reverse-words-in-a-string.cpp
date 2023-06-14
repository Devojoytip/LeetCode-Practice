// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {

        string word="";
        string res="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ') 
            {
                if(i==0 or s[i-1]==' ') continue;
                else 
                {
                    if(res!="") res=word+" "+res;
                    else res=word;
                    word="";
                }
            }
            else word=word+s[i];
        }

        if(word!="")
        {
            if(res!="") res=word+" "+res;
            else res=word;
        }
        
        return res;
    }
};
