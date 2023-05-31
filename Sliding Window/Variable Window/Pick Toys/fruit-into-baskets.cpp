// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& v) {
        int i=0,j=0,total=0,ans=0,cnt=0;

        map<int,int> mp;

        while(j<v.size())
        {
            int curr=v[j];
            if(mp.find(curr)==mp.end() and cnt<2)
            {
                mp[curr]=1;
                cnt++;
                total++;
                ans=max(ans,total);
                j++;
            }
            else if(mp.find(curr)==mp.end() and cnt==2)
            {
                mp[curr]=1;
                while(cnt!=1)
                {
                    mp[v[i]]--;
                    if(mp[v[i]]==0) 
                    {
                        mp.erase(v[i]);
                        cnt--;
                    }
                    i++;
                }
                total=j-i+1;
                ans=max(ans,total);
                j++;
                cnt=2;
            }
            else
            {
                total++;
                ans=max(ans,total);
                j++;
                mp[curr]++;
            }
        }

        return ans;
    }
};
