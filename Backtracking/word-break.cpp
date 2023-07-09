// https://practice.geeksforgeeks.org/problems/word-break1352/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution
{
public:
    int recur(string s, int idx, int n, map<string,bool> mp) {
        //code here
        
        if(idx==n) return 1;
        
        for(int i=idx;i<n;i++)
        {
            string temp = s.substr(idx,i-idx+1);
            if(mp.find(temp)!=mp.end())
            {
                if(recur(s,i+1,n,mp)) return 1;
            }
            
        }
        
        return 0;
    }
    int wordBreak(string s, vector<string> &v) {
        //code here
        map<string,bool> mp;
        int n = s.size();
        for(auto it: v) mp[it]=1;
        
        return recur(s,0,n,mp);
    }
};
