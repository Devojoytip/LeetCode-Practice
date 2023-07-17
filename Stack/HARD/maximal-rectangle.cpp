// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int largestRectangleArea(vector<int> v)
    {
        int n=v.size(), ans=0;
        stack<int> ls;
        stack<int> rs;
        vector<int> l(n);
        vector<int> r(n);

        l[0]=0;
        r[n-1]=n-1;

        for(int i=0;i<n;i++)
        {
            if(ls.empty()) ls.push(i);
            else
            {
                while(ls.size() and v[ls.top()]>=v[i]) ls.pop();
                if(ls.size()) l[i]=ls.top()+1;
                else l[i]=0;
                ls.push(i);
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(rs.empty()) rs.push(i);
            else
            {
                while(rs.size() and v[rs.top()]>=v[i]) rs.pop();
                if(rs.size()) r[i]=rs.top()-1;
                else r[i]=n-1;
                rs.push(i);
            }
        }

        for(int i=0;i<n;i++) ans=max(ans, v[i]*(r[i]-l[i]+1));

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& v) {
        
        int n=v.size();
        int m=v[0].size();
        int ans=0;
        vector<int> hist(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='0') hist[j]=0;
                else hist[j]++;
            }

            ans=max(ans, largestRectangleArea(hist));
        }

        return ans;
    }
};
