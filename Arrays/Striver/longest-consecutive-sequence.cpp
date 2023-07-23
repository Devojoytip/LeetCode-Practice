// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        
        int n=v.size(), ans=0;
        set<int> s;

        for(int i=0;i<n;i++) s.insert(v[i]);

        for(int i=0;i<n;i++) 
        {
            int num=v[i];

            if(s.find(num-1)==s.end())
            {
                int cnt=1;
                num+=1;

                while(s.find(num)!=s.end())
                {
                    cnt++;
                    num++;
                }

                ans=max(ans,cnt);
            }
        }

        return ans;
    }
};
