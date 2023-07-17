// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        
        int n(v.size()),maxi(-1);
        
        stack<int> ls;
        stack<int> rs;
        vector<int> l(n);
        vector<int> r(n);
        r[n-1]=n-1;

        for(int i=0;i<n;i++)
        {
            if(ls.empty()) ls.push(i);
            else
            {
                while(!ls.empty() and v[ls.top()] >= v[i]) ls.pop();
                if(ls.empty()) l[i]=0;
                else l[i]=ls.top()+1; // as we have to exclude it so take everything after it
                ls.push(i);
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(rs.empty()) rs.push(i);
            else
            {
                while(!rs.empty() and v[rs.top()] >= v[i]) rs.pop();
                if(rs.empty()) r[i]=n-1;
                else r[i]=rs.top()-1; // as we have to exclude it so take everything before it
                rs.push(i);
            }
        }
        
        for(int i=0;i<n;i++) maxi=max(maxi,v[i]*(r[i]-l[i]+1));
        return maxi;
    }
};
