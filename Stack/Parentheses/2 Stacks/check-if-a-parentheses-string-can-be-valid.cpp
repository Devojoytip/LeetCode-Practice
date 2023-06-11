// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

// stack 1 - only open brackets which can't be changed
// stack 2 - all brackets which can be changed

class Solution {
public:
    bool canBeValid(string s, string lock) {
        int i=0;
        stack<int> open;
        stack<int> change;

        while(i < s.size())
        {
            if(s[i]=='(' and lock[i]=='1') open.push(i);
            
            else if(s[i]=='(' and lock[i]=='0') change.push(i);
            
            else if(s[i]==')' and lock[i]=='0') change.push(i);

            else
            {
                if(!open.empty()) open.pop();
                else if(!change.empty()) change.pop();
                else return 0;
            }

            i++;
        }

        while(!open.empty())
        {
            if(change.empty() or change.top()<open.top()) return 0;
            else
            {
                open.pop();
                change.pop();
            }
        }

        if(change.size()%2==1) return false;

        return 1;
    }
};
