// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves

class Solution {
public:
    int maximumTop(vector<int>& v, int k) {

        int n=v.size();
        if(n==1 and k%2==1) return -1;
        if(n==1 and k%2==0) return v[0];
        if(k==0 or k==1) return v[k];

        int maxi=0,i=0;

        for(;i<k-1;i++)
        {
            if(i==n) break;
            maxi=max(v[i],maxi);
        }

        // k-1 turns are over but arr is left
        if(i<v.size()-1)
        {
            i++;
            if(v[i]>maxi) return v[i];
        }

        return maxi;
    }
};

