// https://leetcode.com/problems/decode-ways-ii

typedef long long ll;

class Solution {
public:
    ll m = 1e9+7;
    string s;
    
    ll dp[100001];
    
    int numDecodings(string s) {

        for(int i = 0 ; i <= s.size(); i++) dp[i] = -1;
        ll ans = recur(s,0);
        return ans;
    }
    
    ll recur(string &s, int pos){
        //we have reached the end. It is a possible decoding.
        
        if(pos >= s.size()) return 1;
        
        //check cache
        if(dp[pos] != -1) return dp[pos];
        
        //no decoding is possible if current char is 0
        if(s[pos] == '0') return dp[pos] = 0;
        
        //decode normally considering the current char to be anything 1-9 or *
        ll ans = 0;

        if(s[pos] == '*'){
            //if current char is * it can take values from 1-9 therefore multiply by 9
            ans = 9*recur(s,pos+1);
            
            //consider current * as 1
            //next char is 0-9
            if(pos+1 < s.size() and s[pos+1] >= '0' and s[pos+1] <= '9') ans += recur(s,pos+2);

            //next char is *
            if(pos+1 < s.size() and s[pos+1] == '*') ans += 9*recur(s,pos+2);
            
            //consider current * as 2
            //next char is 0-6
            if(pos+1 < s.size() and s[pos+1] >= '0' and s[pos+1] <= '6') ans += recur(s,pos+2);
            
            //next char is *
            if(pos+1 < s.size() and s[pos+1] == '*') ans = ans + (6*recur(s,pos+2));
        }

        else if(s[pos] == '1' and pos+1 < s.size())
        {
            ans=recur(s,pos+1);

            //next char is 0-9
            if(s[pos+1] >= '0' and s[pos+1] <= '9') ans += recur(s,pos+2);

            //next char is *
            else if(s[pos+1] == '*') ans += 9*recur(s,pos+2);
        }

        else if(s[pos] == '2' and pos+1 < s.size())
        {
            ans=recur(s,pos+1);
            
            //next char is 0-6
            if(s[pos+1] >= '0' and s[pos+1] <= '6') ans += recur(s,pos+2);

            //next char is *
            else if(s[pos+1] == '*') ans += 6*recur(s,pos+2);
        }

        else ans=recur(s,pos+1);
        
        //perform mod as and can be large (as given in question)
        ans = ans % m;
        
        //I will remember this result and return the result
        return dp[pos] = ans;
    }
};
