// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    int sol(string s, int &l,int &r,int n)
    {
        while(l>=0 and r<n and s[l]==s[r]) l--, r++;
        return r-l-1;
    } 

    string longestPalindrome(string s) {
        
        int n=s.size(), maxLen=0;
        string res="";

        for(int i=0;i<n;i++)
        {
            int l=i,r=i+1;
            int evenPalLen=sol(s,l,r,n);
            if(evenPalLen>maxLen) 
            {
                maxLen=evenPalLen;
                res=s.substr(l+1,evenPalLen);
            }

            l=i,r=i;
            int oddPalLen=sol(s,l,r,n);
            if(oddPalLen>maxLen) 
            {
                maxLen=oddPalLen;
                res=s.substr(l+1,oddPalLen);
            }
        }

        return res;
    }
};
