// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    int maxDistToClosest(vector<int>& v) {

        int maxi=0,last0cc=-1,n=v.size();

        for(int i=0;i<n;i++)
        {
            if(v[i]==1)
            {
                if(last0cc==-1) maxi=max(maxi,i); // i is 1st chair found to be occupied
                
                else maxi=max(maxi,(i-last0cc)/2);
                
                last0cc=i;
            }
        }

        if(v[n-1]==0) maxi=max(maxi,n-1-last0cc);

        return maxi;
    }
};
