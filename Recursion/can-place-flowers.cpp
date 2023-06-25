// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    int solve(int i,int n,vector<int>& v,int rem){

        if(rem==0) return 1;

        if(i >= n) return 0;
        
        int prev = i-1>=0 ? v[i-1] : 0;
        int next = i+1<n ? v[i+1] : 0;

        if(next == 0 and prev == 0 and v[i] == 0)
        {
            v[i] = 1;
            return solve(i+2,n,v,rem-1);
        }

        return solve(i+1,n,v,rem);
    }
    
    bool canPlaceFlowers(vector<int>& v, int n) 
    {
        return solve(0,v.size(),v,n);
    }
};
