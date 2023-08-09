// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& v) {
        
        int cnt=0, curr=-1;

        for(auto it: v)
        {
            if(cnt==0)
            {
                cnt++;
                curr=it;
            }
            else
            {
                if(it!=curr) cnt--;
                else cnt++;
            }
        }

        cnt=0;
        for(auto it: v)
        {
            if(it==curr) cnt++;
        }

        return (cnt>v.size()/2) ? curr : -1;
    }
};
