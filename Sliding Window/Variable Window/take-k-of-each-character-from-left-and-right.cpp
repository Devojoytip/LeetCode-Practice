// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

class Solution {
public:
    int takeCharacters(string s, int k) {
        map<char,int> mp;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;

        for(int i=0;i<s.size();i++) mp[s[i]]++;

        if(k==0) return 0;
        if(mp['a']-k<0) return -1;
        if(mp['b']-k<0) return -1;
        if(mp['c']-k<0) return -1;

        mp['a']-=k;
        mp['b']-=k;
        mp['c']-=k;

        int i=0,j=0,ans=0;

        while(j<s.size())
        {
            char ch=s[j];
            mp[ch]--;
            if(mp[ch]<0)
            {
                ans=max(ans,j-i);
                while(i<j and mp[ch]<0)
                {
                    mp[s[i]]++;
                    i++;
                }
                if(mp[ch]<0)
                {
                    mp[ch]=0;
                    j++;
                    i=j;
                }
                else j++;
            }
            else j++;
            
        }
        ans=max(ans,j-i);
        return s.size()-ans;
    }
};
