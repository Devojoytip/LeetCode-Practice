// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,cnt=t.size(),ans=1e7,start=-1;

        vector<int> freq(128,0);
        vector<int> curr(128,0);

        for(auto it:t) freq[it]++; 

        while(j<s.size())
        {
            char ch=s[j];

            if(freq[ch]>curr[ch]) cnt--;

            curr[ch]++;
            
            if(cnt==0)
            {
                while(i<=j)
                {
                    char temp=s[i];
                    if(curr[temp]==freq[temp]) break;
                    curr[temp]--;
                    i++;
                }
                if(ans>j-i+1)
                {
                    ans=j-i+1;
                    start=i;
                }
            }
            j++;
        }

        return (start==-1) ? "" : s.substr(start,ans);
    }
};
