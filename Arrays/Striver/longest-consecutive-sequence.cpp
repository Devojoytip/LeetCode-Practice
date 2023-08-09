// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        
        if(v.size()==0) return 0;
        
        int ans=1;

        unordered_map<int, int> mp;

        for(auto it: v) mp[it]=1;

        for(int i=0;i<v.size();i++)
        {
            int num=v[i];
            if(mp.find(num-1)!=mp.end()) continue;

            int cnt=0;
            while(mp.find(num)!=mp.end())
            {
                cnt++;
                num++;
            }
            ans=max(ans, cnt);
        }

        return ans;
    }
};
