/*

https://leetcode.com/problems/first-missing-positive
Same as missing nums,

Change:
Ignore -ve nos and nos greater than n

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        
        int mini(INT_MAX),n(v.size());

        for(int i=0;i<n;i++)
        {
            if(v[i]<=0) v[i]=n+1;
        }

        for(int i=0;i<n;i++)
        {
            int num=abs(v[i]);
            if(num>n) continue;
            else 
            {
                if(v[abs(num-1)] > 0) v[abs(num-1)]*=-1;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(v[i]>0) return i+1;
        }

        return n+1;
    }
};
