// https://leetcode.com/problems/shortest-distance-to-a-character

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        stack<int> st;
        vector<int> res(s.size(),s.size()+1);
        char ch='\0';
        int dis=0;

        for(int i=0;i<s.size();i++)
        {
            if(ch=='\0')
            {
                if(s[i]!=c) st.push(i);
                else 
                {
                    ch=c;
                    res[i]=0;
                    dis=1;
                    while(!st.empty())
                    {
                        int idx=st.top();
                        st.pop();
                        res[idx]=min(dis,res[idx]);
                        dis++;
                    }
                    dis=1;
                }
            }
            else
            {
                if(s[i]!=c)
                {
                    int idx=i;
                    res[idx]=dis;
                    st.push(i);
                    dis++;
                }
                else 
                {
                    dis=1,res[i]=0;
                    while(!st.empty())
                    {
                        int idx=st.top();
                        st.pop();
                        res[idx]=min(dis,res[idx]);
                        dis++;
                    }
                    dis=1;
                }
            }
        }

        return res;
    }
};
