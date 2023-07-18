// https://leetcode.com/problems/different-ways-to-add-parentheses

// Expression tree - using for loop to find all left and right possible results for the curr operand ie (........) + (.........)

class Solution {
public:
    int eval(int a, int b, char c)
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
                return -1;
        }
    }

    vector<int> recur(string s) {
        
        vector<int> res;

        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i])) continue;

            vector<int> left=recur(s.substr(0,i));
            vector<int> right=recur(s.substr(i+1));

            for(auto a: left)
            {
                for(auto b: right)
                {
                    res.push_back(eval(a,b,s[i]));
                }
            }
        }

        if(res.empty()) res.push_back(stoi(s)); // single num

        return res;
    }

    vector<int> diffWaysToCompute(string s) {
        return recur(s);    
    }
};
