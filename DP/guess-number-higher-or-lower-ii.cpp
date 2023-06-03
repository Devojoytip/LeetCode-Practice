/* 

iterate over 1 to n ie keep guessing each number in the range (s,e)
take max of whether the guessed no is greater or smaller than num
choose the min ans for the guessed num as we are told to find min cost
we stop when we find that start and end are equal ie start=end=choosen num

*/

class Solution {
public:
    int recur(vector<vector<int>> &dp,int s,int e) {

        if(s>e) return INT_MIN;

        if(s==e) return 0;

        if(dp[s][e]!=-1) return dp[s][e];

        int ans=INT_MAX;

        for(int i=s;i<=e;i++)
        {
            ans=min(ans,i+max(recur(dp,i+1,e),recur(dp,s,i-1)));
        }

        return dp[s][e]=ans;

    }

    int getMoneyAmount(int n) {

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return recur(dp,1,n);
    }
};
