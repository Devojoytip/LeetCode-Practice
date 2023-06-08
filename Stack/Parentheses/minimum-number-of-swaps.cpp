// each swap reduces the no of extra closing brackets by half
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
// https://www.youtube.com/watch?v=3YDBT9ZrfaU

class Solution {
public:
    int minSwaps(string s) {
        int i=0,n=s.size(),cnt=0;
        stack<char> st;

        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            
            if(ch=='[') st.push(ch);
            
            else if(ch==']')
            {
                if(!st.empty()) st.pop();
            }
        }

        int open=st.size();
        return (open%2==0) ? open/2 : (open+1)/2;
    }
};
