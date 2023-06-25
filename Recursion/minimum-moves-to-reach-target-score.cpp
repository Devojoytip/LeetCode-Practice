// https://leetcode.com/problems/minimum-moves-to-reach-target-score

class Solution {
public:
    int sol(long long curr, int d) {

        if(curr==1) return 0;
      
        if(d==0) return curr-1;

        if(d>0 and curr%2==0) return 1+sol(curr/2,d-1); 

        return 1+sol(curr-1,d); 
    }

    int minMoves(int t, int d) {
        long long curr=t;
        return sol(t,d);
    }
};
