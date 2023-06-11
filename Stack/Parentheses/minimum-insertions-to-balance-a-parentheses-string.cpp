// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string

class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int i=0,ans=0;

        while(i<s.size())
        {
            char ch=s[i];
            if(ch=='(') 
            {
                st.push(ch);
                i++;
            }
            else
            {
                int cnt=0;
                while(i<s.size() and s[i]==ch)
                {
                    cnt++;
                    i++;
                }
                if(cnt%2==1) 
                {
                    cnt++;
                    ans++;
                }
                int open=cnt/2;
                while(!st.empty() and st.top()=='(' and open>0) 
                {
                    open--;
                    st.pop();
                }
                if(open>0 and st.empty()) 
                {
                    ans+=open;
                }
            }
            
        }

        ans+=2*st.size();

        return ans;
    }
};
