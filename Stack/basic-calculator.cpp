// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s)
    {
        int i=0;
        return recur(s,i);
    }

    int recur(string s,int &i) {

        int n=s.size(),num=0,sign=1,res=0;
        stack<char> st;

        for(;i<n;i++)
        {
            char c=s[i];
            if(c==' ') continue;
            else if(c=='(') 
            {
                i=i+1;
                res += recur(s,i)*sign;
            }
            else if(c==')') break;
            else if(c=='-' or c=='+')
            {
                res+=sign*num;
                num=0;
                sign = (c=='+') ? 1 : -1;
            }
            else num=num*10 + (c-'0');
        }

        return res + sign*num;
    }
};
