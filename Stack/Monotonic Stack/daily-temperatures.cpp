// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        
        int n = v.size();
        stack<int> st;
        vector<int> res(n,0);

        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                res[i]=0;
                st.push(i);
            }
            else
            {
                while(!st.empty() and v[st.top()]<=v[i]) st.pop();

                if(st.empty()) res[i]=0;

                else res[i]=st.top()-i;
                
                st.push(i);
            }
        }

        return res;
    }
};
