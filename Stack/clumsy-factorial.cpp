// https://leetcode.com/problems/clumsy-factorial

class Solution {
public:
    int sol(int n) 
    {
        if(n==1 or n==0) return 1;

        int curr=n-1, op=0, sum=0;
        stack<int> st;
        st.push(n);

        while(curr!=0)
        {
            if(op==0) // multiplication
            {
                int num=st.top();
                st.pop();
                st.push(num*curr);
            }

            else if(op==1) // division
            {
                int num=st.top();
                st.pop();
                st.push(num/curr);
            }

            // + operation
            else if(op==2) st.push(curr);

            // - operation
            else st.push(-curr);

            curr--;
            op=(op+1)%4;
        }

        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }

        return sum;
    }

    int clumsy(int n) {
        return sol(n);
    }
};
