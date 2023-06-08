/*

https://leetcode.com/problems/validate-stack-sequences

then we start moving our i pointer and for every index in pushed array 
push[i] == pop[j] - increment i and j (mean we have pushed that element and at the same time poped also)
then we check if the top of the stack is equal to pop[j] then we keep doing pop() operation on stack until the stack.size()!=0 and j<n.

*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        int m=pushed.size(),n=popped.size();
        if(n!=m) return 0;
        stack<int> st;

        while(i<m and j<n)
        {
            while(i<m and pushed[i]!=popped[j])
            {
                st.push(pushed[i]);
                i++;
            } 
            while(i<m and j<n and pushed[i]==popped[j]) 
            {
                i++;
                j++;
            }
            while(!st.empty() and j<n and popped[j]==st.top()) 
            {
                st.pop();
                j++;
            }         
        }
        
        return (st.empty()) ? 1 : 0;
    }
};
