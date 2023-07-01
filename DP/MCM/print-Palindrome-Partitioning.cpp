// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string s)
    {
        string a=s;
        reverse(s.begin(),s.end());
        return a==s;
    }
    void sol(string s,int i,vector<string> v)
    {
        if(i==s.length())
        {
            res.push_back(v);
            return;
        }
        for(int k=i;k<s.length();k++)
        {
            string s1=s.substr(i,k-i+1);
            if(isPalindrome(s1)) 
            {
                v.push_back(s1);
                sol(s,k+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        sol(s,0,v);
        return res;
    }
};
