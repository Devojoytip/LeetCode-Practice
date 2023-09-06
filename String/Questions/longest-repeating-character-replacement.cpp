// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int i=0, j=0, maxi=0, ans=0;
        unordered_map<char, int> mp;

        while(j<s.size())
        {
            char c=s[j];
            mp[c]++;
            
            maxi=max(maxi, mp[c]);
            
            int rem=j-i+1-maxi;

            if(rem>k)
            {
                mp[s[i]]--;
                i++;
            }

            ans=max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};
