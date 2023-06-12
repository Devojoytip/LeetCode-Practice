/*

https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

since we have to remove brackets, we need to store their indices as well

at the end st will have extra braces
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push({s[i],i});

            else if(s[i]==')')
            {
                if(!st.empty() and st.top().first=='(') st.pop();
                else st.push({s[i],i});
            }

            else continue;
        }

        while(!st.empty()) 
        {
            s.erase(st.top().second,1);
            st.pop();
        }
        return s;
    }
};
