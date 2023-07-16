// https://leetcode.com/problems/furthest-building-you-can-reach

// DP but MLE
class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
    
        vector<vector<vector<int>>> dp(v.size()+1,vector<vector<int>>(b+1,vector<int>(l+1,-1)));
        
        return recur(v,b,l,0,dp);
    }
    int recur(vector<int>& v, int b, int l, int i, vector<vector<vector<int>>> &dp) {
    
        if(i+1==v.size()) return i;

        if(v[i+1]>v[i] and l==0 and b<v[i+1]-v[i]) return i;

        if(dp[i][b][l]!=-1) return dp[i][b][l];

        if(v[i+1]>v[i])
        {
            
            int ladAns=-1, brickAns=-1;
            if(l>0) ladAns=recur(v,b,l-1,i+1,dp);
            if(b>=v[i+1]-v[i]) brickAns=recur(v,b-(v[i+1]-v[i]),l,i+1,dp);

            return dp[i][b][l]=max(ladAns, brickAns);
        }
        
        return dp[i][b][l]=recur(v,b,l,i+1,dp);
    }
};

// Priority queue

class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=1;i<v.size();i++)
        {
            // we push first without checking bricks/ladders so we can get the min diff at top to use min bricks
            if(v[i]>v[i-1]) pq.push(v[i]-v[i-1]); 

            if(pq.size()>l) // when all ladders used 
            {
                if(b<pq.top()) return i-1; // bricks insufficient

                b-=pq.top();
                pq.pop();
            }
        }

        return v.size()-1;
    }
};
