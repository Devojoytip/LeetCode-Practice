// https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution {
public:
    int eval(int a,int b,char c)
    {
        switch(c)
        {
            case '+':
                return a+b;
            
            case '-':
                return a-b;
            
            case '*':
                return a*b;

            default:
                return 0;
        }
    }

    vector<int> sol(string s) 
    {

       vector<int> v;
       int i=0;

       for(int i=0; i<s.size(); i++)
       {
           if(isdigit(s[i])) continue;

           vector<int> left=sol(s.substr(0,i));
           vector<int> right=sol(s.substr(i+1));

           for(auto a: left)
           {
               for(auto b: right)
               {
                   v.push_back(eval(a,b,s[i]));
               }
           }
       }

       if(v.empty()) v.push_back(stoi(s));

       return v;
    }
    vector<int> diffWaysToCompute(string s) {
        return sol(s);
    }
};
