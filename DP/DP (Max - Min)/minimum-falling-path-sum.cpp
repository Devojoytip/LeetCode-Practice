/*

https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    long long int recur(vector<vector<int>>& v,int row,int col) {

        if(row>=v.size() or col>=v[0].size() or col<0) return INT_MAX;

        return v[row][col]+min({recur(v,row+1,col-1),recur(v,row+1,col),recur(v,row+1,col+1)});
    }

    int minFallingPathSum(vector<vector<int>>& v) {

        long long int ans(1e9);

        for(int i=0;i<v[0].size();i++) ans=min(ans,recur(v,0,i));

        return (int)ans;
    }
};

this code will not work as it will add INT_MAX at the end of every call 

*/

class Solution {
    
    vector<vector<int>> dp;

    int dfs(int row, int col, vector<vector<int>>& matrix){
        
        if(row == matrix.size()-1) return matrix[row][col];
        
        if(dp[row][col] != -1) return dp[row][col];

        int ans = dfs(row+1, col, matrix);

        if(col > 0) ans = min(ans, dfs(row+1, col-1, matrix));
        if(col < matrix[0].size()-1) ans = min(ans, dfs(row+1, col+1, matrix));

        dp[row][col] = ans + matrix[row][col];
        return dp[row][col];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;

        int n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        for(int i = 0; i<m; i++) minSum = min(minSum, dfs(0, i, matrix));

        return minSum;
    }
};
