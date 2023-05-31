// ADITYA VERMA playlist
// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i=0,j=0,cnt=0,ans=0;
        map<char,int> mp;
        
        while(j<s.size())
        {
            char ch=s[j];
            if(mp.find(ch)==mp.end())
            {
                mp[ch]=0;
                cnt++;
            }
            mp[ch]++;
            
            if(cnt==k) 
            {
                ans=max(ans,j-i+1);
                j++;
            }
            
            else if(cnt>k) 
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) 
                {
                    mp.erase(s[i]);
                    cnt--;
                }
                i++;
                j++;
            }
            
            else j++;
        }
        
        return (ans==0) ? -1 : ans;
    }
};
