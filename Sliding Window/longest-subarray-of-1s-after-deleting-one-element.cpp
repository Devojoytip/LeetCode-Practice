// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& v) {
        
        int i = 0;
        int zeros = 0;
        int ans = 0;
        int n = v.size();

        for (int j = 0; j < n; j++) {
            
            if (v[j] == 0) zeros++;
            
            while (zeros > 1) 
            {
                if (v[i] == 0) zeros--;
                i++;
            }

            ans = max(ans, j - i );
        }
        
        return (ans == n) ? ans - 1 : ans;
    }
};
