// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        int i=0;
        stack<int> open;
        stack<int> star;

        while(i < s.size())
        {
            if(s[i]=='(') open.push(i);

            else if(s[i]=='*') star.push(i);

            else
            {
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return 0;
            }

            i++;
        }

        while(!open.empty())
        {
            if(star.empty() or star.top()<open.top()) return 0;
            else
            {
                open.pop();
                star.pop();
            }
        }

        return 1;
    }
};
