// https://leetcode.com/problems/palindrome-partitioning/description/

// Simple Recursion

class Solution {
public:

    bool isPal(string s)
    {
        string a = s;
        reverse(s.begin(),s.end());
        return a==s;
    }

    void recur(string s, vector<string> v, vector<vector<string>> &res, int i, int n) {

       if(i==n) 
       {
           res.push_back(v);
           return;
       }

       for(int k=i;k<n;k++)
       {
           string curr=s.substr(i,k-i+1);

           if(isPal(curr))
           {
               v.push_back(curr);
               recur(s,v,res,k+1,n);
               v.pop_back();
           }
       }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;

        recur(s,{},res,0,s.size());

        return res;
    }
};
