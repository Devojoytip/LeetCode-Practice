// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {

        vector<int> res(v.size(),-1);
        int n=v.size();
        stack<int>st;
        st.push(-1);

        // checking all ele from 0 to n-2 for last - (n-1)th ele
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and st.top()<=v[i]) st.pop();
            st.push(v[i]);
        }      

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=v[i]) st.pop();
            res[i] = (st.empty()) ? -1 : st.top();
            st.push(v[i]);
        }      

        return res;
    }
};
