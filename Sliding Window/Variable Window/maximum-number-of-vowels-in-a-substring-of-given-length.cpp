// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0,ans=0,cnt=0;

        while(j<s.size())
        {
            char ch=s[j];
            
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') cnt++;
            
            if(j-i+1==k)
            {
                ans=max(ans,cnt);
                char ch0=s[i];
                if(ch0=='a' or ch0=='e' or ch0=='i' or ch0=='o' or ch0=='u') cnt--;
                i++;
                j++;
            }
            else j++;
        }

        return ans;
    }
};
