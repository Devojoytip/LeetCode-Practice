// https://leetcode.com/problems/max-chunks-to-make-sorted-ii

class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        
        stack<int> st;

        for(int i=0;i<v.size();i++)
        {
            int maxi=v[i];
            while(!st.empty() and st.top()>v[i]) 
            {
                maxi=max(maxi,st.top());
                st.pop();
            }
            st.push(maxi);
        }

        return st.size();
    }
};
