/*

https://leetcode.com/problems/rotate-image/

Observation:

after rotation the ith row becomes ith col in reverse order
thus take transpose of v
reverse every row

*/

class Solution {
public:
    void transpose(vector<vector<int>>& v) {
        int n=v.size();
      
        // O(N/2 * N/2)
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(v[i][j],v[j][i]);
            }
        }
        
    }
  
    void rotate(vector<vector<int>>& v) {
        
        transpose(v);

        // O(N * N/2)
        for(auto &row: v) reverse(row.begin(),row.end());
    }
};
