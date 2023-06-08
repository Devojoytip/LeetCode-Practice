/*

https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

*/

class Solution {
public:
    int minAddToMakeValid(string s) {
      
        int i=0,n=s.size(),cnt=0;
        stack<char> st;

        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            
            if(ch=='(') st.push(ch);
            
            else if(ch==')')
            {
                if(!st.empty() and st.top()=='(') st.pop();
                else cnt++;
            }
        }

        cnt+=st.size();

        return cnt;
    }
};
