/*

https://leetcode.com/problems/container-with-most-water

*/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n(h.size()),ans(0),i(0),j(n-1);

        while(i<j)
        {
            if(h[i]<=h[j])
            {
                ans=max(ans,(j-i)*h[i]);
                i++;
            }
            else
            {
                ans=max(ans,(j-i)*h[j]);
                j--;
            }
        }

        return ans;
    }
};
