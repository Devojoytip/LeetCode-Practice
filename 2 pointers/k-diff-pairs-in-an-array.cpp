// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& v, int k) {

        int n=v.size();

        if(n==1) return 0;

        sort(v.begin(),v.end());

        int i=0,j=i+1,ans=0;

        while(j<n and j>i and i<n)
        {
            int diff=abs(v[j]-v[i]);
            if(diff<k) 
            {
                while(j+1<n and v[j+1]==v[j]) j++;
                j++;
            }
            else if(diff>k) 
            {
                while(i+1<n and v[i+1]==v[i]) i++;
                i++;
            }
            else
            {
                ans++;
                while(j+1<n and v[j+1]==v[j]) j++;
                j++;
                while(i+1<n and v[i+1]==v[i]) i++;
                i++;
            }
            if(i==j) j++;
        }

        return ans;
    }
};
