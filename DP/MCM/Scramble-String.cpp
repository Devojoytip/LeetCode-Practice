// https://leetcode.com/problems/scramble-string/description/

class Solution {
public:
    unordered_map<string,bool> mp;

    bool MCM(string a, string b) 
    {
        int n=a.size(), m=b.size();

        if(n!=m or n==0 or m==0) return 0;
        
        if(n==1) return a==b;

        string key=a+"-"+b;

        if(mp.find(key)!=mp.end()) return mp[key];

        int i=0,j=n-1;
        
        for(int k=i;k<j;k++)
        {
            string leftA=a.substr(i,k-i+1);
            string rightA=a.substr(k+1);

            string leftB=b.substr(i,k-i+1);
            string rightB=b.substr(k+1);

            bool NoSwapAns=MCM(leftA,leftB) and MCM(rightA,rightB);
            bool SwapAns=MCM(leftA,b.substr(j-k,leftA.size())) and MCM(rightA,b.substr(i,rightA.size()));
            
            if(SwapAns) return mp[key]=1;
            if(NoSwapAns) return mp[key]=1;
        }

        return mp[key]=0;
    }
    bool isScramble(string a, string b) {
        return MCM(a,b);
    }
};
