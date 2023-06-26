// https://leetcode.com/problems/next-greater-element-i 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v, vector<int>& u) {
        
        vector<int> tem(u.size(),-1);
        vector<int> res(v.size(),-1);;
        stack<int>st;
        st.push(-1);

        for(int i=u.size()-1;i>=0;i--)
        {
            if(st.top()==-1) st.push(u[i]);
            else
            {
                while(st.top()!=-1 and st.top()<=u[i]) st.pop();
                tem[i]=st.top();
                st.push(u[i]);
            }
        }

        for(int i=0;i<v.size();i++)
        {
            int idx= find(u.begin(),u.end(),v[i])-u.begin();
            res[i]=tem[idx];
        }

        return res;
    }
};
