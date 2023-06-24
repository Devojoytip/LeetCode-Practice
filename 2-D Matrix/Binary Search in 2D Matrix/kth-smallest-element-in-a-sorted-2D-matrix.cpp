// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

/*

Say X is the Kth smallest number in the matrix.
Then there should be exactly (k-1) elements in matrix <= X.
Count in each row for such elements.
Binary Search X. The lowest possible number is the first element of matrix and highest possible number is last element of matrix.

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        int n=v.size();
        int s=v[0][0], e=v[n-1][n-1], cnt=0, ans;

        while(s<=e)
        {
            int mid=s+(e-s)/2;
            cnt=0;

            for(int i=0;i<n;i++)
            {
                cnt+=upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
            }

            if(cnt>=k)
            {
                ans=mid;
                e=mid-1;
            }

            else s=mid+1;
        }

        return ans;
    }
};
