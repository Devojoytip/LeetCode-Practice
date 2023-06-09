// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char t) {
        char ans='\0';

        int s=0,e=v.size()-1;

        while(s<=e)
        {
            int mid=s+(e-s)/2;

            if(v[mid]<=t) s=mid+1;

            else
            {
                ans=v[mid];
                e=mid-1;
            }
        }

        return (ans=='\0') ? v[0] : ans;
    }
};
