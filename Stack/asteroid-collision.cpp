// https://leetcode.com/problems/asteroid-collision 

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {

        int n=v.size();
        stack<int> st;

        for(auto it : v)
        {
            if(it>0) st.push(it);
            
            else
            {
                while(!st.empty() and st.top()>0 and st.top() < -it) st.pop();
                
                if(st.size() and st.top() == -it) st.pop();
                
                else if(st.size() and st.top() > -it) {}
                
                else st.push(it);
                
            }
        }

        vector<int> res;
        while(st.size())
        {
            res.push_back(st.top());
            st.pop();   
        }
        reverse(res.begin(),res.end());

        return res;
    }
};
